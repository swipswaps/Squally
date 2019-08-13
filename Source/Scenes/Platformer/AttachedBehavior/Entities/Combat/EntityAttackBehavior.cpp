#include "EntityAttackBehavior.h"

#include "Engine/Animations/SmartAnimationNode.h"
#include "Engine/Input/ClickableNode.h"
#include "Entities/Platformer/PlatformerEnemy.h"
#include "Entities/Platformer/PlatformerEntity.h"
#include "Entities/Platformer/PlatformerFriendly.h"
#include "Events/CombatEvents.h"
#include "Scenes/Platformer/Level/Combat/Attacks/PlatformerAttack.h"

#include "Resources/UIResources.h"

using namespace cocos2d;

const std::string EntityAttackBehavior::MapKeyAttachedBehavior = "entity-attacks";

EntityAttackBehavior* EntityAttackBehavior::create(GameObject* owner, std::string attachedBehaviorArgs)
{
	EntityAttackBehavior* instance = new EntityAttackBehavior(owner, attachedBehaviorArgs);

	instance->autorelease();

	return instance;
}

EntityAttackBehavior::EntityAttackBehavior(GameObject* owner, std::string attachedBehaviorArgs) : super(owner, attachedBehaviorArgs)
{
	this->entity = dynamic_cast<PlatformerEntity*>(owner);

	if (this->entity == nullptr)
	{
		this->invalidate();
	}

	this->attacks = std::vector<PlatformerAttack*>();
}

EntityAttackBehavior::~EntityAttackBehavior()
{
}

void EntityAttackBehavior::initializePositions()
{
}

void EntityAttackBehavior::onLoad()
{
}

std::vector<PlatformerAttack*> EntityAttackBehavior::getAttacks()
{
	return this->attacks;
}

std::vector<PlatformerAttack*> EntityAttackBehavior::getAvailableAttacks()
{
	std::vector<PlatformerAttack*> availableAttacks = std::vector<PlatformerAttack*>();

	for (auto it = this->attacks.begin(); it != this->attacks.end(); it++)
	{
		/* TODO: Broken until attacks abstracted into their own behavior
		if ((*it)->getSpecialCost() <= this->getMana())
		{
			availableAttacks.push_back(*it);
		}*/
	}

	return availableAttacks;
}

std::vector<PlatformerAttack*> EntityAttackBehavior::cloneAttacks()
{
	std::vector<PlatformerAttack*> attacksClone = std::vector<PlatformerAttack*>();

	for (auto it = this->attacks.begin(); it != this->attacks.end(); it++)
	{
		attacksClone.push_back((*it)->clone());
	}

	return attacksClone;
}

void EntityAttackBehavior::registerAttack(PlatformerAttack* attack)
{
	this->addChild(attack);
	this->attacks.push_back(attack);
}
