#pragma once
#include "cocos2d.h"

#include "Entities/Enemy.h"
#include "Resources.h"

using namespace cocos2d;

class MechGuard : public Enemy
{
public:
	static MechGuard * create();

private:
	MechGuard();
	~MechGuard();
};
