#pragma once
#include <chrono>
#include <mutex>
#include <thread>
#include <future> 

#include "cocos2d.h"

#include "Events/NavigationEvents.h"
#include "Engine/Maps/DefaultLayerDeserializer.h"
#include "Engine/Maps/ILayerDeserializer.h"
#include "Engine/Maps/IObjectDeserializer.h"
#include "Engine/Maps/SerializableMap.h"
#include "Engine/Physics/CollisionDeserializer.h"
#include "Engine/SmartNode.h"
#include "Engine/UI/Controls/CProgressBar.h"
#include "Engine/Utils/StrUtils.h"
#include "Entities/Isometric/IsometricEntityDeserializer.h"
#include "Entities/Platformer/Enemies/Castle/CastleEnemyDeserializer.h"
#include "Entities/Platformer/Enemies/Caverns/CavernsEnemyDeserializer.h"
#include "Entities/Platformer/Enemies/Forest/ForestEnemyDeserializer.h"
#include "Entities/Platformer/Enemies/Jungle/JungleEnemyDeserializer.h"
#include "Entities/Platformer/Enemies/Mech/MechEnemyDeserializer.h"
#include "Entities/Platformer/Enemies/Obelisk/ObeliskEnemyDeserializer.h"
#include "Entities/Platformer/Enemies/Ruins/RuinsEnemyDeserializer.h"
#include "Entities/Platformer/Enemies/Snow/SnowEnemyDeserializer.h"
#include "Entities/Platformer/Enemies/Volcano/VolcanoEnemyDeserializer.h"
#include "Entities/Platformer/Npcs/Castle/CastleNpcDeserializer.h"
#include "Entities/Platformer/Npcs/Caverns/CavernsNpcDeserializer.h"
#include "Entities/Platformer/Npcs/Forest/ForestNpcDeserializer.h"
#include "Entities/Platformer/Npcs/Jungle/JungleNpcDeserializer.h"
#include "Entities/Platformer/Npcs/Mech/MechNpcDeserializer.h"
#include "Entities/Platformer/Npcs/Obelisk/ObeliskNpcDeserializer.h"
#include "Entities/Platformer/Npcs/Ruins/RuinsNpcDeserializer.h"
#include "Entities/Platformer/Npcs/Snow/SnowNpcDeserializer.h"
#include "Entities/Platformer/Npcs/Volcano/VolcanoNpcDeserializer.h"
#include "Objects/Isometric/IsometricDecorDeserializer.h"
#include "Objects/Isometric/IsometricObjectDeserializer.h"
#include "Objects/Platformer/PlatformerDecorDeserializer.h"
#include "Objects/Platformer/PlatformerObjectDeserializer.h"
#include "Resources.h"
#include "Scenes/Maps/Platformer/Backgrounds/BackgroundDeserializer.h"
#include "Scenes/Maps/Platformer/Weather/WeatherDeserializer.h"
#include "Sound/MusicDeserializer.h"

using namespace cocos2d;
using namespace cocos_experimental;

class LoadingScreen : public SmartNode
{
public:
	static LoadingScreen * create();

	void loadLevel(std::string levelFile, const std::function<void(SerializableMap*)> newOnLoadCallback);

protected:
	LoadingScreen();
	~LoadingScreen();

private:
	void onEnter() override;
	void initializePositions() override;
	void onFileEnumerationComplete(std::vector<std::string> files);
	void onTextureAssetLoaded(Texture2D* asset);
	void onSoundAssetLoaded();
	void incrementLoadedFileCount();
	bool levelIsLoaded();
	void enterLevelIfDoneLoading();

	static bool isPreloadableImage(std::string filePath);
	static bool isPreloadableSound(std::string filePath);

	Node* background;
	CProgressBar* progressBar;
	SerializableMap* map;
	std::function<void(SerializableMap*)> onLoadCallback;

	int totalFileCount;
	std::atomic_int loadedFileCount;
	std::string currentLevelFile;

	static std::vector<ILayerDeserializer*> layerDeserializers;
	static std::vector<IObjectDeserializer*> objectDeserializers;
};
