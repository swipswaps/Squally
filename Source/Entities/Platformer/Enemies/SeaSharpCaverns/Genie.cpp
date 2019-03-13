//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// THIS C++ FILE IS GENERATED. ONLY EDIT NON-GENERATED SECTIONS. RUN GenerateDataFiles.py TO GENERATE THIS FILE //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Genie.h"

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

const std::string Genie::MapKeyGenie = "genie";
HexusOpponentData* Genie::HexusOpponentDataInstance = nullptr;
const std::string Genie::HexusSaveKey = "HEXUS_OPPONENT_SAVE_KEY_GENIE";

Genie* Genie::deserialize(ValueMap& initProperties)
{
	Genie* instance = new Genie(initProperties);

	instance->autorelease();

	return instance;
}

Genie::Genie(ValueMap& initProperties) : PlatformerEnemy(initProperties,
	EntityResources::Enemies_SeaSharpCaverns_Genie_Animations,
	EntityResources::Enemies_SeaSharpCaverns_Genie_Emblem,
	PlatformerCollisionType::Enemy,
	Size(512.0f, 1126.0f),
	0.20f,
	Vec2(0.0f, 0.0f),
	10,
	10)
{
	this->hexusOpponentData = Genie::getHexusOpponentData();

	///////////////////////////////////////////////////
	// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
	////Y////Y////Y////Y////Y////Y////Y////Y////Y////Y/

	////Z////Z////Z////Z////Z////Z////Z////Z////Z////Z/
	// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
	///////////////////////////////////////////////////
}

Genie::~Genie()
{
}

///////////////////////////////////////////////////
// BEGIN: CODE NOT AFFECTED BY GENERATE SCRIPTS: //
////X////X////X////X////X////X////X////X////X////X/

////O////O////O////O////O////O////O////O////O////O/
// END: CODE NOT AFFECTED BY GENERATE SCRIPTS    //
///////////////////////////////////////////////////

Vec2 Genie::getAvatarFrameOffset()
{
	return Vec2(-32.0f, -112.0f);
}

HexusOpponentData* Genie::getHexusOpponentData()
{
	if (Genie::HexusOpponentDataInstance == nullptr)
	{
		Genie::HexusOpponentDataInstance = new HexusOpponentData(
			EntityResources::Enemies_SeaSharpCaverns_Genie_Animations,
			UIResources::Menus_Hexus_HexusFrameSeaSharpCaverns,
			0.20f,
			Vec2(0.0f, 0.0f),
			Vec2(-48.0f, -144.0f),
			Vec2(-32.0f, -112.0f),
			Genie::HexusSaveKey,
			HexusOpponentData::Strategy::Random,
			Card::CardStyle::Earth,
			1.000f,
			HexusOpponentData::generateDeck(25, 1.000f,
			{

			}),
			nullptr
		);
	}

	return Genie::HexusOpponentDataInstance;
}