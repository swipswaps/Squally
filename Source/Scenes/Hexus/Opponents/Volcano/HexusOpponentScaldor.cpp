#include "HexusOpponentScaldor.h"

const std::string HexusOpponentScaldor::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_SCALDOR";
HexusOpponentScaldor* HexusOpponentScaldor::instance = nullptr;

HexusOpponentScaldor* HexusOpponentScaldor::getInstance()
{
	if (HexusOpponentScaldor::instance == nullptr)
	{
		HexusOpponentScaldor::instance = new HexusOpponentScaldor();
	}

	return HexusOpponentScaldor::instance;
}

HexusOpponentScaldor::HexusOpponentScaldor() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Volcano_Npcs_Scaldor_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameVolcano,
	1.0f,
	Vec2(-48.0f, -48.0f),
	Vec2(-16.0f, -24.0f),
	HexusOpponentScaldor::OpponentSaveKey,
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

HexusOpponentScaldor::~HexusOpponentScaldor()
{
}
