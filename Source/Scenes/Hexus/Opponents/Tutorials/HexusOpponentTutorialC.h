#pragma once
#include "cocos2d.h"

#include "Scenes/Hexus/Opponents/HexusOpponentData.h"
#include "Scenes/Hexus/StateOverride.h"

using namespace cocos2d;

class HexusOpponentTutorialC : public HexusOpponentData
{
public:
	static HexusOpponentTutorialC* getInstance();

private:
	HexusOpponentTutorialC();
	~HexusOpponentTutorialC();

	static const std::string OpponentSaveKey;
	static HexusOpponentTutorialC* instance;
};
