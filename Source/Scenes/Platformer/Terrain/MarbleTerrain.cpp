#include "MarbleTerrain.h"

#include "cocos/base/CCValue.h"

#include "Resources/TerrainResources.h"
#include "Resources/TextureResources.h"

using namespace cocos2d;

const std::string MarbleTerrain::MapKeyTerrainType = "marble";

MarbleTerrain* MarbleTerrain::create(ValueMap& properties)
{
	MarbleTerrain* instance = new MarbleTerrain(properties);

	instance->autorelease();

	return instance;
}

MarbleTerrain::MarbleTerrain(ValueMap& properties) : super(
	properties,
	TerrainObject::TerrainData(
		0.5f,
		MarbleTerrain::MapKeyTerrainType,
		TextureResources::MarbleTexture,
		TerrainResources::Marble_Marble,
		TerrainResources::Marble_MarbleTopLeft,
		TerrainResources::Marble_MarbleTopRight,
		TerrainResources::Marble_MarbleBottom,
		TerrainResources::Marble_MarbleBottomLeft,
		TerrainResources::Marble_MarbleBottomRight,
		TerrainResources::Marble_MarbleLeft,
		TerrainResources::Marble_MarbleRight,
		cocos2d::Vec2::ZERO,
		cocos2d::Vec2(-16.0f, 0.0f),
		cocos2d::Vec2(16.0f, 0.0f),
		cocos2d::Vec2::ZERO,
		cocos2d::Vec2::ZERO,
		Color4B(11, 30, 39, 255)))
{
}

MarbleTerrain::~MarbleTerrain()
{
}