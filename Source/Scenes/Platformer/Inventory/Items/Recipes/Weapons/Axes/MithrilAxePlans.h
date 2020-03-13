#pragma once

#include "Scenes/Platformer/Inventory/Items/Recipes/Weapons/Axes/AxeRecipe.h"

class MithrilAxePlans : public AxeRecipe
{
public:
	static MithrilAxePlans* create();

	Item* craft() override;
	Item* clone() override;
	std::string getItemName() override;
	LocalizedString* getString() override;
	std::string getIconResource() override;
	std::string getCraftedItemIconResource() override;
	std::string getSerializationKey() override;

	static const std::string SaveKeyMithrilAxePlans;

protected:
	MithrilAxePlans();
	virtual ~MithrilAxePlans();
	
	std::map<Item*, int> getReagentsInternal() override;

private:
	typedef AxeRecipe super;
};