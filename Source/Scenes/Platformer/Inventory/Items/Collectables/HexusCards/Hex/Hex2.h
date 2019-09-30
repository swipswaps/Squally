#pragma once

#include "Scenes/Platformer/Inventory/Items/Collectables/HexusCards/HexusCard.h"

class LocalizedString;

class Hex2 : public HexusCard
{
public:
	static Hex2* create();

	Item* clone() override;
	std::string getItemName() override;
	LocalizedString* getString() override;
	std::string getIconResource() override;
	std::string getSerializationKey() override;

	static const std::string SaveKeyHex2;

protected:
	Hex2();
	~Hex2();

private:
	typedef HexusCard super;
};