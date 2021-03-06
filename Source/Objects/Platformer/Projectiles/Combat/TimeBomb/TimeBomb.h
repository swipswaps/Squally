#pragma once

#include "Objects/Platformer/Projectiles/Combat/ThrownObject/ThrownObject.h"

class ConstantString;
class LocalizedLabel;
class PlatformerAttack;
class PlatformerEntity;
class SmartAnimationSequenceNode;
class ThrownObject;
class WorldSound;

class TimeBomb : public ThrownObject
{
public:
	static TimeBomb* create(PlatformerEntity* owner, PlatformerEntity* target, std::function<void()> onExplode);
	
	void runSpawnFX() override;
	void runImpactFX() override;

protected:
	TimeBomb(PlatformerEntity* owner, PlatformerEntity* target, std::function<void()> onExplode);
	virtual ~TimeBomb();

	void onEnter() override;
	void initializePositions() override;
	void update(float dt) override;
	cocos2d::Vec2 getButtonOffset() override;
	void registerHackables() override;
	HackablePreview* createDefaultPreview() override;

private:
	typedef ThrownObject super;

	void updateTimerText();
	void explode();
	void tickTimeBomb();

	bool hasExploded;
	int bombTick;
	float elapsed;

	SmartAnimationSequenceNode* explosionAnim;
	WorldSound* spawnSound;
	WorldSound* tickSound;
	WorldSound* tickSoundPositive;
	WorldSound* explodeSound;
	std::function<void()> onExplode;

	cocos2d::Sprite* bomb;
	cocos2d::Sprite* timerPlate;
	LocalizedLabel* timerLabel;
	ConstantString* minutesString;
	ConstantString* secondsString;

	static const float HackDuration;
	static const int TimerInitial;
	static const int TimerMax;
};
