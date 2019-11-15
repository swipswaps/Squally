#include "RestoreHealth.h"

#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/2d/CCSprite.h"

#include "Engine/Animations/SmartAnimationSequenceNode.h"
#include "Engine/Events/ObjectEvents.h"
#include "Engine/Hackables/HackableCode.h"
#include "Engine/Hackables/HackableObject.h"
#include "Engine/Hackables/HackablePreview.h"
#include "Engine/Sound/WorldSound.h"
#include "Engine/Utils/GameUtils.h"
#include "Engine/Utils/MathUtils.h"
#include "Entities/Platformer/PlatformerEntity.h"
#include "Events/CombatEvents.h"
#include "Events/PlatformerEvents.h"
#include "Scenes/Platformer/Hackables/HackFlags.h"
#include "Scenes/Platformer/Inventory/Items/Consumables/Health/RestorePotion/RestoreHealthClippy.h"
#include "Scenes/Platformer/Inventory/Items/Consumables/Health/RestorePotion/RestoreHealthGenericPreview.h"
#include "Scenes/Platformer/Level/Combat/CombatMap.h"

#include "Resources/FXResources.h"
#include "Resources/SoundResources.h"
#include "Resources/UIResources.h"

#include "Strings/Menus/Hacking/Objects/RestorePotion/IncrementHealth/IncrementHealth.h"
#include "Strings/Menus/Hacking/Objects/RestorePotion/IncrementHealth/RegisterEdi.h"

using namespace cocos2d;

#define LOCAL_FUNC_ID_RESTORE 1

const std::string RestoreHealth::MapKeyPropertyRestorePotionTutorial = "restore-potion-tutorial";
const std::string RestoreHealth::RestoreHealthIdentifier = "restore-health";
const float RestoreHealth::TimeBetweenTicks = 0.5f;

RestoreHealth* RestoreHealth::create(PlatformerEntity* caster, PlatformerEntity* target, int healAmount)
{
	RestoreHealth* instance = new RestoreHealth(caster, target, healAmount);

	instance->autorelease();

	return instance;
}

RestoreHealth::RestoreHealth(PlatformerEntity* caster, PlatformerEntity* target, int healAmount) : super(caster, target)
{
	this->healEffect = SmartAnimationSequenceNode::create(FXResources::Heal_Heal_0000);
	this->healAmount = MathUtils::clamp(healAmount, 1, 255);
	this->impactSound = WorldSound::create(SoundResources::Platformer_Attacks_Spells_Heal2);
	this->healSound = WorldSound::create(SoundResources::Platformer_Attacks_Spells_Ding1);

	this->addChild(this->healEffect);
	this->addChild(this->impactSound);
	this->addChild(this->healSound);
}

RestoreHealth::~RestoreHealth()
{
}

void RestoreHealth::onEnter()
{
	super::onEnter();

	this->runRestoreHealth();
}

void RestoreHealth::initializePositions()
{
	super::initializePositions();

	this->setPosition(Vec2(0.0f, 118.0f));
}

void RestoreHealth::registerHackables()
{
	super::registerHackables();

	if (this->target == nullptr)
	{
		return;
	}

	std::map<unsigned char, HackableCode::LateBindData> lateBindMap =
	{
		{
			LOCAL_FUNC_ID_RESTORE,
			HackableCode::LateBindData(
				RestoreHealth::RestoreHealthIdentifier,
				Strings::Menus_Hacking_Objects_RestorePotion_IncrementHealth_IncrementHealth::create(),
				UIResources::Menus_Icons_ArrowUp,
				RestoreHealthGenericPreview::create(),
				{
					{ HackableCode::Register::zdi, Strings::Menus_Hacking_Objects_RestorePotion_IncrementHealth_RegisterEdi::create() }
				},
				int(HackFlags::None),
				2.0f,
				this->showClippy ? RestoreHealthClippy::create() : nullptr
			)
		},
	};

	auto restoreFunc = &RestoreHealth::runRestoreTick;
	this->hackables = HackableCode::create((void*&)restoreFunc, lateBindMap);

	for (auto it = this->hackables.begin(); it != this->hackables.end(); it++)
	{
		this->target->registerCode(*it);
	}
}

void RestoreHealth::runRestoreHealth()
{
	this->healEffect->playAnimationRepeat(FXResources::Heal_Heal_0000, 0.05f);
	this->impactSound->play();

	const float StartDelay = 1.0f;

	for (int healIndex = 0; healIndex < this->healAmount; healIndex++)
	{
		this->runAction(Sequence::create(
			DelayTime::create(RestoreHealth::TimeBetweenTicks * float(healIndex) + StartDelay),
			CallFunc::create([=]()
			{
				this->runRestoreTick();
			}),
			nullptr
		));
	}

	this->runAction(Sequence::create(
		DelayTime::create(RestoreHealth::TimeBetweenTicks * float(this->healAmount) + StartDelay),
		CallFunc::create([=]()
		{
			this->healEffect->runAction(FadeTo::create(0.25f, 0));
		}),
		DelayTime::create(0.5f),
		CallFunc::create([=]()
		{
			this->removeBuff();
		}),
		nullptr
	));
}

NO_OPTIMIZE void RestoreHealth::runRestoreTick()
{
	int incrementAmount = 0;

	ASM(push ZDI);
	ASM(mov ZDI, 0)

	HACKABLE_CODE_BEGIN(LOCAL_FUNC_ID_RESTORE);
	ASM(inc ZDI);
	HACKABLE_CODE_END();

	ASM_MOV_VAR_REG(incrementAmount, ZDI);

	ASM(pop ZDI);

	incrementAmount = MathUtils::clamp(incrementAmount, -1, 1);

	this->healSound->play();
	CombatEvents::TriggerDamageOrHealing(CombatEvents::DamageOrHealingArgs(this->caster, this->target, incrementAmount));

	HACKABLES_STOP_SEARCH();
}