#pragma once
#include "cocos2d.h"

#include "Resources.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"

using namespace cocos2d;

class HexusOpponentAlder : public HexusOpponentData
{
public:
	static HexusOpponentAlder* getInstance();

private:
	HexusOpponentAlder();
	~HexusOpponentAlder();

	static const std::string OpponentSaveKey;
	static HexusOpponentAlder* instance;
};
