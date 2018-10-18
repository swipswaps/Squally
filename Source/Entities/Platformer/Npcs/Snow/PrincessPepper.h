#pragma once
#include "cocos2d.h"

#include "Entities/Platformer/Npcs/NpcBase.h"
#include "Resources.h"

using namespace cocos2d;

class PrincessPepper : public NpcBase
{
public:
	static PrincessPepper * deserialize(ValueMap* initProperties);

	static const std::string MapKeyNpcPrincessPepper;

private:
	PrincessPepper(ValueMap* initProperties);
	~PrincessPepper();
};