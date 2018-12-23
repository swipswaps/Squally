////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED DO NOT EDIT. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
////////////////////////////////////////////////////////////////////////////////////////////

#include "KingRedsongSlime.h"

#include "Resources/EntityResources.h"

const std::string KingRedsongSlime::MapKeyKingRedsongSlime = "king-redsong-slime";

KingRedsongSlime* KingRedsongSlime::deserialize(cocos2d::ValueMap* initProperties)
{
	KingRedsongSlime* instance = new KingRedsongSlime(initProperties);

	instance->autorelease();

	return instance;
}

KingRedsongSlime::KingRedsongSlime(cocos2d::ValueMap* initProperties) : NpcBase(initProperties,
	EntityResources::Npcs_CastleValgrind_KingRedsongSlime_Animations,
	PlatformerCollisionType::FriendlyNpc,
	cocos2d::Size(112.0f, 160.0f),
	0.9f,
	cocos2d::Vec2(0.0f, 0.0f))
{
}

KingRedsongSlime::~KingRedsongSlime()
{
}

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////X////X////X////X////X////X////X////X////X////X/

////O////O////O////O////O////O////O////O////O////O/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////