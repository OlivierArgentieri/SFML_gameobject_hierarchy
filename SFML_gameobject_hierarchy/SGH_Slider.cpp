#include "SGH_Slider.h"

bool SGH_Slider::TriggerBoundary(sf::RenderWindow& _w)
{

	return true;
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
		shape->setPosition(_w.getSize().x / 2, _w.getSize().y - 20);
	}
}

sf::Vector2f SGH_Slider::GetPosition()
{
	return shape->getPosition();

}

void SGH_Slider::CatchEvent(sf::RenderWindow& _w, sf::Event _events)
{
	if (_events.type == sf::Event::KeyPressed && _events.key.code == sf::Keyboard::Right /*&& TriggerBoundary(_w)*/)
	{
		SetPosition(GetPosition() + sf::Vector2f(10, 0));
	}

	if (_events.type == sf::Event::KeyPressed && _events.key.code == sf::Keyboard::Left /*&& TriggerBoundary(_w)*/)
	{
		SetPosition(GetPosition() - sf::Vector2f(10, 0));
	}
}
