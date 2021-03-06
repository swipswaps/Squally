#pragma once
#include <set>

#include "Objects/Platformer/Interactables/Doors/MagePortals/MagePortal.h"

namespace cocos2d
{
	class DrawNode;
}

class SmartParticles;

class FirePortal : public MagePortal
{
public:
	static FirePortal* create(cocos2d::ValueMap& properties);

	void closePortal(bool instant) override;
	void openPortal(bool instant) override;

	static const std::string MapKey;

protected:
	FirePortal(cocos2d::ValueMap& properties);
	virtual ~FirePortal();
	void onEnter() override;
	void initializePositions() override;
	void initializeListeners() override;

private:
	typedef MagePortal super;

	SmartParticles* portalParticles;
	SmartParticles* edgeParticles;
};
