#include "PlatformerEntityDeserializer.h"

#include "cocos/base/CCEventCustom.h"
#include "cocos/base/CCEventListenerCustom.h"

#include "Engine/GlobalDirector.h"
#include "Engine/Maps/SerializableObject.h"
#include "Entities/Platformer/Squally/Squally.h"

////////////////////////////////////
// BEGIN: THIS CODE IS GENERATED: //
////V////V////V////V////V////V////V/

#include "Entities/Platformer/Enemies/BalmerPeaks/Cyrogen.h"
#include "Entities/Platformer/Enemies/BalmerPeaks/FrostFiend.h"
#include "Entities/Platformer/Enemies/BalmerPeaks/GoblinElf.h"
#include "Entities/Platformer/Enemies/BalmerPeaks/IceGolem.h"
#include "Entities/Platformer/Enemies/BalmerPeaks/PenguinGrunt.h"
#include "Entities/Platformer/Enemies/BalmerPeaks/PenguinWarrior.h"
#include "Entities/Platformer/Enemies/BalmerPeaks/Santa.h"
#include "Entities/Platformer/Enemies/BalmerPeaks/SnowFiend.h"
#include "Entities/Platformer/Enemies/BalmerPeaks/ToySoldierGoblin.h"
#include "Entities/Platformer/Enemies/BalmerPeaks/Viking.h"
#include "Entities/Platformer/Enemies/BalmerPeaks/WaterElemental.h"
#include "Entities/Platformer/Enemies/BalmerPeaks/Yeti.h"
#include "Entities/Platformer/Helpers/BalmerPeaks/Snowman.h"
#include "Entities/Platformer/Helpers/BalmerPeaks/YetiBaby.h"
#include "Entities/Platformer/Npcs/BalmerPeaks/Aspen.h"
#include "Entities/Platformer/Npcs/BalmerPeaks/Aster.h"
#include "Entities/Platformer/Npcs/BalmerPeaks/Bodom.h"
#include "Entities/Platformer/Npcs/BalmerPeaks/Cookie.h"
#include "Entities/Platformer/Npcs/BalmerPeaks/Cooper.h"
#include "Entities/Platformer/Npcs/BalmerPeaks/Irmik.h"
#include "Entities/Platformer/Npcs/BalmerPeaks/Jingles.h"
#include "Entities/Platformer/Npcs/BalmerPeaks/Juniper.h"
#include "Entities/Platformer/Npcs/BalmerPeaks/Kringle.h"
#include "Entities/Platformer/Npcs/BalmerPeaks/Nessie.h"
#include "Entities/Platformer/Npcs/BalmerPeaks/PrincessPepper.h"
#include "Entities/Platformer/Npcs/BalmerPeaks/Thatcher.h"
#include "Entities/Platformer/Npcs/BalmerPeaks/Theldar.h"
#include "Entities/Platformer/Npcs/BalmerPeaks/Tinsel.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Agnes.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Jack.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Reaper.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Scarecrow.h"
#include "Entities/Platformer/Enemies/CastleValgrind/SkeletalPirate.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Thug.h"
#include "Entities/Platformer/Enemies/CastleValgrind/VampireLord.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Vampiress.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Werewolf.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Wraith.h"
#include "Entities/Platformer/Enemies/CastleValgrind/Zombie.h"
#include "Entities/Platformer/Enemies/CastleValgrind/ZombieElric.h"
#include "Entities/Platformer/Helpers/CastleValgrind/Knight.h"
#include "Entities/Platformer/Helpers/CastleValgrind/Princess.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Elric.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Garin.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Gaunt.h"
#include "Entities/Platformer/Npcs/CastleValgrind/KingRedsong.h"
#include "Entities/Platformer/Npcs/CastleValgrind/KingRedsongSlime.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Leopold.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Leroy.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Mabel.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Merlin.h"
#include "Entities/Platformer/Npcs/CastleValgrind/PrincessOpal.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Raven.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Rogas.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Thurstan.h"
#include "Entities/Platformer/Npcs/CastleValgrind/Tyracius.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/Asmodeus.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/DemonDragon.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/DemonGhost.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/DemonGrunt.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/DemonRogue.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/DemonShaman.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/DemonSwordsman.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/DemonWarrior.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/FireElemental.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/FireTiger.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/Krampus.h"
#include "Entities/Platformer/Enemies/DaemonsHallow/LavaGolem.h"
#include "Entities/Platformer/Helpers/DaemonsHallow/Apple.h"
#include "Entities/Platformer/Helpers/DaemonsHallow/CritterDemon.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Ash.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Brine.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Celeste.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Cindra.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Drak.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Igneus.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Lucifer.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Magnus.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Pan.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/PrincessMittens.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Ragnis.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Rupert.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Rusty.h"
#include "Entities/Platformer/Npcs/DaemonsHallow/Scaldor.h"
#include "Entities/Platformer/Enemies/EndianForest/Centaur.h"
#include "Entities/Platformer/Enemies/EndianForest/Cyclops.h"
#include "Entities/Platformer/Enemies/EndianForest/GoblinGruntBoar.h"
#include "Entities/Platformer/Enemies/EndianForest/GoblinShaman.h"
#include "Entities/Platformer/Enemies/EndianForest/GoblinWarriorPig.h"
#include "Entities/Platformer/Enemies/EndianForest/KingGrogg.h"
#include "Entities/Platformer/Enemies/EndianForest/Ogre.h"
#include "Entities/Platformer/Enemies/EndianForest/OrcBomber.h"
#include "Entities/Platformer/Enemies/EndianForest/OrcGrunt.h"
#include "Entities/Platformer/Enemies/EndianForest/OrcSwordsman.h"
#include "Entities/Platformer/Enemies/EndianForest/OrcWarrior.h"
#include "Entities/Platformer/Enemies/EndianForest/Troll.h"
#include "Entities/Platformer/Helpers/EndianForest/Goblin.h"
#include "Entities/Platformer/Helpers/EndianForest/Turtle.h"
#include "Entities/Platformer/Npcs/EndianForest/Appolo.h"
#include "Entities/Platformer/Npcs/EndianForest/Ara.h"
#include "Entities/Platformer/Npcs/EndianForest/Bard.h"
#include "Entities/Platformer/Npcs/EndianForest/Blackbeard.h"
#include "Entities/Platformer/Npcs/EndianForest/Chiron.h"
#include "Entities/Platformer/Npcs/EndianForest/Elriel.h"
#include "Entities/Platformer/Npcs/EndianForest/Gramps.h"
#include "Entities/Platformer/Npcs/EndianForest/Liana.h"
#include "Entities/Platformer/Npcs/EndianForest/Lycan.h"
#include "Entities/Platformer/Npcs/EndianForest/Minos.h"
#include "Entities/Platformer/Npcs/EndianForest/Polyphemus.h"
#include "Entities/Platformer/Npcs/EndianForest/PrincessMatu.h"
#include "Entities/Platformer/Npcs/EndianForest/Robin.h"
#include "Entities/Platformer/Npcs/EndianForest/Toben.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/BoneFiend.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/Hunter.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/KingZul.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/Mystic.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/ReanimatedFighter.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/ReanimatedPig.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/SkeletalBaron.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/SkeletalCleaver.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/SkeletalKnight.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/SkeletalPriestess.h"
#include "Entities/Platformer/Enemies/LambdaCrypts/Undead.h"
#include "Entities/Platformer/Helpers/LambdaCrypts/Ghost.h"
#include "Entities/Platformer/Helpers/LambdaCrypts/Grim.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Amelia.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Azmus.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Dudly.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Garrick.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Johann.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Necron.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/PrincessNebea.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Roger.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Thion.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Ursula.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Vesuvius.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Viper.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Zana.h"
#include "Entities/Platformer/Npcs/LambdaCrypts/Zelina.h"
#include "Entities/Platformer/Enemies/SeaSharpCaverns/Barbarian.h"
#include "Entities/Platformer/Enemies/SeaSharpCaverns/EarthElemental.h"
#include "Entities/Platformer/Enemies/SeaSharpCaverns/EarthGolem.h"
#include "Entities/Platformer/Enemies/SeaSharpCaverns/ForestGolem.h"
#include "Entities/Platformer/Enemies/SeaSharpCaverns/Gorilla.h"
#include "Entities/Platformer/Enemies/SeaSharpCaverns/LightningGolem.h"
#include "Entities/Platformer/Enemies/SeaSharpCaverns/Rhinoman.h"
#include "Entities/Platformer/Enemies/SeaSharpCaverns/Shaman.h"
#include "Entities/Platformer/Enemies/SeaSharpCaverns/SkeletalArcher.h"
#include "Entities/Platformer/Enemies/SeaSharpCaverns/SkeletalNecromancer.h"
#include "Entities/Platformer/Enemies/SeaSharpCaverns/SkeletalWarrior.h"
#include "Entities/Platformer/Enemies/SeaSharpCaverns/TikiGolem.h"
#include "Entities/Platformer/Helpers/SeaSharpCaverns/Gecko.h"
#include "Entities/Platformer/Npcs/SeaSharpCaverns/Alder.h"
#include "Entities/Platformer/Npcs/SeaSharpCaverns/Bonnie.h"
#include "Entities/Platformer/Npcs/SeaSharpCaverns/Brock.h"
#include "Entities/Platformer/Npcs/SeaSharpCaverns/Burch.h"
#include "Entities/Platformer/Npcs/SeaSharpCaverns/Cypress.h"
#include "Entities/Platformer/Npcs/SeaSharpCaverns/Finch.h"
#include "Entities/Platformer/Npcs/SeaSharpCaverns/Fraya.h"
#include "Entities/Platformer/Npcs/SeaSharpCaverns/Jasper.h"
#include "Entities/Platformer/Npcs/SeaSharpCaverns/Mildred.h"
#include "Entities/Platformer/Npcs/SeaSharpCaverns/Olive.h"
#include "Entities/Platformer/Npcs/SeaSharpCaverns/PrincessDawn.h"
#include "Entities/Platformer/Npcs/SeaSharpCaverns/Raka.h"
#include "Entities/Platformer/Npcs/SeaSharpCaverns/Sarude.h"
#include "Entities/Platformer/Npcs/SeaSharpCaverns/Shen.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/AnubisPup.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/AnubisWarrior.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/LionMan.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/Lioness.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/Medusa.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/Mermaid.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/Minotaur.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/MummyPriest.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/MummyWarrior.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/Osiris.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/TigerMan.h"
#include "Entities/Platformer/Enemies/UnderflowRuins/Tigress.h"
#include "Entities/Platformer/Helpers/UnderflowRuins/Mummy.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Ajax.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Angel.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Aphrodite.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Ares.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Athena.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Cleopatra.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Geryon.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Griffin.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Hades.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Hera.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Horus.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Poseidon.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Thor.h"
#include "Entities/Platformer/Npcs/UnderflowRuins/Zeus.h"
#include "Entities/Platformer/Enemies/VoidStar/Abomination.h"
#include "Entities/Platformer/Enemies/VoidStar/Assassin.h"
#include "Entities/Platformer/Enemies/VoidStar/BoneKnight.h"
#include "Entities/Platformer/Enemies/VoidStar/DarkTiger.h"
#include "Entities/Platformer/Enemies/VoidStar/EvilEye.h"
#include "Entities/Platformer/Enemies/VoidStar/Exterminator.h"
#include "Entities/Platformer/Enemies/VoidStar/Gargoyle.h"
#include "Entities/Platformer/Enemies/VoidStar/Shade.h"
#include "Entities/Platformer/Enemies/VoidStar/VoidArcher.h"
#include "Entities/Platformer/Enemies/VoidStar/VoidDemon.h"
#include "Entities/Platformer/Enemies/VoidStar/Warlock.h"
#include "Entities/Platformer/Helpers/VoidStar/Professor.h"
#include "Entities/Platformer/Helpers/VoidStar/Robot.h"
#include "Entities/Platformer/Npcs/VoidStar/Atreus.h"
#include "Entities/Platformer/Npcs/VoidStar/Bancroft.h"
#include "Entities/Platformer/Npcs/VoidStar/Godiva.h"
#include "Entities/Platformer/Npcs/VoidStar/Illia.h"
#include "Entities/Platformer/Npcs/VoidStar/Leon.h"
#include "Entities/Platformer/Npcs/VoidStar/Mara.h"
#include "Entities/Platformer/Npcs/VoidStar/Marcel.h"
#include "Entities/Platformer/Npcs/VoidStar/Piper.h"
#include "Entities/Platformer/Npcs/VoidStar/QueenElise.h"
#include "Entities/Platformer/Npcs/VoidStar/Radon.h"
#include "Entities/Platformer/Npcs/VoidStar/Ralston.h"
#include "Entities/Platformer/Npcs/VoidStar/Xenon.h"
#include "Entities/Platformer/Npcs/VoidStar/Ysara.h"

