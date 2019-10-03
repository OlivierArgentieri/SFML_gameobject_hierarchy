#include "SGH_Runtime.h"
#include "SGH_Rect.h"
#include "SGH_Circle.h"
#include "SGH_Slider.h"
#include <iostream>
#include "SGH_PongBall.h"
#include "SGH_Player.h"
#include "SGH_InputManager.h"
#include "SGH_GameManager.h"


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
	
	playerManager = new SGH_PlayerManager();
	SGH_Slider* slider = new SGH_Slider(10,100);
	slider->CenterPivot();
	slider->SetPosition(20, renderWindow.getSize().y / 2);
	SGH_GameObjectManager::GetInstance()->AddGameObject(slider);

	SGH_Slider* slider2 = new SGH_Slider(10, 100);
	slider2->CenterPivot();
	slider2->SetPosition(1260, renderWindow.getSize().y / 2);
	SGH_GameObjectManager::GetInstance()->AddGameObject(slider2);

	auto ball = new SGH_PongBall(10.0f);
	ball->SetPosition(10, 10);
	ball->CenterPivot();

	slider->AddPongBalls(ball);
	slider2->AddPongBalls(ball);
	SGH_GameObjectManager::GetInstance()->AddGameObject(ball);


	SGH_Player* player = new SGH_Player(slider);
	player->SetUpKey(SGH_InputManager::GetInputUpPlayerOne());
	player->SetDownKey(SGH_InputManager::GetInputDownPlayerOne());
	playerManager->AddPlayer(player);

	SGH_Player* player2 = new SGH_Player(slider2);
	player2->SetUpKey(SGH_InputManager::GetInputUpPlayerTwo());
	player2->SetDownKey(SGH_InputManager::GetInputDownPlayerTwo());
	playerManager->AddPlayer(player2);


	SGH_GameManager::GetInstance()->AddPlayer(player);
	SGH_GameManager::GetInstance()->AddPlayer(player2);
	SGH_GameManager::GetInstance()->AddPongBall(ball);
	SGH_GameManager::GetInstance()->AddSlider(slider);
	SGH_GameManager::GetInstance()->AddSlider(slider2);
	Run(renderWindow);
}

SGH_Runtime::~SGH_Runtime()
{
	delete playerManager;
}

void SGH_Runtime::Render(sf::RenderWindow& _w)
{
	_w.clear();
	SGH_GameObjectManager::GetInstance()->UpdateAll(_w);
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
		playerManager->TriggerAllPlayer(_events, _w);
	}
}