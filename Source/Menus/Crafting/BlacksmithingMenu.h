#pragma once
#include <functional>

#include "Menus/Crafting/CraftingMenuBase.h"

namespace cocos2d
{
	class Sprite;
};

class BlacksmithingMenu : public CraftingMenuBase
{
public:
	static BlacksmithingMenu* create();

protected:
	BlacksmithingMenu();
	virtual ~BlacksmithingMenu();

	void initializePositions() override;

private:
	typedef CraftingMenuBase super;

	cocos2d::Sprite* anvil;
	cocos2d::Sprite* icon;
};
