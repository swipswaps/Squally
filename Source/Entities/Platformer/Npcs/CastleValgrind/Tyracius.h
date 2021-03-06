#pragma once
#include <string>

#include "Entities/Platformer/PlatformerFriendly.h"

class LocalizedString;

class Tyracius : public PlatformerFriendly
{
public:
	static Tyracius* deserialize(cocos2d::ValueMap& properties);

	cocos2d::Vec2 getDialogueOffset() override;
	LocalizedString* getEntityName() override;

	static const std::string MapKey;

protected:
	Tyracius(cocos2d::ValueMap& properties);
	virtual ~Tyracius();

private:
	typedef PlatformerFriendly super;
};
