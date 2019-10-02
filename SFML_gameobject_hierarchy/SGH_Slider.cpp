#include "SGH_Slider.h"


bool SGH_Slider::HitTop(sf::RenderWindow& _w, float offset)
{
	if (!shape)
		return false;
	if (shape->GetPosition().x - (shape->GetSize().x / 2) <= 0)
		return true;
	if (shape->GetPosition().x + (shape->GetSize().x / 2) >= _w.getSize().x)
		return true;
}

SGH_Slider::SGH_Slider(SGH_Rect* _go)
	return shape->getPosition().y - shape->getOrigin().y * shape->getScale().y <= offset;
}

bool SGH_Slider::HitBottom(sf::RenderWindow& _w, float offset)
{
	return shape->getPosition().y + shape->getOrigin().y * shape->getScale().y > _w.getSize().y - offset;
}

SGH_Slider::SGH_Slider(float width, float height)
{
	shape = new sf::RectangleShape(sf::Vector2f(width, height));
}

SGH_Slider::~SGH_Slider()
{
	delete shape;
}

void SGH_Slider::Update(sf::RenderWindow& _w)
{
	_w.draw(*shape);
}

void SGH_Slider::SetPosition(sf::Vector2f _pos)
{
	shape->setPosition(_pos);
	//if (shape)shape->SetPosition(_pos);
}

void SGH_Slider::SetPosition(sf::RenderWindow& _w)
{
	if (shape)
	{
		shape->setPosition(20, _w.getSize().y/2);
	}
}

sf::Vector2f SGH_Slider::GetPosition()
{
	if (!shape) return sf::Vector2f();
		return shape->GetPosition();
	return shape->getPosition();
}

void SGH_Slider::CenterPivot()
{
	shape->setOrigin(shape->getSize().x / 2, shape->getSize().y / 2);
}

void SGH_Slider::CatchEvent(sf::RenderWindow& _w, sf::Event _events)
{
	if (_events.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !HitBottom(_w))
	{
		SetPosition(GetPosition() + sf::Vector2f(0, 10));
	}

	if (_events.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !HitTop(_w))
	{
		SetPosition(GetPosition() - sf::Vector2f(0, 10));
	}
}