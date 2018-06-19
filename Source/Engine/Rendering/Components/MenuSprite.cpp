#include "MenuSprite.h"

MenuSprite* MenuSprite::create(std::string spriteNormal, std::string spriteSelectedResource, std::string spriteClickedResource)
{
	return MenuSprite::create(Sprite::create(spriteNormal), Sprite::create(spriteSelectedResource), Sprite::create(spriteClickedResource));
}

MenuSprite* MenuSprite::create(Node* spriteNormal, std::string spriteSelectedResource, std::string spriteClickedResource)
{
	MenuSprite* menuSprite = new MenuSprite(spriteNormal, Sprite::create(spriteSelectedResource), Sprite::create(spriteClickedResource));

	menuSprite->autorelease();

	return menuSprite;
}

MenuSprite* MenuSprite::create(Node* nodeNormal, Node* nodeSelected, Node* nodeClicked)
{
	MenuSprite* menuSprite = new MenuSprite(nodeNormal, nodeSelected, nodeClicked);

	menuSprite->autorelease();

	return menuSprite;
}

MenuSprite::MenuSprite(Node* nodeNormal, Node* nodeSelected, Node* nodeClicked)
{
	this->mouseClickEvent = nullptr;
	this->mouseDownEvent = nullptr;
	this->mouseDragEvent = nullptr;
	this->mouseOverEvent = nullptr;
	this->interactionEnabled = true;

	this->clickSound = Resources::Sounds_ButtonClick1;
	this->mouseOverSound = "";

	this->sprite = nodeNormal;
	this->spriteSelected = nodeSelected;
	this->spriteClicked = nodeClicked;

	this->offsetCorrection = Vec2::ZERO;

	this->setContentSize(this->sprite->getContentSize());

	this->addChild(this->sprite);
	this->addChild(this->spriteClicked);
	this->addChild(this->spriteSelected);
}

MenuSprite::~MenuSprite()
{
}

void MenuSprite::onEnter()
{
	Node::onEnter();

	this->isClickInit = false;
	this->isClicked = false;

	this->setCascadeOpacityEnabled(true);
	this->spriteClicked->setVisible(false);
	this->spriteSelected->setVisible(false);

	this->initializeListeners();
	this->scheduleUpdate();
}

void MenuSprite::update(float dt)
{
	Node::update(dt);

	this->spriteClicked->setPosition(this->sprite->getPosition());
	this->spriteSelected->setPosition(this->sprite->getPosition());
}

void MenuSprite::disableInteraction()
{
	this->interactionEnabled = false;

	// Restore normal sprite
	this->sprite->setVisible(true);
	this->spriteClicked->setVisible(false);
	this->spriteSelected->setVisible(false);
}

void MenuSprite::enableInteraction()
{
	this->interactionEnabled = true;
}

void MenuSprite::setContentScale(float scale)
{
	this->setContentSize(this->sprite->getContentSize() * scale);
}

void MenuSprite::setOffsetCorrection(Vec2 newOffsetCorrection)
{
	this->offsetCorrection = newOffsetCorrection;
}

void MenuSprite::setClickCallback(std::function<void(MenuSprite*, EventMouse* args)> onMouseClick)
{
	this->mouseClickEvent = onMouseClick;
}

void MenuSprite::setMouseDownCallback(std::function<void(MenuSprite*, EventMouse* args)> onMouseDown)
{
	this->mouseDownEvent = onMouseDown;
}

void MenuSprite::setMouseDragCallback(std::function<void(MenuSprite*, EventMouse* args)> onMouseDrag)
{
	this->mouseDragEvent = onMouseDrag;
}

void MenuSprite::setMouseOverCallback(std::function<void(MenuSprite*, EventMouse* args)> onMouseOver)
{
	this->mouseOverEvent = onMouseOver;
}

void MenuSprite::setMouseOverSound(std::string soundResource)
{
	this->mouseOverSound = soundResource;
}

void MenuSprite::setClickSound(std::string soundResource)
{
	this->clickSound = soundResource;
}

