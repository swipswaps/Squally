#pragma once
#include "cocos2d.h"
#include "Resources.h"
#include "Entities/Enemy.h"

using namespace cocos2d;

class DemonArcher : public Enemy
{
public:
	static DemonArcher * create();

private:
	DemonArcher();
	~DemonArcher();
};