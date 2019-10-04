#include "SGH_GameObject.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "SGH_Behaviour.h"

bool SGH_GameObject::IsPause()
{
	return isPause;
}

void SGH_GameObject::SetPause()
{
	isPause = !isPause;
}

void SGH_GameObject::SetPause(bool _pause)
{
	isPause = _pause;
}

void SGH_GameObject::SetVisibility(bool _visibility)
{
	isVisible = _visibility;
}

bool SGH_GameObject::IsVisible()
{
	return isVisible;
}

sf::Rect<int> SGH_GameObject::GetIntRect()
{
	return sf::IntRect();
}

sf::Rect<float> SGH_GameObject::GetFloatRect()
{
	return sf::FloatRect();
}

float SGH_GameObject::GetFloatSize()
{
	return 0;
}

sf::Vector2f SGH_GameObject::GetVector2fSize()
{
	return sf::Vector2f();
}

void SGH_GameObject::SetColor(sf::Color _color)
{
	
}


void SGH_GameObject::ClearBehaviours()
{
	for (unsigned int i = 0; i < behaviours.size(); ++i)
	{
		delete behaviours[i];
	}
}

SGH_GameObject::SGH_GameObject()
{
	isPause = false;
	transform = nullptr;
}

SGH_GameObject::~SGH_GameObject()
{
	delete transform;
	ClearBehaviours();
}

SGH_GameObject::SGH_GameObject(sf::Transformable* _tranformable) : SGH_GameObject()
{
	transform = _tranformable;
}

void SGH_GameObject::Update(sf::RenderWindow& _w)
{
	// todo throw new exception 
}

void SGH_GameObject::ApplyBehaviour(sf::RenderWindow& _w)
{
	for (unsigned int i = 0; i < behaviours.size(); ++i)
	{
		behaviours[i]->TriggerBehaviour(_w);
	}
}

void SGH_GameObject::CatchEvent(sf::RenderWindow& _w, sf::Event _events)
{
}

sf::Vector2f SGH_GameObject::GetPosition()
{
	return transform->getPosition();
}

void SGH_GameObject::SetPosition(float _x, float _y)
{
	SetPosition(sf::Vector2f(_x, _y));
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
