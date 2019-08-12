#include "NpcCollisionBehavior.h"

#include "Engine/Animations/SmartAnimationNode.h"
#include "Engine/Physics/CollisionObject.h"
#include "Engine/Physics/EngineCollisionTypes.h"
#include "Entities/Platformer/NpcBase.h"
#include "Scenes/Platformer/AttachedBehavior/Entities/Collision/EntityMovementCollisionBehavior.h"
#include "Scenes/Platformer/Level/Physics/PlatformerCollisionType.h"

#include "Resources/EntityResources.h"

using namespace cocos2d;

const std::string NpcCollisionBehavior::MapKeyAttachedBehavior = "npc-collisions";

NpcCollisionBehavior* NpcCollisionBehavior::create(GameObject* owner, std::string attachedBehaviorArgs)
{
	NpcCollisionBehavior* instance = new NpcCollisionBehavior(owner, attachedBehaviorArgs);

	instance->autorelease();

	return instance;
}

NpcCollisionBehavior::NpcCollisionBehavior(GameObject* owner, std::string attachedBehaviorArgs) : super(owner, attachedBehaviorArgs)
{
	this->npc = static_cast<NpcBase*>(owner);

	if (this->npc == nullptr)
	{
		this->invalidate();
	}
}

NpcCollisionBehavior::~NpcCollisionBehavior()
{
}

void NpcCollisionBehavior::onLoad()
{
	EntityMovementCollisionBehavior* movementBehavior = this->npc->getAttachedBehavior<EntityMovementCollisionBehavior>();

	if (movementBehavior != nullptr)
	{
		movementBehavior->movementCollision->whenCollidesWith({ (int)PlatformerCollisionType::PlayerWeapon }, [=](CollisionObject::CollisionData collisionData)
		{	
			return CollisionObject::CollisionResult::CollideWithPhysics;
		});
	}
}