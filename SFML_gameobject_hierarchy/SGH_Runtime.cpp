#include "SGH_Runtime.h"
#include "SGH_Rect.h"
#include "SGH_Slider.h"
#include <iostream>
#include "SGH_PongBall.h"
#include "SGH_Player.h"
#include "SGH_InputManager.h"
#include "SGH_GameManager.h"
#include "SGH_Bric.h"


void SGH_Runtime::Run(sf::RenderWindow& _w)
{
	sf::Clock _clock;
	sf::Time _deltaTime = sf::Time::Zero;
	
	while (_w.isOpen())
	{
		Event(_w);
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

	//SGH_GameManager::GetInstance()->Bric(renderWindow);
	
	Run(renderWindow);
}

SGH_Runtime::~SGH_Runtime()
{
}

void SGH_Runtime::Render(sf::RenderWindow& _w)
{
	_w.clear();
	SGH_GameObjectManager::GetInstance()->UpdateAll(_w);
	SGH_GameManager::GetInstance()->Update(_w);
	SGH_GameManager::GetInstance()->GameOver(_w);
	_w.display();
}

void SGH_Runtime::Event(sf::RenderWindow& _w)
{
	sf::Event _events;

	while (_w.pollEvent(_events))
	{
		bool exit = _events.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
		bool pause = _events.type == sf::Event::KeyPressed && _events.key.code == sf::Keyboard::P;

		if (pause)
			SGH_GameObjectManager::GetInstance()->SetPauseAll();
		if (exit)
			_w.close();
		SGH_PlayerManager::GetInstance()->TriggerAllPlayer(_events, _w);
	}
}