#include "HexusOpponentAbomination.h"

const std::string HexusOpponentAbomination::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_ABOMINATION";
HexusOpponentAbomination* HexusOpponentAbomination::instance = nullptr;

HexusOpponentAbomination* HexusOpponentAbomination::getInstance()
{
	if (HexusOpponentAbomination::instance == nullptr)
	{
		HexusOpponentAbomination::instance = new HexusOpponentAbomination();
	}

	return HexusOpponentAbomination::instance;
}

HexusOpponentAbomination::HexusOpponentAbomination() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Obelisk_Enemies_Abomination_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameObelisk,
	0.7f,
	Vec2(-48.0f, -64.0f),
	Vec2(-48.0f, -48.0f),
	HexusOpponentAbomination::OpponentSaveKey,
	HexusOpponentData::Difficulty::Stupid,
	Card::CardStyle::Earth,
	{
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal4),
		CardList::getInstance()->cardListByName->at(CardKeys::LogicalAnd),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex4),
	},
	HexusOpponentData::generateDeck(25, 0.815f,
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

HexusOpponentAbomination::~HexusOpponentAbomination()
{
}
