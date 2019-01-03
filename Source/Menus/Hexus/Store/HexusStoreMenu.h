#pragma once
#include <map>
#include <tuple>
#include <vector>

#include "Engine/GlobalScene.h"

namespace cocos2d
{
	class LayerColor;
	class ParticleSystem;
	class Sprite;
}

class Card;
class CardData;
class ConstantString;
class LocalizedLabel;
class MenuCard;
class MenuSprite;
class MenuSprite;
class ScrollPane;
class Shopkeeper;
class SmartAnimationNode;
class TextMenuSprite;

class HexusStoreMenu : public GlobalScene
{
public:
	static void registerGlobalScene();

protected:
	HexusStoreMenu();
	~HexusStoreMenu();

private:
	typedef GlobalScene super;
	void onEnter() override;
	void initializePositions() override;
	void initializeListeners() override;
	std::tuple<MenuSprite*, int> constructLootBoxButton(std::string lootBoxAnimations, int price, std::map<CardData*, float> cardChoices);
	std::tuple<MenuSprite*, MenuCard*, int> constructCard(CardData* cardData);
	void onLootBoxTabClick();
	void onBinaryTabClick();
	void onDecimalTabClick();
	void onHexTabClick();
	void onSpecialTabClick();
	void updateAllCardLimits();
	void updateCardLimitText(LocalizedLabel* label, ConstantString* countString, ConstantString* limitString, CardData* cardData);
	void updateGoldText();
	void hideMenus();
	void onLootBoxClick(MenuSprite* sprite, int price, std::map<CardData*, float> cardChoices, SmartAnimationNode* animationNode);
	void onCardClick(MenuSprite* card, CardData* cardData, int price, LocalizedLabel* label, ConstantString* countString, ConstantString* limitString);
	void onBackClick(MenuSprite* menuSprite);
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void onLootBoxReturnButtonClick(int price, std::vector<Card*> chosenCards);
	static CardData* chooseRandomCard(std::map<CardData*, float> cardChoices);
	static std::map<CardData*, float> getCardsTier1();
	static std::map<CardData*, float> getCardsTier2();
	static std::map<CardData*, float> getCardsTier3();
	static std::map<CardData*, float> getCardsTier4();
	static std::map<CardData*, float> getCardsTier5();
	static std::map<CardData*, float> getCardsTier6();
	static std::map<CardData*, float> getCardsTier7();
	static std::map<CardData*, float> getCardsTier8();
	static std::map<CardData*, float> getCardsTier9();

	cocos2d::ParticleSystem* dustParticles;
	cocos2d::Sprite* storeBack;
	Shopkeeper* shopKeeper;
	cocos2d::Sprite* storeFront;
	cocos2d::Node* storeNode;
	cocos2d::Sprite* storeMenu;
	cocos2d::Sprite* goldPanel;
	cocos2d::Sprite* goldIcon;
	ConstantString* goldString;
	LocalizedLabel* goldLabel;
	cocos2d::Node* lootboxesNode;
	ScrollPane* binaryCardsScrollPane;
	ScrollPane* decimalCardsScrollPane;
	ScrollPane* hexCardsScrollPane;
	ScrollPane* specialCardsScrollPane;
	MenuSprite* lootBoxButton;
	MenuSprite* binaryButton;
	MenuSprite* decimalButton;
	MenuSprite* hexButton;
	MenuSprite* specialButton;
	TextMenuSprite* backButton;
	cocos2d::LayerColor* lootBoxRewardBackground;
	MenuSprite* lootBoxReturnButton;
	cocos2d::Node* chosenCardsNode;

	std::vector<std::tuple<MenuSprite*, int>> lootBoxes;
	std::vector<std::tuple<MenuSprite*, MenuCard*, int>> binaryCards;
	std::vector<std::tuple<MenuSprite*, MenuCard*, int>> decimalCards;
	std::vector<std::tuple<MenuSprite*, MenuCard*, int>> hexCards;
	std::vector<std::tuple<MenuSprite*, MenuCard*, int>> specialCards;
	std::map<MenuCard*, std::tuple<ConstantString*, ConstantString*, LocalizedLabel*>> limitLabels;

	static HexusStoreMenu* instance;
	static const float LootBoxScale;
};