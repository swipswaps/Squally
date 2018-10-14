#pragma once
#include "cocos2d.h"

#include "Resources.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"

using namespace cocos2d;

class HexusOpponentLavaGolem : public HexusOpponentData
{
public:
	static HexusOpponentLavaGolem* getInstance();

private:
	HexusOpponentLavaGolem();
	~HexusOpponentLavaGolem();

	static const std::string OpponentSaveKey;
	static HexusOpponentLavaGolem* instance;
};
