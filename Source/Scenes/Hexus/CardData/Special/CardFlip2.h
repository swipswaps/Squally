#pragma once

#include "cocos2d.h"

#include "Resources.h"
#include "Scenes/Hexus/CardData/CardData.h"

using namespace cocos2d;

class CardFlip2 : public CardData
{
public:
	CardFlip2();
	~CardFlip2();

private:
	static const std::string StringKeyCardName;
};