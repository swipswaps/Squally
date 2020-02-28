#pragma once

#include "Scenes/Platformer/Inventory/Items/Equipment/Gear/Hats/Hat.h"

class GunnersHat : public Hat
{
public:
	static GunnersHat* create();

	Item* clone() override;
	std::string getItemName() override;
	LocalizedString* getString() override;
	std::string getIconResource() override;
	std::string getSerializationKey() override;
	cocos2d::Vec2 getDisplayOffset() override;

	static const std::string SaveKeyGunnersHat;

protected:
	GunnersHat();
	virtual ~GunnersHat();

private:
	typedef Hat super;
};
