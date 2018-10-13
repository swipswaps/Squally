#pragma once
#include "cocos2d.h"

#include "Resources.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"

using namespace cocos2d;

class HexusOpponentBodom : public HexusOpponentData
{
public:
	static HexusOpponentBodom* getInstance();

private:
	HexusOpponentBodom();
	~HexusOpponentBodom();

	static const std::string StringKeyOpponentName;
	static HexusOpponentBodom* instance;
};
