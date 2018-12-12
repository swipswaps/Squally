#include "Aphrodite.h"

const std::string Aphrodite::MapKeyNpcAphrodite = "Aphrodite";

Aphrodite* Aphrodite::deserialize(ValueMap* initProperties)
{
	Aphrodite* instance = new Aphrodite(initProperties);

	instance->autorelease();

	return instance;
}

Aphrodite::Aphrodite(ValueMap* initProperties) : NpcBase(initProperties,
	EntityResources::Environment_Ruins_Npcs_Aphrodite_Animations,
	PlatformerCollisionType::Enemy,
	Size(472.0f, 780.0f),
	0.3f,
	Vec2(-24.0f, -390.0f))
{
}

Aphrodite::~Aphrodite()
{
}
