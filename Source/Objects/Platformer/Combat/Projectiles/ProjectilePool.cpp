#include "ProjectilePool.h"

#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionEase.h"
#include "cocos/2d/CCSprite.h"
#include "cocos/base/CCValue.h"

#include "Engine/Utils/GameUtils.h"
#include "Engine/Utils/MathUtils.h"
#include "Objects/Platformer/Combat/Projectiles/Projectile.h"

#include "Resources/ObjectResources.h"

using namespace cocos2d;

ProjectilePool* ProjectilePool::create(int capacity, std::function<Projectile*()> projectileFactory)
{
	ProjectilePool* instance = new ProjectilePool(capacity, projectileFactory);

	instance->autorelease();

	return instance;
}

ProjectilePool::ProjectilePool(int capacity, std::function<Projectile*()> projectileFactory) : super()
{
	this->projectiles = std::vector<Projectile*>();
	this->dartIndex = 0;

	if (projectileFactory != nullptr)
	{
		for (int index = 0; index < capacity; index++)
		{
			this->projectiles.push_back(projectileFactory());
		}
	}

	for (auto it = this->projectiles.begin(); it != this->projectiles.end(); it++)
	{
		this->addChild(*it);
	}
}

ProjectilePool::~ProjectilePool()
{
}

Projectile* ProjectilePool::getNextProjectile()
{
	if (this->projectiles.size() <= 0)
	{
		return nullptr;
	}

	this->dartIndex = MathUtils::wrappingNormalize(this->dartIndex + 1, 0, this->projectiles.size() - 1);

	return this->projectiles[dartIndex];
}
