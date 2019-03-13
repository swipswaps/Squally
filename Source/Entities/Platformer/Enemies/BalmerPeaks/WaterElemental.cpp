//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED. ONLY EDIT NON-GENERATED SECTIONS. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "WaterElemental.h"

#include "cocos/math/CCGeometry.h"

#include "Scenes/Hexus/Card.h"
#include "Scenes/Hexus/CardData/CardData.h"
#include "Scenes/Hexus/CardData/CardKeys.h"
#include "Scenes/Hexus/CardData/CardList.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"

#include "Resources/EntityResources.h"
#include "Resources/UIResources.h"

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////A////A////A////A////A////A////A////A////A////A/

////B////B////B////B////B////B////B////B////B////B/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////

using namespace cocos2d;

const std::string WaterElemental::MapKeyWaterElemental = "water-elemental";
HexusOpponentData* WaterElemental::HexusOpponentDataInstance = nullptr;
const std::string WaterElemental::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_WATER_ELEMENTAL";

WaterElemental* WaterElemental::deserialize(ValueMap& initProperties)
{
	WaterElemental* instance = new WaterElemental(initProperties);

	instance->autorelease();

	return instance;
}

WaterElemental::WaterElemental(ValueMap& initProperties) : PlatformerEnemy(initProperties,
	EntityResources::Enemies_BalmerPeaks_WaterElemental_Animations,
	EntityResources::Enemies_BalmerPeaks_WaterElemental_Emblem,
	PlatformerCollisionType::Enemy,
	Size(820.0f, 1480.0f),
	0.20f,
	Vec2(0.0f, 0.0f),
	10,
	10)
{
	this->hexusOpponentData = WaterElemental::getHexusOpponentData();

	///////////////////////////////////////////////////
	// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
	////Y////Y////Y////Y////Y////Y////Y////Y////Y////Y/

	////Z////Z////Z////Z////Z////Z////Z////Z////Z////Z/
	// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
	///////////////////////////////////////////////////
}

WaterElemental::~WaterElemental()
{
}

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////X////X////X////X////X////X////X////X////X////X/

////O////O////O////O////O////O////O////O////O////O/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////

Vec2 WaterElemental::getAvatarFrameOffset()
{
	return Vec2(-32.0f, -112.0f);
}

HexusOpponentData* WaterElemental::getHexusOpponentData()
{
	if (WaterElemental::HexusOpponentDataInstance == nullptr)
	{
		WaterElemental::HexusOpponentDataInstance = new HexusOpponentData(
			EntityResources::Enemies_BalmerPeaks_WaterElemental_Animations,
			UIResources::Menus_Hexus_HexusFrameBalmerPeaks,
			0.20f,
			Vec2(0.0f, 0.0f),
			Vec2(-48.0f, -144.0f),
			Vec2(-32.0f, -112.0f),
			WaterElemental::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Water,
			1.000f,
			HexusOpponentData::generateDeck(25, 1.000f,
			{

			}),
			nullptr
		);
	}

	return WaterElemental::HexusOpponentDataInstance;
}