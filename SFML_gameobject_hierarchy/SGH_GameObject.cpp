#include "SGH_GameObject.h"

SGH_GameObject::SGH_GameObject()
{
	transform = nullptr;
}

SGH_GameObject::SGH_GameObject(const SGH_GameObject& _ref)
{
	transform = _ref.transform;
}

SGH_GameObject::SGH_GameObject(sf::Transformable& _refTransform)
{
	transform = &_refTransform;
}

SGH_GameObject::~SGH_GameObject()
{
	delete transform;
}

void SGH_GameObject::Update()
{
	// todo throw new exception 
}

sf::Vector2f SGH_GameObject::GetPosition()
{
	return transform->getPosition();
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
