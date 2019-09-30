#include "SGH_Rect.h"
#include "SGH_GameObjectManager.h"

SGH_Rect::SGH_Rect() : SGH_GameObject()
{
	rectangle = new sf::RectangleShape(sf::Vector2f(100,100));
	this->transform = rectangle;
}

SGH_Rect::SGH_Rect(const SGH_Rect& _ref) : SGH_GameObject(*this)
{
	rectangle = _ref.rectangle;
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

void SGH_Rect::CenterPivot()
{
	float x = this->rectangle->getSize().x / 2;
	float y = this->rectangle->getSize().y / 2;
	this->SetOrigin(sf::Vector2f(x, y));
}
