#include "HexusOpponentEvilEye.h"

const std::string HexusOpponentEvilEye::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_EVIL_EYE";
HexusOpponentEvilEye* HexusOpponentEvilEye::instance = nullptr;

HexusOpponentEvilEye* HexusOpponentEvilEye::getInstance()
{
	if (HexusOpponentEvilEye::instance == nullptr)
	{
		HexusOpponentEvilEye::instance = new HexusOpponentEvilEye();
	}

	return HexusOpponentEvilEye::instance;
}

HexusOpponentEvilEye::HexusOpponentEvilEye() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Mech_Enemies_EvilEye_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameMech,
	0.7f,
	Vec2(-48.0f, -112.0f),
	Vec2(-16.0f, -144.0f),
	HexusOpponentEvilEye::OpponentSaveKey,
	HexusOpponentData::Difficulty::Stupid,
	Card::CardStyle::Earth,
	{
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal4),
		CardList::getInstance()->cardListByName->at(CardKeys::LogicalAnd),
		CardList::getInstance()->cardListByName->at(CardKeys::Hex4),
	},
	HexusOpponentData::generateDeck(25, 0, 15, 0.33f, 0.33f,
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

HexusOpponentEvilEye::~HexusOpponentEvilEye()
{
}
