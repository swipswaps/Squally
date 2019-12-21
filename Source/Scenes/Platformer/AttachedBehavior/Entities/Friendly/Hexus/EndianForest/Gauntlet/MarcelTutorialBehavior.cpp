#include "MarcelTutorialBehavior.h"

#include "Engine/Animations/SmartAnimationNode.h"
#include "Entities/Platformer/PlatformerEntity.h"
#include "Objects/Platformer/ItemPools/HexusPools/EndianForest/HexusPoolMarcel.h"
#include "Scenes/Hexus/CardData/CardKeys.h"
#include "Scenes/Hexus/CardData/CardList.h"
#include "Scenes/Hexus/Components/Components.h"
#include "Scenes/Hexus/StateOverride.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Dialogue/EntityDialogueBehavior.h"

#include "Resources/HexusResources.h"
#include "Resources/SoundResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string MarcelTutorialBehavior::WinLossTrackIdentifier = "marcel-tutorial";

MarcelTutorialBehavior* MarcelTutorialBehavior::create(GameObject* owner)
{
	MarcelTutorialBehavior* instance = new MarcelTutorialBehavior(owner);

	instance->autorelease();

	return instance;
}

MarcelTutorialBehavior::MarcelTutorialBehavior(GameObject* owner) : super(owner, SoundResources::Platformer_Entities_Generic_ChatterShort1, Strings::Platformer_Dialogue_Hexus_IAcceptYourChallenge::create())
{
}

MarcelTutorialBehavior::~MarcelTutorialBehavior()
{
}

MinMaxPool* MarcelTutorialBehavior::generateReward()
{
	return HexusPoolMarcel::create();
}

std::string MarcelTutorialBehavior::getWinLossSaveKey()
{
	return MarcelTutorialBehavior::WinLossTrackIdentifier;
}

std::string MarcelTutorialBehavior::getBackgroundResource()
{
	return HexusResources::Menus_HexusFrameCastleValgrind;
}

std::vector<CardData*> MarcelTutorialBehavior::generateDeck()
{
	return HexusOpponentData::generateDeck(18, 0.07f,
	{
		// CardList::getInstance()->cardListByName[CardKeys::Decimal0],
	});
}

StateOverride* MarcelTutorialBehavior::getStateOverride()
{
	return nullptr;
}

std::vector<TutorialBase*> MarcelTutorialBehavior::getTutorials()
{
	return { MarcelTutorialIntroSequence::create(), MarcelTutorialClaimVictory::create() };
}
