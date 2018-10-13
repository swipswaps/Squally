#pragma once
#include "cocos2d.h"

#include "Entities/Platformer/Npcs/NpcBase.h"
#include "Resources.h"

using namespace cocos2d;

class Magnus : public NpcBase
{
public:
	static Magnus * deserialize(ValueMap* initProperties);

	static const std::string MapKeyNpcMagnus;

private:
	Magnus(ValueMap* initProperties);
	~Magnus();
};
