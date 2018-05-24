#pragma once
#include "cocos2d.h"
#include "Resources.h"
#include "Entities/Enemy.h"

using namespace cocos2d;

class EarthElemental : public Enemy
{
public:
	static EarthElemental * create();

private:
	EarthElemental();
	~EarthElemental();
};