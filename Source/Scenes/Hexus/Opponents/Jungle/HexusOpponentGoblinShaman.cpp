#include "HexusOpponentGoblinShaman.h"

const std::string HexusOpponentGoblinShaman::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_GOBLIN_SHAMAN";
HexusOpponentGoblinShaman* HexusOpponentGoblinShaman::instance = nullptr;

HexusOpponentGoblinShaman* HexusOpponentGoblinShaman::getInstance()
{
	if (HexusOpponentGoblinShaman::instance == nullptr)
	{
		HexusOpponentGoblinShaman::instance = new HexusOpponentGoblinShaman();
	}

	return HexusOpponentGoblinShaman::instance;
}

HexusOpponentGoblinShaman::HexusOpponentGoblinShaman() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Jungle_Enemies_GoblinShaman_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameForest,
	1.0f,
	Vec2(-48.0f, -64.0f),
	Vec2(-16.0f, -32.0f),
	HexusOpponentGoblinShaman::OpponentSaveKey,
	HexusOpponentData::Difficulty::Stupid,
	Card::CardStyle::Earth,
	{
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal4),
		CardList::getInstance()->cardListByName->at(CardKeys::LogicalAnd),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex4),
	},
	HexusOpponentData::generateDeck(25, 0.115f,
		{
			CardList::getInstance()->cardListByName->at(CardKeys::Binary0),
			CardList::getInstance()->cardListByName->at(CardKeys::Hex0),
			CardList::getInstance()->cardListByName->at(CardKeys::Decimal0),
			CardList::getInstance()->cardListByName->at(CardKeys::Addition),
			CardList::getInstance()->cardListByName->at(CardKeys::Addition),
			CardList::getInstance()->cardListByName->at(CardKeys::ShiftLeft),
			CardList::getInstance()->cardListByName->at(CardKeys::ShiftRight),
		})
	)
{
}

HexusOpponentGoblinShaman::~HexusOpponentGoblinShaman()
{
}
