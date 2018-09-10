#include "Squally.h"

Squally* Squally::squallyInstance = nullptr;
int Squally::health;
const float Squally::squallyScale = 0.13f;

const std::string Squally::KeySquallyProperty = "squally";

Squally* Squally::deserialize(ValueMap* initProperties)
{
	Squally* instance = new Squally(initProperties);

	Squally::squallyInstance = instance;
	instance->autorelease();

	return instance;
}

Squally* Squally::getInstance()
{
	return Squally::squallyInstance;
}

Squally::Squally(ValueMap* initProperties) : PlatformerEntity::PlatformerEntity(initProperties,
	Resources::Entities_Platformer_Squally_Animations,
	PlatformerCollisionMapping::KeyCollisionTypePlayer,
	Size(720.0f, 1600.0f), 
	Squally::squallyScale,
	Vec2(0.0f, 600.0f))
{
	this->actualJumpLaunchVelocity = 1280.0f;
	this->actualGravityAcceleration = 400.0f;
	this->actualMaxFallSpeed = 600.0f;
	this->moveAcceleration = 14000.0f;

	// this->hover = Hover::create(this);

	//this->hover->setContactBeginCallback(CC_CALLBACK_1(Squally::hoverContactBegin, this));
	//this->hover->setContactUpdateCallback(CC_CALLBACK_1(Squally::hoverContactUpdate, this));
	//this->hover->setContactEndCallback(CC_CALLBACK_1(Squally::hoverContactEnd, this));
	//this->addChild(this->hover);

	this->registerHackables();
}

Squally::~Squally()
{
}

void Squally::onEnter()
{
	PlatformerEntity::onEnter();

	this->inputManager = InputManager::getInstance();
}

void Squally::registerHackables()
{
	//HackableData* hackableDataHealth = HackableData::create("Health", &this->health, &typeid(this->health));
	//HackableData* hackableDataPositionX = HackableData::create("X Position", &this->position.x, &typeid(this->position.x));
	//HackableData* hackableDataPositionY = HackableData::create("Y Position", &this->position.y, &typeid(this->position.y));

	//HackableCode* hackableVelocity = HackableCode::create("Take Damage", &this->_displayedColor, 8);
	//HackableCode* hackableVelocityA = HackableCode::create("Set X Velocity", &this->_actionManager, 4);
	//HackableCode* hackableVelocityB = HackableCode::create("Set Y Velocity", &this->_scaleX, 7);

	//this->registerData(hackableDataHealth);
	//this->registerData(hackableDataPositionX);
	//this->registerData(hackableDataPositionY);

	//this->registerCode(hackableVelocity);
	//this->registerCode(hackableVelocityA);
	//this->registerCode(hackableVelocityB);
}

Vec2 Squally::getButtonOffset()
{
	return Vec2(0, 72.0f);
}

void Squally::update(float dt)
{
	PlatformerEntity::update(dt);

	this->movement.x = 0.0f;
	this->movement.y = 0.0f;

	if (this->inputManager->isPressed(EventKeyboard::KeyCode::KEY_LEFT_ARROW) || this->inputManager->isPressed(EventKeyboard::KeyCode::KEY_A))
	{
		this->movement.x -= 1.0f;
		this->setFlippedX(true);
	}

	if (this->inputManager->isPressed(EventKeyboard::KeyCode::KEY_RIGHT_ARROW) || this->inputManager->isPressed(EventKeyboard::KeyCode::KEY_D))
	{
		this->movement.x += 1.0f;
		this->setFlippedX(false);
	}

	if (this->inputManager->isPressed(EventKeyboard::KeyCode::KEY_UP_ARROW) || this->inputManager->isPressed(EventKeyboard::KeyCode::KEY_W) || this->inputManager->isPressed(EventKeyboard::KeyCode::KEY_SPACE))
	{
		this->movement.y += 1.0f;
	}

	if (this->inputManager->isPressed(EventKeyboard::KeyCode::KEY_DOWN_ARROW) || this->inputManager->isPressed(EventKeyboard::KeyCode::KEY_S))
	{
		this->hover->setHeight(16.0f);
	}
}

void Squally::setFlippedX(bool newIsFlipped)
{
	this->isFlipped = newIsFlipped;
}

bool Squally::hoverContactBegin(CollisionData data)
{
	return true;
}

bool Squally::hoverContactUpdate(CollisionData data)
{
	switch (data.other->getCategoryGroup())
	{
	case PlatformerCollisionMapping::CategoryGroupType::G_Solid:
		if (abs(data.normal.y) >= PlatformerEntity::normalJumpThreshold)
		{
			this->isOnGround = true;
		}
		return true;
	case PlatformerCollisionMapping::CategoryGroupType::G_Player:
		return true;
	}

	return true;
}

bool Squally::hoverContactEnd(CollisionData data)
{
	switch (data.other->getCategoryGroup())
	{
	case PlatformerCollisionMapping::CategoryGroupType::G_Solid:
		this->isOnGround = false;
		return true;
	case PlatformerCollisionMapping::CategoryGroupType::G_Player:
		return true;
	}

	return true;
}

bool Squally::contactBegin(CollisionData data)
{
	switch (data.other->getCategoryGroup())
	{
	case PlatformerCollisionMapping::CategoryGroupType::G_Enemy:
	case PlatformerCollisionMapping::CategoryGroupType::G_EnemyFlying:
		PlatformerEnemy * enemy = dynamic_cast<PlatformerEnemy*>(data.other);

		if (enemy != nullptr)
		{
			NavigationEvents::loadFight(this, enemy);
		}

		return false;
	}

	return true;
}

bool Squally::contactUpdate(CollisionData data)
{
	switch (data.other->getCategoryGroup())
	{
	case PlatformerCollisionMapping::CategoryGroupType::G_Solid:
		switch (data.direction)
		{
		case CollisionDirection::Down:
			this->isOnGround = true;
			break;
		}
		return true;
	case PlatformerCollisionMapping::CategoryGroupType::G_Force:
		return true;
	case PlatformerCollisionMapping::CategoryGroupType::G_Enemy:
	case PlatformerCollisionMapping::CategoryGroupType::G_EnemyFlying:
		// TODO: Damage
		return false;
	case PlatformerCollisionMapping::CategoryGroupType::G_SolidNpc:
	case PlatformerCollisionMapping::CategoryGroupType::G_SolidFlyingNpc:
		return false;
	}

	return true;
}

bool Squally::contactEnd(CollisionData data)
{
	switch (data.other->getCategoryGroup())
	{
	case PlatformerCollisionMapping::CategoryGroupType::G_Solid:
		this->isOnGround = false;
		return true;
	case PlatformerCollisionMapping::CategoryGroupType::G_Force:
		return true;
	case PlatformerCollisionMapping::CategoryGroupType::G_Enemy:
	case PlatformerCollisionMapping::CategoryGroupType::G_EnemyFlying:
		return false;
	case PlatformerCollisionMapping::CategoryGroupType::G_SolidNpc:
	case PlatformerCollisionMapping::CategoryGroupType::G_SolidFlyingNpc:
		return false;
	}

	return true;
}

Size Squally::getSize()
{
	return this->size * Squally::squallyScale;
}