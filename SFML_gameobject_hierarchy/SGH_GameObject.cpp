#include "SGH_GameObject.h"
#include <SFML/Graphics/RenderWindow.hpp>

SGH_GameObject::SGH_GameObject()
{
	transform = nullptr;
}

SGH_GameObject::~SGH_GameObject()
{
	delete transform;
}

void SGH_GameObject::Update(sf::RenderWindow& _w)
{
	// todo throw new exception 
}

void SGH_GameObject::ApplyBehaviour()
{
	for (int i = 0; i < behaviours.size()-1; ++i)
	{
		behaviours[i].TriggerBehaviour();
	}
}

sf::Vector2f SGH_GameObject::GetPosition()
{
	return transform->getPosition();
}

void SGH_GameObject::SetPosition(float _width, float _height)
{
	SetPosition(sf::Vector2f(_width, _height));
}

void SGH_GameObject::SetPosition(sf::Vector2f _newPosition)
{
	transform->setPosition(_newPosition);
}

float SGH_GameObject::GetRotation()
{
	return transform->getRotation();
}

void SGH_GameObject::SetRotation(float _newRotation)
{
	transform->setRotation(_newRotation);
}

sf::Vector2f SGH_GameObject::GetScale()
{
	return transform->getScale();
}

void SGH_GameObject::SetScale(sf::Vector2f _newScale)
{
	transform->setScale(_newScale);
}

sf::Vector2f SGH_GameObject::GetOrigin()
{
	return transform->getOrigin();
}

void SGH_GameObject::SetOrigin(sf::Vector2f _newOrigin)
{
	transform->setOrigin(_newOrigin);
}

void SGH_GameObject::CenterPivot()
{
	// todo throw ..
}
