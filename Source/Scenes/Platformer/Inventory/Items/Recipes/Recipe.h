#pragma once

#include "Engine/Inventory/Item.h"

class Recipe : public Item
{
public:
	virtual Item* craft() = 0;
	std::map<Item*, int> getReagents();
	
	Item* getCraftedItemRef();

protected:
	Recipe(CurrencyInventory* cost);
	virtual ~Recipe();

	virtual std::map<Item*, int> getReagentsInternal() = 0;

private:
	typedef Item super;

	Item* craftedItem;

	cocos2d::Node* reagentsNode;
	std::map<Item*, int> reagentsCache;
};