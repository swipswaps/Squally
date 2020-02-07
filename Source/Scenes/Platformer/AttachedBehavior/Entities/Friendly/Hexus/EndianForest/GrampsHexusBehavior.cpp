#include "GrampsHexusBehavior.h"

#include "Objects/Platformer/ItemPools/HexusPools/EndianForest/HexusPoolEFGeneric.h"
#include "Scenes/Hexus/CardData/CardKeys.h"
#include "Scenes/Hexus/CardData/CardList.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"
#include "Scenes/Hexus/StateOverride.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Friendly/Hexus/EndianForest/EFHexusConfig.h"

#include "Resources/HexusResources.h"
#include "Resources/SoundResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string GrampsHexusBehavior::MapKeyAttachedBehavior = "gramps-hexus";

GrampsHexusBehavior* GrampsHexusBehavior::create(GameObject* owner)
{
	GrampsHexusBehavior* instance = new GrampsHexusBehavior(owner);

	instance->autorelease();

	return instance;
}

GrampsHexusBehavior::GrampsHexusBehavior(GameObject* owner) : super(owner, SoundResources::Platformer_Entities_Generic_ChatterShort1)
{
}

GrampsHexusBehavior::~GrampsHexusBehavior()
{
}

MinMaxPool* GrampsHexusBehavior::generateReward()
{
	return HexusPoolEFGeneric::create();
}

std::string GrampsHexusBehavior::getWinLossSaveKey()
{
	return GrampsHexusBehavior::MapKeyAttachedBehavior;
}

std::string GrampsHexusBehavior::getBackgroundResource()
{
	return HexusResources::Menus_HexusFrameCastleValgrind;
}

std::vector<CardData*> GrampsHexusBehavior::generateDeck()
{
	const float LocalOrder = 2.0f / EFHexusConfig::MaxEntities;

	return HexusOpponentData::generateDeck(25, LocalOrder * EFHexusConfig::ZoneOrder,
	{
		CardList::getInstance()->cardListByName[CardKeys::Binary0],
		CardList::getInstance()->cardListByName[CardKeys::Decimal0],
		CardList::getInstance()->cardListByName[CardKeys::Hex0],
	});
}

StateOverride* GrampsHexusBehavior::getStateOverride()
{
	return nullptr;
}

std::vector<TutorialBase*> GrampsHexusBehavior::getTutorials()
{
	return { };
}
