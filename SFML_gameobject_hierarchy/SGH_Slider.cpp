#include "SGH_Slider.h"

bool SGH_Slider::TriggerBoundary(sf::RenderWindow& _w)
{
	if (!shape)
		return false;
	if (shape->GetPosition().x - (shape->GetScale().x / 2) == 0)
		return true;
	if (shape->GetPosition().x + (shape->GetScale().x / 2) == _w.getSize().x)
		return true;
	return true;
}

SGH_Slider::SGH_Slider(SGH_GameObject* _go)
{
	shape = _go;
}

SGH_Slider::~SGH_Slider()
{
	delete 	shape;
}

void SGH_Slider::Update(sf::RenderWindow& _w)
{
	if (!shape)
		return;

	shape->Update(_w);
}

void SGH_Slider::SetPosition(sf::Vector2f _pos)
{
	if (shape)shape->SetPosition(_pos);
}

void SGH_Slider::SetPosition(sf::RenderWindow& _w)
{
	if (shape)
	{
		shape->SetPosition(_w.getSize().x / 2, _w.getSize().y-20);
	}
}

sf::Vector2f SGH_Slider::GetPosition()
{
	if (!shape) return sf::Vector2f();
		return shape->GetPosition();
	
}

void SGH_Slider::CatchEvent(sf::RenderWindow& _w, sf::Event _events)
{
	if (_events.type == sf::Event::KeyPressed && _events.key.code == sf::Keyboard::Right /*&& TriggerBoundary(_w)*/)
	{
		SetPosition(GetPosition() + sf::Vector2f(10,0));
	}

	if (_events.type == sf::Event::KeyPressed && _events.key.code == sf::Keyboard::Left /*&& TriggerBoundary(_w)*/)
	{
		SetPosition(GetPosition() - sf::Vector2f(10, 0));
	}
}
