////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED DO NOT EDIT. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
////////////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <string>

#include "Entities/Platformer/NpcBase.h"

class Ysara : public NpcBase
{
public:
	static Ysara* deserialize(cocos2d::ValueMap* initProperties);

	static const std::string MapKeyYsara;

private:
	Ysara(cocos2d::ValueMap* initProperties);
	~Ysara();
};