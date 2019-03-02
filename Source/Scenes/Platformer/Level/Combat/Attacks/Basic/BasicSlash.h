#pragma once

#include "Scenes/Platformer/Level/Combat/Attacks/PlatformerAttack.h"

class BasicSlash : public PlatformerAttack
{
public:
	static BasicSlash* create(float attackDuration, float recoverDuration);

	PlatformerAttack* clone() override;
	LocalizedString* getString() override;

protected:
	BasicSlash(float attackDuration, float recoverDuration);
	~BasicSlash() = default;

	void onDamageOrHealingDelt() override;

private:
	typedef PlatformerAttack super;
};