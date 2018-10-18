#include "HexusOpponentGarrick.h"

const std::string HexusOpponentGarrick::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_GARRICK";
HexusOpponentGarrick* HexusOpponentGarrick::instance = nullptr;

HexusOpponentGarrick* HexusOpponentGarrick::getInstance()
{
	if (HexusOpponentGarrick::instance == nullptr)
	{
		HexusOpponentGarrick::instance = new HexusOpponentGarrick();
	}

	return HexusOpponentGarrick::instance;
}

HexusOpponentGarrick::HexusOpponentGarrick() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Obelisk_Npcs_Garrick_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameObelisk,
	0.85f,
	Vec2(-48.0f, -80.0f),
	Vec2(-16.0f, -48.0f),
	HexusOpponentGarrick::OpponentSaveKey,
	HexusOpponentData::Difficulty::Stupid,
	Card::CardStyle::Earth,
	{
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal4),
		CardList::getInstance()->cardListByName->at(CardKeys::LogicalAnd),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex4),
	},
	HexusOpponentData::generateDeck(25, 0.81f,
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

HexusOpponentGarrick::~HexusOpponentGarrick()
{
}