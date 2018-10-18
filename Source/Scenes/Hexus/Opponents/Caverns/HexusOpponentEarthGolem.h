#pragma once
#include "cocos2d.h"

#include "Resources.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"

using namespace cocos2d;

class HexusOpponentEarthGolem : public HexusOpponentData
{
public:
	static HexusOpponentEarthGolem* getInstance();

private:
	HexusOpponentEarthGolem();
	~HexusOpponentEarthGolem();

	static const std::string OpponentSaveKey;
	static HexusOpponentEarthGolem* instance;
};