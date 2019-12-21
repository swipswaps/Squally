#pragma once

#include "Scenes/Platformer/Inventory/Items/Misc/Misc.h"

class EssenceOfLight : public Misc
{
public:
	static EssenceOfLight* create();

	Item* clone() override;
	std::string getItemName() override;
	LocalizedString* getString() override;
	std::string getIconResource() override;
	std::string getSerializationKey() override;

	static const std::string SaveKeyEssenceOfLight;

protected:
	EssenceOfLight();
	~EssenceOfLight();

private:
	typedef Misc super;
};