////Y////Y////Y////Y////Y////Y////Y/
// END: THIS CODE IS GENERATED    //
////////////////////////////////////

using namespace cocos2d;

const std::string PlatformerEntityDeserializer::KeyTypeEntity = "entity";

PlatformerEntityDeserializer* PlatformerEntityDeserializer::instance = nullptr;

void PlatformerEntityDeserializer::registerGlobalNode()
{
	// Register this class globally so that it can always listen for events
	GlobalDirector::getInstance()->registerGlobalNode(PlatformerEntityDeserializer::getInstance());
}

PlatformerEntityDeserializer* PlatformerEntityDeserializer::getInstance()
{
	if (PlatformerEntityDeserializer::instance == nullptr)
	{
		PlatformerEntityDeserializer::instance = new PlatformerEntityDeserializer();

		instance->autorelease();
	}

	return instance;
}

PlatformerEntityDeserializer::PlatformerEntityDeserializer()
{
}

PlatformerEntityDeserializer::~PlatformerEntityDeserializer()
{
}

void PlatformerEntityDeserializer::initializeListeners()
{
	super::initializeListeners();

	EventListenerCustom* deserializationRequestListener = EventListenerCustom::create(
		DeserializationEvents::RequestObjectDeserializeEvent,
		[=](EventCustom* eventCustom)
		{
			DeserializationEvents::ObjectDeserializationRequestArgs* args = static_cast<DeserializationEvents::ObjectDeserializationRequestArgs*>(eventCustom->getUserData());

			if (args != nullptr)
			{
				this->onDeserializationRequest(args);
			}
		}
	);

	this->addGlobalEventListener(deserializationRequestListener);
}

