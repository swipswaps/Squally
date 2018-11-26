#pragma once
#include "cocos2d.h"

#include "Scenes/Hexus/Opponents/HexusOpponentData.h"
#include "Scenes/Hexus/StateOverride.h"

using namespace cocos2d;

class HexusOpponentTutorialD : public HexusOpponentData
{
public:
	static HexusOpponentTutorialD* getInstance();

private:
	HexusOpponentTutorialD();
	~HexusOpponentTutorialD();

	static const std::string OpponentSaveKey;
	static HexusOpponentTutorialD* instance;
};
