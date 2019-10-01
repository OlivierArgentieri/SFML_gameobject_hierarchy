#include "SGH_Slider.h"

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

sf::Vector2f SGH_Slider::GetPosition()
{
	if (!shape) return sf::Vector2f();
		return shape->GetPosition();
	
}

void SGH_Slider::CatchEvent(sf::RenderWindow& _w, sf::Event _events)
{
	if (_events.type == sf::Event::KeyPressed && _events.key.code == sf::Keyboard::Right)
	{
		//call SGH_MoveBehaviour

		//TEST MOVE : 
		SetPosition(GetPosition() + sf::Vector2f(10,0));
	}

	if (_events.type == sf::Event::KeyPressed && _events.key.code == sf::Keyboard::Left)
	{
		//call SGH_MoveBehaviour
		//TEST MOVE : 
		SetPosition(GetPosition() - sf::Vector2f(10, 0));
	}
}
