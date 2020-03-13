#include "ChieftainsWandPlans.h"

#include "Engine/Inventory/CurrencyInventory.h"
#include "Scenes/Platformer/Inventory/Currencies/IOU.h"
#include "Scenes/Platformer/Inventory/Items/PlatformerItems.h"

#include "Resources/ObjectResources.h"

#include "Strings/Strings.h"

using namespace cocos2d;

const std::string ChieftainsWandPlans::SaveKeyChieftainsWandPlans = "chieftains-wand-plans";

ChieftainsWandPlans* ChieftainsWandPlans::create()
{
	ChieftainsWandPlans* instance = new ChieftainsWandPlans();

	instance->autorelease();

	return instance;
}

ChieftainsWandPlans::ChieftainsWandPlans() : super(CurrencyInventory::create({{ IOU::getIOUIdentifier(), 2 }}))
{
}

ChieftainsWandPlans::~ChieftainsWandPlans()
{
}

Item* ChieftainsWandPlans::craft()
{
	return ChieftainsWand::create();
}

std::map<Item*, int> ChieftainsWandPlans::getReagentsInternal()
{
	return
	{
		{ Wood::create(), 2 },
		{ Iron::create(), 4 },
	};
}

Item* ChieftainsWandPlans::clone()
{
	return ChieftainsWandPlans::create();
}

std::string ChieftainsWandPlans::getItemName()
{
	return ChieftainsWandPlans::SaveKeyChieftainsWandPlans;
}

LocalizedString* ChieftainsWandPlans::getString()
{
	return Strings::Items_Equipment_Weapons_Wands_ChieftainsWand::create();
}

std::string ChieftainsWandPlans::getIconResource()
{
	return ObjectResources::Items_Crafting_SCROLL_1;
}

std::string ChieftainsWandPlans::getCraftedItemIconResource()
{
	return ObjectResources::Items_Equipment_Weapons_Wands_ChieftainsWand;
}

std::string ChieftainsWandPlans::getSerializationKey()
{
	return ChieftainsWandPlans::SaveKeyChieftainsWandPlans;
}