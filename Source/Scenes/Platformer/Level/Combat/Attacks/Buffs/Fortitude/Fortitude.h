#pragma once

#include "Scenes/Platformer/Level/Combat/Buffs/Buff.h"

namespace cocos2d
{
	class Sprite;
}

class HackablePreview;
class PlatformerEntity;
class FortitudeClippy;
class SmartParticles;
class WorldSound;

class Fortitude : public Buff
{
public:
	static Fortitude* create(PlatformerEntity* caster, PlatformerEntity* target);

	void enableClippy();

	static const std::string PropertyRestorePotionTutorial;
	static const std::string FortitudeIdentifier;

protected:
	Fortitude(PlatformerEntity* caster, PlatformerEntity* target);
	virtual ~Fortitude();

	void onEnter() override;
	void initializePositions() override;
	void registerHackables() override;
	void onBeforeDamageTaken(volatile int* damageOrHealing, std::function<void()> handleCallback, PlatformerEntity* caster, PlatformerEntity* target) override;

private:
	typedef Buff super;

	void applyFortitude();
	
	volatile int currentDamageTaken;
	
	FortitudeClippy* clippy;
	cocos2d::Sprite* bubble;
	SmartParticles* spellEffect;
	cocos2d::Sprite* spellAura;
	
	static const int MaxMultiplier;
	static const int DamageReduction;
	static const float Duration;
};