void MenuSprite::initializeListeners()
{
	EventListenerMouse* mouseListener = EventListenerMouse::create();
	EventListenerCustom* customListener = EventListenerCustom::create(MouseEvents::MouseMoveEvent, CC_CALLBACK_1(MenuSprite::onMouseSpriteMove, this));

	mouseListener->onMouseUp = CC_CALLBACK_1(MenuSprite::onMouseUp, this);
	mouseListener->onMouseDown = CC_CALLBACK_1(MenuSprite::onMouseDown, this);

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(customListener, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener, this);
}

bool MenuSprite::intersects(Vec2 mousePos)
{
	if (dynamic_cast<const LayerColor*>(this->sprite) != nullptr)
	{
		return GameUtils::intersectsV2(this, Vec2(mousePos.x, mousePos.y) + this->offsetCorrection);
	}

	return GameUtils::intersects(this, Vec2(mousePos.x, mousePos.y) + this->offsetCorrection);
}

void MenuSprite::onMouseSpriteMove(EventCustom* event)
{
	MouseEvents::MouseEventArgs* args = static_cast<MouseEvents::MouseEventArgs*>(event->getUserData());

	if (!this->interactionEnabled)
	{
		return;
	}

	if (GameUtils::isVisible(this))
	{
		// Mouse drag callback
		if (args->innerEvent->getMouseButton() == EventMouse::MouseButton::BUTTON_LEFT)
		{
			if (this->isClicked && this->mouseDragEvent != nullptr)
			{
				this->mouseDragEvent(this, args->innerEvent);
			}
		}
		else
		{
			this->isClickInit = false;
			this->isClicked = false;
		}

		if (!args->handled && this->intersects(Vec2(args->mouseX, args->mouseY)))
		{
			MouseEvents::TriggerCanClickEvent(MouseEvents::MouseCanClickEventArgs(true));

			if (args->innerEvent->getMouseButton() == EventMouse::MouseButton::BUTTON_LEFT)
			{
				// Show mouse click sprite
				this->sprite->setVisible(false);
				this->spriteClicked->setVisible(true);
				this->spriteSelected->setVisible(false);

				// Mouse down callback
				if (this->mouseDownEvent != nullptr)
				{
					this->mouseDownEvent(this, args->innerEvent);
				}
			}
			else
			{
				// Show mouse hover sprite
				this->sprite->setVisible(false);
				this->spriteClicked->setVisible(false);
				this->spriteSelected->setVisible(true);
			}

			// Mouse over callback
			if (this->mouseOverEvent != nullptr)
			{
				this->mouseOverEvent(this, args->innerEvent);
			}

			// For the use cases of this game, I see no case in which we want to mouse over two things at once
			// If this changes, we will have to make this line optional/configurable
			args->handled = true;
		}
		else
		{
			// Show normal sprite
			this->sprite->setVisible(true);
			this->spriteClicked->setVisible(false);
			this->spriteSelected->setVisible(false);
		}
	}
}

void MenuSprite::onMouseDown(EventMouse* event)
{
	if (!this->interactionEnabled)
	{
		return;
	}

	if (GameUtils::isVisible(this))
	{
		if (this->intersects(Vec2(event->getCursorX(), event->getCursorY())))
		{
			if (event->getMouseButton() == EventMouse::MouseButton::BUTTON_LEFT)
			{
				if (!this->isClickInit)
				{
					this->isClicked = true;
				}
			}
		}

		if (event->getMouseButton() == EventMouse::MouseButton::BUTTON_LEFT)
		{
			this->isClickInit = true;
		}
	}
}

void MenuSprite::onMouseUp(EventMouse* event)
{
	if (!this->interactionEnabled)
	{
		return;
	}

	if (GameUtils::isVisible(this) && this->intersects(Vec2(event->getCursorX(), event->getCursorY())))
	{
		if (this->mouseClickEvent != nullptr)
		{
			if (this->isClicked)
			{
				// Mouse click callback
				this->mouseClickEvent(this, event);

				// Play click sound
				if (this->clickSound.length() > 0)
				{
					SoundManager::playSoundResource(this->clickSound);
				}

				// Show mouse hover sprite
				this->sprite->setVisible(false);
				this->spriteClicked->setVisible(false);
				this->spriteSelected->setVisible(true);

				event->stopPropagation();
			}
		}

		if (event->getMouseButton() == EventMouse::MouseButton::BUTTON_LEFT)
		{
			this->isClickInit = false;
			this->isClicked = false;
		}
	}
}