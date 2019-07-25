#include "LiquidTop.h"

#include "cocos/2d/CCLayer.h"
#include "cocos/base/CCDirector.h"
#include "cocos/renderer/CCCustomCommand.h"
#include "cocos/renderer/CCGLProgramCache.h"
#include "cocos/renderer/ccGLStateCache.h"
#include "cocos/renderer/CCRenderer.h"

#include "Engine/Utils/MathUtils.h"

using namespace cocos2d;

const int LiquidTop::ColumnsPer128px = 16;

LiquidTop* LiquidTop::create(Size surfaceSize, Color4B surfaceColor, Color4B bodyColor, float tension, float dampening, float spread)
{
    LiquidTop* instance = new LiquidTop(surfaceSize, surfaceColor, bodyColor, tension, dampening, spread);

    instance->autorelease();

    return instance;
}

LiquidTop::LiquidTop(Size surfaceSize, Color4B surfaceColor, Color4B bodyColor, float tension, float dampening, float spread)
{
    this->surfaceSize = surfaceSize;
    this->vertexArray = std::vector<Vertex>();
    this->leftDeltas = std::vector<float>();
    this->rightDeltas = std::vector<float>();
    this->columns = std::vector<ColumnData>();
    this->colorArray = std::vector<cocos2d::Color4B>();
    this->customCommand = new CustomCommand();
    this->tension = tension;
    this->dampening = dampening;
    this->spread = spread;

    int columnCount = int((this->surfaceSize.width / 128.0f) * float(LiquidTop::ColumnsPer128px));

    for (int index = 0; index < columnCount; index++)
    {
        ColumnData column = ColumnData(this->surfaceSize.height, this->surfaceSize.height, 0);

        this->colorArray.push_back(surfaceColor);
        this->colorArray.push_back(bodyColor);
        this->vertexArray.push_back(Vertex());
        this->vertexArray.push_back(Vertex());
        this->leftDeltas.push_back(0.0f);
        this->rightDeltas.push_back(0.0f);
        this->columns.push_back(column);
    }
    
    this->setGLProgram(GLProgramCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_COLOR));
}

LiquidTop::~LiquidTop()
{
    delete(this->customCommand);
}

void LiquidTop::onEnter()
{
    super::onEnter();

    this->scheduleUpdate();
}

void LiquidTop::update(float dt)
{
    super::update(dt);

    for (auto it = this->columns.begin(); it != this->columns.end(); it++)
    {
        (*it).update(this->dampening, this->tension);
    }

    for (int j = 0; j < 8; j++)
    {
        for (int i = 0; i < this->columns.size(); i++)
        {
            if (i > 0)
            {
                leftDeltas[i] = this->spread * (columns[i].height - columns[i-1].height);
                (columns[i - 1]).speed += leftDeltas[i];
            }
            if (i < this->columns.size() - 1)
            {
                rightDeltas[i] = this->spread * (columns[i].height - columns[i+1].height);
                (columns[i + 1]).speed += rightDeltas[i];
            }
        }

        for (int i = 0; i < this->columns.size(); i++)
        {
            if (i > 0)
            {
                (columns[i - 1]).height += leftDeltas[i];
            }
            if (i < this->columns.size() - 1)
            {
                (columns[i + 1]).height += rightDeltas[i];
            }
        }
    }
}

void LiquidTop::splash(float x, float speed)
{
    int index = int((x / this->surfaceSize.width) * float(this->columns.size()));

    index = MathUtils::clamp(index, 0, this->columns.size() - 1);

    columns[index].speed = speed;
}

void LiquidTop::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags)
{
    this->customCommand->init(_globalZOrder);
    this->customCommand->func = CC_CALLBACK_0(LiquidTop::onCustomDraw, this, transform);

    renderer->addCommand(customCommand);
}

void LiquidTop::onCustomDraw(const Mat4 &transform)
{
    // update the matrix
    Director::getInstance()->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
    Director::getInstance()->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, transform);

    for (int index = 0; index < this->columns.size(); index++)
    {
        uint16_t x = (float(index) / float(this->columns.size() - 1)) * this->surfaceSize.width;
        uint16_t y = columns[index].height;
        
        this->vertexArray[2 * index] = Vertex(x, y);
        this->vertexArray[2 * index + 1] = Vertex(x, 0);
    }
    
    // now finally call the low-level opengGL calls to render the GL_TRIANGLE_STRIP in a simple way
    GL::enableVertexAttribs(GL::VERTEX_ATTRIB_FLAG_POSITION | GL::VERTEX_ATTRIB_FLAG_COLOR);
    this->getGLProgram()->use();
    this->getGLProgram()->setUniformsForBuiltins();

    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 2, GL_UNSIGNED_SHORT, GL_FALSE, 0, this->vertexArray.data());
    glEnableVertexAttribArray(GL::VERTEX_ATTRIB_FLAG_POSITION);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_UNSIGNED_BYTE, GL_TRUE, 0, this->colorArray.data());
    glEnableVertexAttribArray(GL::VERTEX_ATTRIB_FLAG_COLOR);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, this->columns.size() * 2);
}
