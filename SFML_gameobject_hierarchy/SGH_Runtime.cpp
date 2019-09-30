#include "SGH_Runtime.h"
#include "SGH_Rect.h"


void SGH_Runtime::Run(sf::RenderWindow& _w)
{
	while (_w.isOpen())
	{
		Event(_w);
		Render(_w);
	}
}

SGH_Runtime::SGH_Runtime() : renderWindow(sf::VideoMode(800, 400), "window", sf::Style::Close)
{
	gameManager = new SGH_GameObjectManager();
	gameManager->AddGameObject(new SGH_Rect());
	Run(renderWindow);
}

SGH_Runtime::~SGH_Runtime()
{
	delete gameManager;
}

void SGH_Runtime::Render(sf::RenderWindow& _w)
{
	_w.clear();
	gameManager->UpdateAll(_w);
	_w.display();
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