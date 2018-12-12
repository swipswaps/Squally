#include "Gargoyle.h"

const std::string Gargoyle::MapKeyEnemyGargoyle = "gargoyle";

Gargoyle* Gargoyle::deserialize(ValueMap* initProperties)
{
	Gargoyle* instance = new Gargoyle(initProperties);

	instance->autorelease();

	return instance;
}

Gargoyle::Gargoyle(ValueMap* initProperties) : PlatformerEnemy(initProperties,
	EntityResources::Environment_Obelisk_Enemies_Gargoyle_Animations,
	PlatformerCollisionType::Enemy,
	Size(256.0f, 256.0f),
	1.0f,
	Vec2(-32.0f, -24.0f))
{
}

Gargoyle::~Gargoyle()
{
}
