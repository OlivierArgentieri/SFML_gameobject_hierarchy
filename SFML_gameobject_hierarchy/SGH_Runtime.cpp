#include "SGH_Runtime.h"


void SGH_Runtime::Run()
{
}

SGH_Runtime::SGH_Runtime() : renderWindow(sf::VideoMode(800, 400), "window", sf::Style::Close)
{
	gameManager = new SGH_GameObjectManager();
}

SGH_Runtime::~SGH_Runtime()
{
	delete gameManager;
}

void SGH_Runtime::Render(sf::RenderWindow& _w)
{
	_w.clear();
}

void SGH_Runtime::Event(sf::RenderWindow& _w)
{
	sf::Event _events;

	while (_w.pollEvent(_events))
	{
		bool exit = _events.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);

		if (exit)
		{
			_w.close();
		}
	}

}