void PlatformerEntityDeserializer::onDeserializationRequest(DeserializationEvents::ObjectDeserializationRequestArgs* args)
{
	if (args->typeName == PlatformerEntityDeserializer::KeyTypeEntity)
	{
		ValueMap properties = args->properties;
		std::string name = properties.at(SerializableObject::MapKeyName).asString();
		SerializableObject* newEntity = nullptr;

		if (name == Squally::MapKeySqually)
		{
			newEntity = Squally::deserialize(properties);
		}

		////////////////////////////////////
		// BEGIN: THIS CODE IS GENERATED: //
		////X////X////X////X////X////X////X/

		if (name == Cyrogen::MapKeyCyrogen)
		{
			newEntity = Cyrogen::deserialize(properties);
		}
		if (name == FrostFiend::MapKeyFrostFiend)
		{
			newEntity = FrostFiend::deserialize(properties);
		}
		if (name == GoblinElf::MapKeyGoblinElf)
		{
			newEntity = GoblinElf::deserialize(properties);
		}
		if (name == IceGolem::MapKeyIceGolem)
		{
			newEntity = IceGolem::deserialize(properties);
		}
		if (name == PenguinGrunt::MapKeyPenguinGrunt)
		{
			newEntity = PenguinGrunt::deserialize(properties);
		}
		if (name == PenguinWarrior::MapKeyPenguinWarrior)
		{
			newEntity = PenguinWarrior::deserialize(properties);
		}
		if (name == Santa::MapKeySanta)
		{
			newEntity = Santa::deserialize(properties);
		}
		if (name == SnowFiend::MapKeySnowFiend)
		{
			newEntity = SnowFiend::deserialize(properties);
		}
		if (name == ToySoldierGoblin::MapKeyToySoldierGoblin)
		{
			newEntity = ToySoldierGoblin::deserialize(properties);
		}
		if (name == Viking::MapKeyViking)
		{
			newEntity = Viking::deserialize(properties);
		}
		if (name == WaterElemental::MapKeyWaterElemental)
		{
			newEntity = WaterElemental::deserialize(properties);
		}
		if (name == Yeti::MapKeyYeti)
		{
			newEntity = Yeti::deserialize(properties);
		}
		if (name == Snowman::MapKeySnowman)
		{
			newEntity = Snowman::deserialize(properties);
		}
		if (name == YetiBaby::MapKeyYetiBaby)
		{
			newEntity = YetiBaby::deserialize(properties);
		}
		if (name == Aspen::MapKeyAspen)
		{
			newEntity = Aspen::deserialize(properties);
		}
		if (name == Aster::MapKeyAster)
		{
			newEntity = Aster::deserialize(properties);
		}
		if (name == Bodom::MapKeyBodom)
		{
			newEntity = Bodom::deserialize(properties);
		}
		if (name == Cookie::MapKeyCookie)
		{
			newEntity = Cookie::deserialize(properties);
		}
		if (name == Cooper::MapKeyCooper)
		{
			newEntity = Cooper::deserialize(properties);
		}
		if (name == Irmik::MapKeyIrmik)
		{
			newEntity = Irmik::deserialize(properties);
		}
		if (name == Jingles::MapKeyJingles)
		{
			newEntity = Jingles::deserialize(properties);
		}
		if (name == Juniper::MapKeyJuniper)
		{
			newEntity = Juniper::deserialize(properties);
		}
		if (name == Kringle::MapKeyKringle)
		{
			newEntity = Kringle::deserialize(properties);
		}
		if (name == Nessie::MapKeyNessie)
		{
			newEntity = Nessie::deserialize(properties);
		}
		if (name == PrincessPepper::MapKeyPrincessPepper)
		{
			newEntity = PrincessPepper::deserialize(properties);
		}
		if (name == Thatcher::MapKeyThatcher)
		{
			newEntity = Thatcher::deserialize(properties);
		}
		if (name == Theldar::MapKeyTheldar)
		{
			newEntity = Theldar::deserialize(properties);
		}
		if (name == Tinsel::MapKeyTinsel)
		{
			newEntity = Tinsel::deserialize(properties);
		}
		if (name == Agnes::MapKeyAgnes)
		{
			newEntity = Agnes::deserialize(properties);
		}
		if (name == Jack::MapKeyJack)
		{
			newEntity = Jack::deserialize(properties);
		}
		if (name == Reaper::MapKeyReaper)
		{
			newEntity = Reaper::deserialize(properties);
		}
		if (name == Scarecrow::MapKeyScarecrow)
		{
			newEntity = Scarecrow::deserialize(properties);
		}
		if (name == SkeletalPirate::MapKeySkeletalPirate)
		{
			newEntity = SkeletalPirate::deserialize(properties);
		}
		if (name == Thug::MapKeyThug)
		{
			newEntity = Thug::deserialize(properties);
		}
		if (name == VampireLord::MapKeyVampireLord)
		{
			newEntity = VampireLord::deserialize(properties);
		}
		if (name == Vampiress::MapKeyVampiress)
		{
			newEntity = Vampiress::deserialize(properties);
		}
		if (name == Werewolf::MapKeyWerewolf)
		{
			newEntity = Werewolf::deserialize(properties);
		}
		if (name == Wraith::MapKeyWraith)
		{
			newEntity = Wraith::deserialize(properties);
		}
		if (name == Zombie::MapKeyZombie)
		{
			newEntity = Zombie::deserialize(properties);
		}
		if (name == ZombieElric::MapKeyZombieElric)
		{
			newEntity = ZombieElric::deserialize(properties);
		}
		if (name == Knight::MapKeyKnight)
		{
			newEntity = Knight::deserialize(properties);
		}
		if (name == Princess::MapKeyPrincess)
		{
			newEntity = Princess::deserialize(properties);
		}
		if (name == Elric::MapKeyElric)
		{
			newEntity = Elric::deserialize(properties);
		}
		if (name == Garin::MapKeyGarin)
		{
			newEntity = Garin::deserialize(properties);
		}
		if (name == Gaunt::MapKeyGaunt)
		{
			newEntity = Gaunt::deserialize(properties);
		}
		if (name == KingRedsong::MapKeyKingRedsong)
		{
			newEntity = KingRedsong::deserialize(properties);
		}
		if (name == KingRedsongSlime::MapKeyKingRedsongSlime)
		{
			newEntity = KingRedsongSlime::deserialize(properties);
		}
		if (name == Leopold::MapKeyLeopold)
		{
			newEntity = Leopold::deserialize(properties);
		}
		if (name == Leroy::MapKeyLeroy)
		{
			newEntity = Leroy::deserialize(properties);
		}
		if (name == Mabel::MapKeyMabel)
		{
			newEntity = Mabel::deserialize(properties);
		}
		if (name == Merlin::MapKeyMerlin)
		{
			newEntity = Merlin::deserialize(properties);
		}
		if (name == PrincessOpal::MapKeyPrincessOpal)
		{
			newEntity = PrincessOpal::deserialize(properties);
		}
		if (name == Raven::MapKeyRaven)
		{
			newEntity = Raven::deserialize(properties);
		}
		if (name == Rogas::MapKeyRogas)
		{
			newEntity = Rogas::deserialize(properties);
		}
		if (name == Thurstan::MapKeyThurstan)
		{
			newEntity = Thurstan::deserialize(properties);
		}
		if (name == Tyracius::MapKeyTyracius)
		{
			newEntity = Tyracius::deserialize(properties);
		}
		if (name == Asmodeus::MapKeyAsmodeus)
		{
			newEntity = Asmodeus::deserialize(properties);
		}
		if (name == DemonDragon::MapKeyDemonDragon)
		{
			newEntity = DemonDragon::deserialize(properties);
		}
		if (name == DemonGhost::MapKeyDemonGhost)
		{
			newEntity = DemonGhost::deserialize(properties);
		}
		if (name == DemonGrunt::MapKeyDemonGrunt)
		{
			newEntity = DemonGrunt::deserialize(properties);
		}
		if (name == DemonRogue::MapKeyDemonRogue)
		{
			newEntity = DemonRogue::deserialize(properties);
		}
		if (name == DemonShaman::MapKeyDemonShaman)
		{
			newEntity = DemonShaman::deserialize(properties);
		}
		if (name == DemonSwordsman::MapKeyDemonSwordsman)
		{
			newEntity = DemonSwordsman::deserialize(properties);
		}
		if (name == DemonWarrior::MapKeyDemonWarrior)
		{
			newEntity = DemonWarrior::deserialize(properties);
		}
		if (name == FireElemental::MapKeyFireElemental)
		{
			newEntity = FireElemental::deserialize(properties);
		}
		if (name == FireTiger::MapKeyFireTiger)
		{
			newEntity = FireTiger::deserialize(properties);
		}
		if (name == Krampus::MapKeyKrampus)
		{
			newEntity = Krampus::deserialize(properties);
		}
		if (name == LavaGolem::MapKeyLavaGolem)
		{
			newEntity = LavaGolem::deserialize(properties);
		}
		if (name == Apple::MapKeyApple)
		{
			newEntity = Apple::deserialize(properties);
		}
		if (name == CritterDemon::MapKeyCritterDemon)
		{
			newEntity = CritterDemon::deserialize(properties);
		}
		if (name == Ash::MapKeyAsh)
		{
			newEntity = Ash::deserialize(properties);
		}
		if (name == Brine::MapKeyBrine)
		{
			newEntity = Brine::deserialize(properties);
		}
		if (name == Celeste::MapKeyCeleste)
		{
			newEntity = Celeste::deserialize(properties);
		}
		if (name == Cindra::MapKeyCindra)
		{
			newEntity = Cindra::deserialize(properties);
		}
		if (name == Drak::MapKeyDrak)
		{
			newEntity = Drak::deserialize(properties);
		}
		if (name == Igneus::MapKeyIgneus)
		{
			newEntity = Igneus::deserialize(properties);
		}
		if (name == Lucifer::MapKeyLucifer)
		{
			newEntity = Lucifer::deserialize(properties);
		}
		if (name == Magnus::MapKeyMagnus)
		{
			newEntity = Magnus::deserialize(properties);
		}
		if (name == Pan::MapKeyPan)
		{
			newEntity = Pan::deserialize(properties);
		}
		if (name == PrincessMittens::MapKeyPrincessMittens)
		{
			newEntity = PrincessMittens::deserialize(properties);
		}
		if (name == Ragnis::MapKeyRagnis)
		{
			newEntity = Ragnis::deserialize(properties);
		}
		if (name == Rupert::MapKeyRupert)
		{
			newEntity = Rupert::deserialize(properties);
		}
		if (name == Rusty::MapKeyRusty)
		{
			newEntity = Rusty::deserialize(properties);
		}
		if (name == Scaldor::MapKeyScaldor)
		{
			newEntity = Scaldor::deserialize(properties);
		}
		if (name == Centaur::MapKeyCentaur)
		{
			newEntity = Centaur::deserialize(properties);
		}
		if (name == Cyclops::MapKeyCyclops)
		{
			newEntity = Cyclops::deserialize(properties);
		}
		if (name == GoblinGruntBoar::MapKeyGoblinGruntBoar)
		{
			newEntity = GoblinGruntBoar::deserialize(properties);
		}
		if (name == GoblinShaman::MapKeyGoblinShaman)
		{
			newEntity = GoblinShaman::deserialize(properties);
		}
		if (name == GoblinWarriorPig::MapKeyGoblinWarriorPig)
		{
			newEntity = GoblinWarriorPig::deserialize(properties);
		}
		if (name == KingGrogg::MapKeyKingGrogg)
		{
			newEntity = KingGrogg::deserialize(properties);
		}
		if (name == Ogre::MapKeyOgre)
		{
			newEntity = Ogre::deserialize(properties);
		}
		if (name == OrcBomber::MapKeyOrcBomber)
		{
			newEntity = OrcBomber::deserialize(properties);
		}
		if (name == OrcGrunt::MapKeyOrcGrunt)
		{
			newEntity = OrcGrunt::deserialize(properties);
		}
		if (name == OrcSwordsman::MapKeyOrcSwordsman)
		{
			newEntity = OrcSwordsman::deserialize(properties);
		}
		if (name == OrcWarrior::MapKeyOrcWarrior)
		{
			newEntity = OrcWarrior::deserialize(properties);
		}
		if (name == Troll::MapKeyTroll)
		{
			newEntity = Troll::deserialize(properties);
		}
		if (name == Goblin::MapKeyGoblin)
		{
			newEntity = Goblin::deserialize(properties);
		}
		if (name == Turtle::MapKeyTurtle)
		{
			newEntity = Turtle::deserialize(properties);
		}
		if (name == Appolo::MapKeyAppolo)
		{
			newEntity = Appolo::deserialize(properties);
		}
		if (name == Ara::MapKeyAra)
		{
			newEntity = Ara::deserialize(properties);
		}
		if (name == Bard::MapKeyBard)
		{
			newEntity = Bard::deserialize(properties);
		}
		if (name == Blackbeard::MapKeyBlackbeard)
		{
			newEntity = Blackbeard::deserialize(properties);
		}
		if (name == Chiron::MapKeyChiron)
		{
			newEntity = Chiron::deserialize(properties);
		}
		if (name == Elriel::MapKeyElriel)
		{
			newEntity = Elriel::deserialize(properties);
		}
		if (name == Gramps::MapKeyGramps)
		{
			newEntity = Gramps::deserialize(properties);
		}
		if (name == Liana::MapKeyLiana)
		{
			newEntity = Liana::deserialize(properties);
		}
		if (name == Lycan::MapKeyLycan)
		{
			newEntity = Lycan::deserialize(properties);
		}
		if (name == Minos::MapKeyMinos)
		{
			newEntity = Minos::deserialize(properties);
		}
		if (name == Polyphemus::MapKeyPolyphemus)
		{
			newEntity = Polyphemus::deserialize(properties);
		}
		if (name == PrincessMatu::MapKeyPrincessMatu)
		{
			newEntity = PrincessMatu::deserialize(properties);
		}
		if (name == Robin::MapKeyRobin)
		{
			newEntity = Robin::deserialize(properties);
		}
		if (name == Toben::MapKeyToben)
		{
			newEntity = Toben::deserialize(properties);
		}
		if (name == BoneFiend::MapKeyBoneFiend)
		{
			newEntity = BoneFiend::deserialize(properties);
		}
		if (name == Hunter::MapKeyHunter)
		{
			newEntity = Hunter::deserialize(properties);
		}
		if (name == KingZul::MapKeyKingZul)
		{
			newEntity = KingZul::deserialize(properties);
		}
		if (name == Mystic::MapKeyMystic)
		{
			newEntity = Mystic::deserialize(properties);
		}
		if (name == ReanimatedFighter::MapKeyReanimatedFighter)
		{
			newEntity = ReanimatedFighter::deserialize(properties);
		}
		if (name == ReanimatedPig::MapKeyReanimatedPig)
		{
			newEntity = ReanimatedPig::deserialize(properties);
		}
		if (name == SkeletalBaron::MapKeySkeletalBaron)
		{
			newEntity = SkeletalBaron::deserialize(properties);
		}
		if (name == SkeletalCleaver::MapKeySkeletalCleaver)
		{
			newEntity = SkeletalCleaver::deserialize(properties);
		}
		if (name == SkeletalKnight::MapKeySkeletalKnight)
		{
			newEntity = SkeletalKnight::deserialize(properties);
		}
		if (name == SkeletalPriestess::MapKeySkeletalPriestess)
		{
			newEntity = SkeletalPriestess::deserialize(properties);
		}
		if (name == Undead::MapKeyUndead)
		{
			newEntity = Undead::deserialize(properties);
		}
		if (name == Ghost::MapKeyGhost)
		{
			newEntity = Ghost::deserialize(properties);
		}
		if (name == Grim::MapKeyGrim)
		{
			newEntity = Grim::deserialize(properties);
		}
		if (name == Amelia::MapKeyAmelia)
		{
			newEntity = Amelia::deserialize(properties);
		}
		if (name == Azmus::MapKeyAzmus)
		{
			newEntity = Azmus::deserialize(properties);
		}
		if (name == Dudly::MapKeyDudly)
		{
			newEntity = Dudly::deserialize(properties);
		}
		if (name == Garrick::MapKeyGarrick)
		{
			newEntity = Garrick::deserialize(properties);
		}
		if (name == Johann::MapKeyJohann)
		{
			newEntity = Johann::deserialize(properties);
		}
		if (name == Necron::MapKeyNecron)
		{
			newEntity = Necron::deserialize(properties);
		}
		if (name == PrincessNebea::MapKeyPrincessNebea)
		{
			newEntity = PrincessNebea::deserialize(properties);
		}
		if (name == Roger::MapKeyRoger)
		{
			newEntity = Roger::deserialize(properties);
		}
		if (name == Thion::MapKeyThion)
		{
			newEntity = Thion::deserialize(properties);
		}
		if (name == Ursula::MapKeyUrsula)
		{
			newEntity = Ursula::deserialize(properties);
		}
		if (name == Vesuvius::MapKeyVesuvius)
		{
			newEntity = Vesuvius::deserialize(properties);
		}
		if (name == Viper::MapKeyViper)
		{
			newEntity = Viper::deserialize(properties);
		}
		if (name == Zana::MapKeyZana)
		{
			newEntity = Zana::deserialize(properties);
		}
		if (name == Zelina::MapKeyZelina)
		{
			newEntity = Zelina::deserialize(properties);
		}
		if (name == Barbarian::MapKeyBarbarian)
		{
			newEntity = Barbarian::deserialize(properties);
		}
		if (name == EarthElemental::MapKeyEarthElemental)
		{
			newEntity = EarthElemental::deserialize(properties);
		}
		if (name == EarthGolem::MapKeyEarthGolem)
		{
			newEntity = EarthGolem::deserialize(properties);
		}
		if (name == ForestGolem::MapKeyForestGolem)
		{
			newEntity = ForestGolem::deserialize(properties);
		}
		if (name == Gorilla::MapKeyGorilla)
		{
			newEntity = Gorilla::deserialize(properties);
		}
		if (name == LightningGolem::MapKeyLightningGolem)
		{
			newEntity = LightningGolem::deserialize(properties);
		}
		if (name == Rhinoman::MapKeyRhinoman)
		{
			newEntity = Rhinoman::deserialize(properties);
		}
		if (name == Shaman::MapKeyShaman)
		{
			newEntity = Shaman::deserialize(properties);
		}
		if (name == SkeletalArcher::MapKeySkeletalArcher)
		{
			newEntity = SkeletalArcher::deserialize(properties);
		}
		if (name == SkeletalNecromancer::MapKeySkeletalNecromancer)
		{
			newEntity = SkeletalNecromancer::deserialize(properties);
		}
		if (name == SkeletalWarrior::MapKeySkeletalWarrior)
		{
			newEntity = SkeletalWarrior::deserialize(properties);
		}
		if (name == TikiGolem::MapKeyTikiGolem)
		{
			newEntity = TikiGolem::deserialize(properties);
		}
		if (name == Gecko::MapKeyGecko)
		{
			newEntity = Gecko::deserialize(properties);
		}
		if (name == Alder::MapKeyAlder)
		{
			newEntity = Alder::deserialize(properties);
		}
		if (name == Bonnie::MapKeyBonnie)
		{
			newEntity = Bonnie::deserialize(properties);
		}
		if (name == Brock::MapKeyBrock)
		{
			newEntity = Brock::deserialize(properties);
		}
		if (name == Burch::MapKeyBurch)
		{
			newEntity = Burch::deserialize(properties);
		}
		if (name == Cypress::MapKeyCypress)
		{
			newEntity = Cypress::deserialize(properties);
		}
		if (name == Finch::MapKeyFinch)
		{
			newEntity = Finch::deserialize(properties);
		}
		if (name == Fraya::MapKeyFraya)
		{
			newEntity = Fraya::deserialize(properties);
		}
		if (name == Jasper::MapKeyJasper)
		{
			newEntity = Jasper::deserialize(properties);
		}
		if (name == Mildred::MapKeyMildred)
		{
			newEntity = Mildred::deserialize(properties);
		}
		if (name == Olive::MapKeyOlive)
		{
			newEntity = Olive::deserialize(properties);
		}
		if (name == PrincessDawn::MapKeyPrincessDawn)
		{
			newEntity = PrincessDawn::deserialize(properties);
		}
		if (name == Raka::MapKeyRaka)
		{
			newEntity = Raka::deserialize(properties);
		}
		if (name == Sarude::MapKeySarude)
		{
			newEntity = Sarude::deserialize(properties);
		}
		if (name == Shen::MapKeyShen)
		{
			newEntity = Shen::deserialize(properties);
		}
		if (name == AnubisPup::MapKeyAnubisPup)
		{
			newEntity = AnubisPup::deserialize(properties);
		}
		if (name == AnubisWarrior::MapKeyAnubisWarrior)
		{
			newEntity = AnubisWarrior::deserialize(properties);
		}
		if (name == LionMan::MapKeyLionMan)
		{
			newEntity = LionMan::deserialize(properties);
		}
		if (name == Lioness::MapKeyLioness)
		{
			newEntity = Lioness::deserialize(properties);
		}
		if (name == Medusa::MapKeyMedusa)
		{
			newEntity = Medusa::deserialize(properties);
		}
		if (name == Mermaid::MapKeyMermaid)
		{
			newEntity = Mermaid::deserialize(properties);
		}
		if (name == Minotaur::MapKeyMinotaur)
		{
			newEntity = Minotaur::deserialize(properties);
		}
		if (name == MummyPriest::MapKeyMummyPriest)
		{
			newEntity = MummyPriest::deserialize(properties);
		}
		if (name == MummyWarrior::MapKeyMummyWarrior)
		{
			newEntity = MummyWarrior::deserialize(properties);
		}
		if (name == Osiris::MapKeyOsiris)
		{
			newEntity = Osiris::deserialize(properties);
		}
		if (name == TigerMan::MapKeyTigerMan)
		{
			newEntity = TigerMan::deserialize(properties);
		}
		if (name == Tigress::MapKeyTigress)
		{
			newEntity = Tigress::deserialize(properties);
		}
		if (name == Mummy::MapKeyMummy)
		{
			newEntity = Mummy::deserialize(properties);
		}
		if (name == Ajax::MapKeyAjax)
		{
			newEntity = Ajax::deserialize(properties);
		}
		if (name == Angel::MapKeyAngel)
		{
			newEntity = Angel::deserialize(properties);
		}
		if (name == Aphrodite::MapKeyAphrodite)
		{
			newEntity = Aphrodite::deserialize(properties);
		}
		if (name == Ares::MapKeyAres)
		{
			newEntity = Ares::deserialize(properties);
		}
		if (name == Athena::MapKeyAthena)
		{
			newEntity = Athena::deserialize(properties);
		}
		if (name == Cleopatra::MapKeyCleopatra)
		{
			newEntity = Cleopatra::deserialize(properties);
		}
		if (name == Geryon::MapKeyGeryon)
		{
			newEntity = Geryon::deserialize(properties);
		}
		if (name == Griffin::MapKeyGriffin)
		{
			newEntity = Griffin::deserialize(properties);
		}
		if (name == Hades::MapKeyHades)
		{
			newEntity = Hades::deserialize(properties);
		}
		if (name == Hera::MapKeyHera)
		{
			newEntity = Hera::deserialize(properties);
		}
		if (name == Horus::MapKeyHorus)
		{
			newEntity = Horus::deserialize(properties);
		}
		if (name == Poseidon::MapKeyPoseidon)
		{
			newEntity = Poseidon::deserialize(properties);
		}
		if (name == Thor::MapKeyThor)
		{
			newEntity = Thor::deserialize(properties);
		}
		if (name == Zeus::MapKeyZeus)
		{
			newEntity = Zeus::deserialize(properties);
		}
		if (name == Abomination::MapKeyAbomination)
		{
			newEntity = Abomination::deserialize(properties);
		}
		if (name == Assassin::MapKeyAssassin)
		{
			newEntity = Assassin::deserialize(properties);
		}
		if (name == BoneKnight::MapKeyBoneKnight)
		{
			newEntity = BoneKnight::deserialize(properties);
		}
		if (name == DarkTiger::MapKeyDarkTiger)
		{
			newEntity = DarkTiger::deserialize(properties);
		}
		if (name == EvilEye::MapKeyEvilEye)
		{
			newEntity = EvilEye::deserialize(properties);
		}
		if (name == Exterminator::MapKeyExterminator)
		{
			newEntity = Exterminator::deserialize(properties);
		}
		if (name == Gargoyle::MapKeyGargoyle)
		{
			newEntity = Gargoyle::deserialize(properties);
		}
		if (name == Shade::MapKeyShade)
		{
			newEntity = Shade::deserialize(properties);
		}
		if (name == VoidArcher::MapKeyVoidArcher)
		{
			newEntity = VoidArcher::deserialize(properties);
		}
		if (name == VoidDemon::MapKeyVoidDemon)
		{
			newEntity = VoidDemon::deserialize(properties);
		}
		if (name == Warlock::MapKeyWarlock)
		{
			newEntity = Warlock::deserialize(properties);
		}
		if (name == Professor::MapKeyProfessor)
		{
			newEntity = Professor::deserialize(properties);
		}
		if (name == Robot::MapKeyRobot)
		{
			newEntity = Robot::deserialize(properties);
		}
		if (name == Atreus::MapKeyAtreus)
		{
			newEntity = Atreus::deserialize(properties);
		}
		if (name == Bancroft::MapKeyBancroft)
		{
			newEntity = Bancroft::deserialize(properties);
		}
		if (name == Godiva::MapKeyGodiva)
		{
			newEntity = Godiva::deserialize(properties);
		}
		if (name == Illia::MapKeyIllia)
		{
			newEntity = Illia::deserialize(properties);
		}
		if (name == Leon::MapKeyLeon)
		{
			newEntity = Leon::deserialize(properties);
		}
		if (name == Mara::MapKeyMara)
		{
			newEntity = Mara::deserialize(properties);
		}
		if (name == Marcel::MapKeyMarcel)
		{
			newEntity = Marcel::deserialize(properties);
		}
		if (name == Piper::MapKeyPiper)
		{
			newEntity = Piper::deserialize(properties);
		}
		if (name == QueenElise::MapKeyQueenElise)
		{
			newEntity = QueenElise::deserialize(properties);
		}
		if (name == Radon::MapKeyRadon)
		{
			newEntity = Radon::deserialize(properties);
		}
		if (name == Ralston::MapKeyRalston)
		{
			newEntity = Ralston::deserialize(properties);
		}
		if (name == Xenon::MapKeyXenon)
		{
			newEntity = Xenon::deserialize(properties);
		}
		if (name == Ysara::MapKeyYsara)
		{
			newEntity = Ysara::deserialize(properties);
		}

		////O////O////O////O////O////O////O/
		// END: THIS CODE IS GENERATED    //
		////////////////////////////////////

		if (newEntity != nullptr)
		{
			// Fire an event indicating successful deserialization
			args->onDeserializeCallback(DeserializationEvents::ObjectDeserializationArgs(newEntity));
		}
	}
}
