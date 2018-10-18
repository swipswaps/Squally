#include "HexusOpponentGriffin.h"

const std::string HexusOpponentGriffin::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_GRIFFIN";
HexusOpponentGriffin* HexusOpponentGriffin::instance = nullptr;

HexusOpponentGriffin* HexusOpponentGriffin::getInstance()
{
	if (HexusOpponentGriffin::instance == nullptr)
	{
		HexusOpponentGriffin::instance = new HexusOpponentGriffin();
	}

	return HexusOpponentGriffin::instance;
}

HexusOpponentGriffin::HexusOpponentGriffin() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Ruins_Npcs_Griffin_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameRuins,
	1.0f,
	Vec2(-48.0f, -64.0f),
	Vec2(-16.0f, -48.0f),
	HexusOpponentGriffin::OpponentSaveKey,
	HexusOpponentData::Difficulty::Stupid,
	Card::CardStyle::Earth,
	{
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal4),
		CardList::getInstance()->cardListByName->at(CardKeys::LogicalAnd),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex4),
	},
	HexusOpponentData::generateDeck(25, 0.27f,
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

HexusOpponentGriffin::~HexusOpponentGriffin()
{
}