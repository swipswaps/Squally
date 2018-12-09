#include "SerializableLayer.h"

#include <tinyxml2/tinyxml2.h>

#include "Engine/Utils/GameUtils.h"

using namespace cocos2d;

const std::string SerializableLayer::KeyType = "type";
const std::string SerializableLayer::MapKeyPropertyName = "name";
const std::string SerializableLayer::MapKeyPropertyValue = "value";
const std::string SerializableLayer::MapKeyPropertyDepth = "depth";
const std::string SerializableLayer::MapKeyPropertyIgnoreHackermode = "ignore_hackermode";


SerializableLayer* SerializableLayer::create(ValueMap* initProperties, std::string name,
		const std::vector<SerializableObject*>& objects)
{
	SerializableLayer* instance = new SerializableLayer(initProperties, name, objects);

	instance->autorelease();

	return instance;
}

SerializableLayer::SerializableLayer()
{
	if (this->properties != nullptr)
	{
		delete(this->properties);
	}
}

SerializableLayer::SerializableLayer(ValueMap* initProperties, std::string name) : SerializableLayer(initProperties, name, std::vector<SerializableObject*>())
{
}

SerializableLayer::SerializableLayer(ValueMap* initProperties, std::string name,
		const std::vector<SerializableObject*>& objects)
{
	this->layerName = name;
	this->serializableObjects = objects;
	this->properties = new ValueMap(*initProperties);

	if (GameUtils::keyExists(this->properties, SerializableLayer::MapKeyPropertyDepth))
	{
		this->setPositionZ(this->properties->at(SerializableLayer::MapKeyPropertyDepth).asFloat());
	}

	for (auto it = objects.begin(); it != objects.end(); it++)
	{
		this->addChild(*it);
	}
}

SerializableLayer::~SerializableLayer()
{
}

void SerializableLayer::serialize(tinyxml2::XMLDocument* documentRoot, tinyxml2::XMLElement* parentElement, Size mapUnitSize, Size mapTileSize)
{
	tinyxml2::XMLElement* objectGroupElement = documentRoot->NewElement("objectgroup");
	objectGroupElement->SetAttribute(SerializableLayer::MapKeyPropertyName.c_str(), this->layerName.c_str());

	if (this->properties != nullptr && this->properties->size() > 0)
	{
		tinyxml2::XMLElement* propertiesElement = documentRoot->NewElement("properties");

		for (auto it = this->properties->begin(); it != this->properties->end(); it++)
		{
			tinyxml2::XMLElement* propertyElement = documentRoot->NewElement("property");

			propertyElement->SetAttribute(SerializableLayer::MapKeyPropertyName.c_str(), it->first.c_str());
			propertyElement->SetAttribute(SerializableLayer::MapKeyPropertyValue.c_str(), it->second.asString().c_str());

			propertiesElement->InsertEndChild(propertyElement);
		}

		objectGroupElement->InsertEndChild(propertiesElement);
	}

	for (auto it = this->serializableObjects.begin(); it != this->serializableObjects.end(); it++)
	{
		(*it)->serialize(documentRoot, objectGroupElement, mapUnitSize, mapTileSize);
	}

	parentElement->LinkEndChild(objectGroupElement);
}

bool SerializableLayer::isHackerModeIgnored()
{
	if (GameUtils::keyExists(this->properties, SerializableLayer::MapKeyPropertyIgnoreHackermode))
	{
		return this->properties->at(SerializableLayer::MapKeyPropertyIgnoreHackermode).asBool();
	}
	
	return false;
}
