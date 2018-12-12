#include "FrostFiend.h"

const std::string FrostFiend::MapKeyEnemyFrostFiend = "frost_fiend";

FrostFiend* FrostFiend::deserialize(ValueMap* initProperties)
{
	FrostFiend* instance = new FrostFiend(initProperties);

	instance->autorelease();

	return instance;
}

FrostFiend::FrostFiend(ValueMap* initProperties) : PlatformerEnemy(initProperties,
	EntityResources::Environment_Snow_Enemies_FrostFiend_Animations,
	PlatformerCollisionType::Enemy,
	Size(212.0f, 296.0f),
	0.7f,
	Vec2(0.0f, 0.0f))
{
}

FrostFiend::~FrostFiend()
{
}
