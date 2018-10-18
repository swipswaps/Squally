#pragma once
#include "cocos2d.h"

#include "Resources.h"
#include "Scenes/Hexus/Opponents/HexusOpponentData.h"

using namespace cocos2d;

class HexusOpponentGargoyle : public HexusOpponentData
{
public:
	static HexusOpponentGargoyle* getInstance();

private:
	HexusOpponentGargoyle();
	~HexusOpponentGargoyle();

	static const std::string OpponentSaveKey;
	static HexusOpponentGargoyle* instance;
};