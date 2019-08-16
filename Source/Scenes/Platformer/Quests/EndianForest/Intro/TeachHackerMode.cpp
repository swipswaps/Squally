#include "TeachHackerMode.h"

#include "cocos/2d/CCActionEase.h"
#include "cocos/2d/CCActionInstant.h"
#include "cocos/2d/CCActionInterval.h"
#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"
#include "cocos/base/CCValue.h"

#include "Engine/Animations/SmartAnimationNode.h"
#include "Engine/Dialogue/SpeechBubble.h"
#include "Engine/Events/ObjectEvents.h"
#include "Engine/Events/QuestEvents.h"
#include "Engine/Sound/Sound.h"
#include "Entities/Platformer/Helpers/EndianForest/FlyBot.h"
#include "Events/PlatformerEvents.h"
#include "Objects/Platformer/Cinematic/CinematicMarker.h"

#include "Strings/Dialogue/Story/Intro/HackerMode.h"

using namespace cocos2d;

const std::string TeachHackerMode::MapKeyQuest = "teach-hacker-mode";

TeachHackerMode* TeachHackerMode::create(GameObject* owner, QuestLine* questLine,  std::string questTag)
{
	TeachHackerMode* instance = new TeachHackerMode(owner, questLine, questTag);

	instance->autorelease();

	return instance;
}

TeachHackerMode::TeachHackerMode(GameObject* owner, QuestLine* questLine, std::string questTag) : super(owner, questLine, TeachHackerMode::MapKeyQuest, questTag, false)
{
	this->hasRunEvent = false;
	this->flyBot = nullptr;
}

TeachHackerMode::~TeachHackerMode()
{
}

void TeachHackerMode::onLoad(QuestState questState)
{
	this->scheduleUpdate();
}

void TeachHackerMode::onActivate(bool isActiveThroughSkippable)
{
	this->listenForMapEvent(TeachHackerMode::MapKeyQuest, [=](ValueMap args)
	{
		this->complete();

		this->runCinematicSequence();
	});
}

void TeachHackerMode::onComplete()
{
}

void TeachHackerMode::onSkipped()
{
	this->removeAllListeners();
}

void TeachHackerMode::update(float dt)
{
	super::update(dt);

	if (this->flyBot == nullptr)
	{
		ObjectEvents::QueryObjects(QueryObjectsArgs<FlyBot>([&](FlyBot* flyBot)
		{
			this->flyBot = flyBot;
		}));
	}
}

void TeachHackerMode::runCinematicSequence()
{
	if (this->hasRunEvent)
	{
		return;
	}
	
	this->hasRunEvent = true;

	if (this->flyBot != nullptr)
	{
		PlatformerEvents::TriggerCinematicHijack();

		this->flyBot->runAction(Sequence::create(
			CallFunc::create([=]()
			{
				this->flyBot->droidChatterSound->play();
			}),
			CallFunc::create([=]()
			{
				this->flyBot->speechBubble->runDialogue(Strings::Dialogue_Story_Intro_HackerMode::create());
			}),
			DelayTime::create(4.0f),
			CallFunc::create([=]()
			{
				PlatformerEvents::TriggerCinematicRestore();
				this->flyBot->speechBubble->hideDialogue();
			}),
			nullptr
		));
	}
}
