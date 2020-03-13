#pragma once

#include "Scenes/Platformer/Inventory/Items/Recipes/Weapons/Axes/AxeRecipe.h"

class SteelAxePlans : public AxeRecipe
{
public:
	static SteelAxePlans* create();

	Item* craft() override;
	Item* clone() override;
	std::string getItemName() override;
	LocalizedString* getString() override;
	std::string getIconResource() override;
	std::string getCraftedItemIconResource() override;
	std::string getSerializationKey() override;

	static const std::string SaveKeySteelAxePlans;

protected:
	SteelAxePlans();
	virtual ~SteelAxePlans();
	
	std::map<Item*, int> getReagentsInternal() override;

private:
	typedef AxeRecipe super;
};