#include "HexusOpponentBrine.h"

const std::string HexusOpponentBrine::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_BRINE";
HexusOpponentBrine* HexusOpponentBrine::instance = nullptr;

HexusOpponentBrine* HexusOpponentBrine::getInstance()
{
	if (HexusOpponentBrine::instance == nullptr)
	{
		HexusOpponentBrine::instance = new HexusOpponentBrine();
	}

	return HexusOpponentBrine::instance;
}

HexusOpponentBrine::HexusOpponentBrine() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Volcano_Npcs_Brine_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameVolcano,
	1.0f,
	Vec2(-48.0f, -64.0f),
	Vec2(-16.0f, -32.0f),
	HexusOpponentBrine::OpponentSaveKey,
	HexusOpponentData::Difficulty::Stupid,
	Card::CardStyle::Earth,
	{
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal4),
		CardList::getInstance()->cardListByName->at(CardKeys::LogicalAnd),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex4),
	},
	HexusOpponentData::generateDeck(25, 0, 11, 0.33f, 0.33f,
		{
			CardList::getInstance()->cardListByName->at(CardKeys::Addition),
			CardList::getInstance()->cardListByName->at(CardKeys::LogicalAnd),
			CardList::getInstance()->cardListByName->at(CardKeys::LogicalOr),
			CardList::getInstance()->cardListByName->at(CardKeys::LogicalXor),
			CardList::getInstance()->cardListByName->at(CardKeys::ShiftLeft),
			CardList::getInstance()->cardListByName->at(CardKeys::ShiftRight),
		})
	)
{
}

HexusOpponentBrine::~HexusOpponentBrine()
{
}
