#pragma once

#include "Scenes/Platformer/Inventory/Items/Crafting/Crafting.h"

class LocalizedString;

class VoidCrystal : public Crafting
{
public:
	static VoidCrystal* create();

	Item* clone() override;
	std::string getItemName() override;
	LocalizedString* getString() override;
	std::string getIconResource() override;
	std::string getSerializationKey() override;

	static const std::string SaveKey;

protected:
	VoidCrystal();
	virtual ~VoidCrystal();

private:
	typedef Crafting super;
};
