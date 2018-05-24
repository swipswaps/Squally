#pragma once
#include "cocos2d.h"
#include "Resources.h"
#include "MiniGames/Hexus/Components/ComponentBase.h"
#include "GUI/Components/MenuSprite.h"
#include "Utils/StrUtils.h"

using namespace cocos2d;

class ControlNeutral : public ComponentBase
{
public:
	static ControlNeutral * create();

protected:
	void onStateChange(GameState* gameState) override;

private:
	ControlNeutral();
	~ControlNeutral();

	void onEnter() override;
	void initializePositions();
	void initializeListeners();
	void initializeCallbacks(GameState* gameState);
	void aiDoSelection(GameState* gameState);
	void selectCard(Card* card);

	GameState* activeGameState;
};