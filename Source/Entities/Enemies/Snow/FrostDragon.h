#pragma once
#include "cocos2d.h"
#include "Resources.h"
#include "Entities/Entity.h"
#include "Objects/Collision/CategoryGroup.h"

using namespace cocos2d;

class FrostDragon : public Entity
{
public:
	static FrostDragon * create();

protected:
	bool contactBegin(CollisionData data) override;
	bool contactUpdate(CollisionData data) override;
	bool contactEnd(CollisionData data) override;

private:
	FrostDragon();
	~FrostDragon();

	void update(float) override;

	Animation* walkAnimation;
	Animation* deathAnimation;

	Sprite* sprite;
};