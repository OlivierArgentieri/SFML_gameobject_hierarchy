#include "SGH_Runtime.h"
#include "SGH_Rect.h"
#include "SGH_Circle.h"
#include "SGH_Slider.h"
#include <iostream>
#include "SGH_PongBall.h"

void SGH_Runtime::Run(sf::RenderWindow& _w)
{
	sf::Clock _clock;
	sf::Time _deltaTime = sf::Time::Zero;
	while (_w.isOpen())
	{
		_deltaTime += _clock.restart();
		while (_deltaTime > frameRate)
		{
			_deltaTime -= frameRate;
			Event(_w);
			Render(_w);
		}
	}
}

SGH_Runtime::SGH_Runtime() : renderWindow(sf::VideoMode(1280, 720), "window", sf::Style::Close)
{
	gameManager = new SGH_GameObjectManager();
	SGH_Slider* slider = new SGH_Slider(10,100);
	slider->CenterPivot();
	slider->SetPosition(renderWindow);
	gameManager->AddGameObject(slider);

	auto ball = new SGH_PongBall(10.0f);
	ball->SetPosition(10, 10);
	ball->CenterPivot();
	
	gameManager->AddGameObject(ball);
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
			_w.close();
		gameManager->CatchAllEvents(_w, _events);
	}
}