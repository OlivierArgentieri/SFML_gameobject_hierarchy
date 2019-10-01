#include "SGH_Rect.h"
#include "SGH_GameObjectManager.h"


SGH_Rect::SGH_Rect(sf::Vector2f _size)
{
	rectangle = new sf::RectangleShape(_size);
	transform = rectangle;
}

SGH_Rect::SGH_Rect(const SGH_Rect& _ref)
{
	rectangle = _ref.rectangle;
	transform = _ref.transform;
}

SGH_Rect::~SGH_Rect()
{
	delete rectangle;
}

void SGH_Rect::Update(sf::RenderWindow& _w)
{
	if (rectangle == nullptr)
		return;
	
	_w.draw(*rectangle);
}

void SGH_Rect::SetSize(sf::Vector2f _size)
{
	rectangle->setSize(_size);
}

sf::Vector2f SGH_Rect::GetSize()
{
	return rectangle->getSize();
}

void SGH_Rect::CenterPivot()
{
	float x = this->rectangle->getSize().x / 2;
	float y = this->rectangle->getSize().y / 2;
	this->SetOrigin(sf::Vector2f(x, y));
}
