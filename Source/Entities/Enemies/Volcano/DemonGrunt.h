#pragma once
#include "cocos2d.h"
#include "Resources.h"
#include "Entities/Enemy.h"

using namespace cocos2d;

class DemonGrunt : public Enemy
{
public:
	static DemonGrunt * create();

private:
	DemonGrunt();
	~DemonGrunt();
};