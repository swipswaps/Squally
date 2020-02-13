#pragma once

#include "Scenes/Platformer/AttachedBehavior/Entities/Collision/EntityCollisionBehaviorBase.h"

class CollisionObject;
class PlatformerEntity;

class EnemyCollisionBehavior : public EntityCollisionBehaviorBase
{
public:
	static EnemyCollisionBehavior* create(GameObject* owner);

	CollisionObject* entityCollision;

	static const std::string MapKeyAttachedBehavior;

protected:
	EnemyCollisionBehavior(GameObject* owner);
	virtual ~EnemyCollisionBehavior();

	void onLoad() override;
	void onEntityCollisionCreated() override;

private:
	typedef EntityCollisionBehaviorBase super;
};
