#pragma once
#include "cocos2d.h"

#include "Scenes/Hexus/Opponents/HexusOpponentData.h"

using namespace cocos2d;

class HexusOpponentYsara : public HexusOpponentData
{
public:
	static HexusOpponentYsara* getInstance();

private:
	HexusOpponentYsara();
	~HexusOpponentYsara();

	static const std::string OpponentSaveKey;
	static HexusOpponentYsara* instance;
};
