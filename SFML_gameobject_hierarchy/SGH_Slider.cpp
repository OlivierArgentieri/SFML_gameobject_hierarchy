#include "SGH_Slider.h"

SGH_Slider::SGH_Slider()
{
	//Test :
	rectangle = new sf::RectangleShape(sf::Vector2f(100, 10));
	transform = rectangle;
}

SGH_Slider::~SGH_Slider()
{
	delete rectangle;
}

void SGH_Slider::Update(sf::RenderWindow& _w)
{
	if (rectangle == nullptr)
		return;

	_w.draw(*rectangle);
}

void SGH_Slider::CatchEvent(sf::RenderWindow& _w, sf::Event _events)
{
	if (_events.type == sf::Event::KeyPressed && _events.key.code == sf::Keyboard::Right)
	{
		//call SGH_MoveBehaviour

		//TEST MOVE : 
		//SetPosition(GetPosition() + sf::Vector2f(10,0));
	}

	if (_events.type == sf::Event::KeyPressed && _events.key.code == sf::Keyboard::Left)
	{
		//call SGH_MoveBehaviour
		//TEST MOVE : 
		//SetPosition(GetPosition() - sf::Vector2f(10, 0));
	}
}
