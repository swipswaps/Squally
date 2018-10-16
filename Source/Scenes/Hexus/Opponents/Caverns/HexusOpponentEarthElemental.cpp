#include "HexusOpponentEarthElemental.h"

const std::string HexusOpponentEarthElemental::OpponentSaveKey = "HEXUS_OPPONENT_SAVE_KEY_EARTH_ELEMENTAL";
HexusOpponentEarthElemental* HexusOpponentEarthElemental::instance = nullptr;

HexusOpponentEarthElemental* HexusOpponentEarthElemental::getInstance()
{
	if (HexusOpponentEarthElemental::instance == nullptr)
	{
		HexusOpponentEarthElemental::instance = new HexusOpponentEarthElemental();
	}

	return HexusOpponentEarthElemental::instance;
}

HexusOpponentEarthElemental::HexusOpponentEarthElemental() : HexusOpponentData(
	Resources::Entities_Platformer_Environment_Caverns_Enemies_EarthElemental_Animations,
	Resources::Menus_MinigamesMenu_Hexus_HexusFrameCaverns,
	1.0f,
	Vec2(-32.0f, -48.0f),
	Vec2(-32.0f, -64.0f),
	HexusOpponentEarthElemental::OpponentSaveKey,
	HexusOpponentData::Difficulty::Stupid,
	Card::CardStyle::Shadow,
	{
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal3),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal2),
		CardList::getInstance()->cardListByName->at(CardKeys::Decimal1),
	},
	HexusOpponentData::generateDeck(25, 0.435f,
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

HexusOpponentEarthElemental::~HexusOpponentEarthElemental()
{
}
