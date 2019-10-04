#include "SGH_GameManager.h"
#include "SGH_GameObjectManager.h"
#include "SGH_InputManager.h"
#include "SGH_PlayerManager.h"
#include "SGH_Bric.h"
#include "SGH_Menu.h"

SGH_GameManager* SGH_GameManager::instance;

SGH_GameManager::SGH_GameManager()
{
	menu = new SGH_Menu();
}

void SGH_GameManager::PongOnePlayer(sf::RenderWindow& _w)
{
	isGameselected = true;
	SGH_Slider* slider = new SGH_Slider(10, 100);
	slider->CenterPivot();
	slider->SetPosition(20, _w.getSize().y / 2);
	SGH_GameObjectManager::GetInstance()->AddGameObject(slider);

	SGH_PongBall* ball = new SGH_PongBall(10.0f);
	ball->SetPosition(10, 10);
	ball->CenterPivot();

	slider->AddPongBalls(ball);
	SGH_GameObjectManager::GetInstance()->AddGameObject(ball);

	SGH_Player* player = new SGH_Player(slider);
	player->SetUpKey(SGH_InputManager::GetInputUpPlayerOne());
	player->SetDownKey(SGH_InputManager::GetInputDownPlayerOne());
	SGH_PlayerManager::GetInstance()->AddPlayer(player);

	SGH_GameManager::GetInstance()->AddPlayer(player);
	SGH_GameManager::GetInstance()->AddPongBall(ball);

}

void SGH_GameManager::PongTwoPlayer(sf::RenderWindow& _w)
{
	isGameselected = true;
	SGH_Slider* slider = new SGH_Slider(10, 100);
	slider->CenterPivot();
	slider->SetPosition(20, _w.getSize().y / 2);
	SGH_GameObjectManager::GetInstance()->AddGameObject(slider);

	SGH_Slider* slider2 = new SGH_Slider(10, 100);
	slider2->CenterPivot();
	slider2->SetPosition(_w.getSize().x - 20, _w.getSize().y / 2);
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
	SGH_PlayerManager::GetInstance()->AddPlayer(player);

	SGH_Player* player2 = new SGH_Player(slider2);
	player2->SetUpKey(SGH_InputManager::GetInputUpPlayerTwo());
	player2->SetDownKey(SGH_InputManager::GetInputDownPlayerTwo());
	SGH_PlayerManager::GetInstance()->AddPlayer(player2);

	SGH_GameManager::GetInstance()->AddPlayer(player);
	SGH_GameManager::GetInstance()->AddPlayer(player2);
	SGH_GameManager::GetInstance()->AddPongBall(ball);
}

void SGH_GameManager::Bric(sf::RenderWindow& _w)
{
	isGameselected = true;
	SGH_Slider* slider = new SGH_Slider(10, 100);
	slider->CenterPivot();
	slider->SetPosition(20, _w.getSize().y / 2);
	SGH_GameObjectManager::GetInstance()->AddGameObject(slider);


	SGH_Player* player = new SGH_Player(slider);
	player->SetUpKey(SGH_InputManager::GetInputUpPlayerOne());
	player->SetDownKey(SGH_InputManager::GetInputDownPlayerOne());
	SGH_PlayerManager::GetInstance()->AddPlayer(player);

	SGH_PongBall* ball = new SGH_PongBall(10.0f);
	ball->SetPosition(10, 10);
	ball->CenterPivot();
	
	SGH_Bric* bric = new SGH_Bric(50, 100, ball);
	bric->CenterPivot();
	bric->SetPosition(sf::Vector2f(_w.getSize().x/ 2, _w.getSize().y/ 2));
	SGH_GameObjectManager::GetInstance()->AddGameObject(bric);

	slider->AddPongBalls(ball);
	SGH_GameObjectManager::GetInstance()->AddGameObject(ball);
	SGH_GameManager::GetInstance()->AddPongBall(ball);
	SGH_GameManager::GetInstance()->AddPlayer(player);

}


void SGH_GameManager::Update(sf::RenderWindow& _w)
{
	if(!isGameselected)
	menu->Update(_w);
}

SGH_GameManager* SGH_GameManager::GetInstance()
{
	if (!instance)
		instance = new SGH_GameManager();
	return instance;
}

void SGH_GameManager::AddPlayer(SGH_Player* _player)
{
	if (!playerOne)
	{
		playerOne = _player;
		scores.insert(std::pair<SGH_Player*, int>(_player, 0));

		return;
	}
	if (!playerTwo)
	{
		playerTwo = _player;
		scores.insert(std::pair<SGH_Player*, int>(_player, 0));
	}
}

void SGH_GameManager::AddSlider(SGH_Slider* _slider)
{
	if (_slider)
		sliders.push_back(_slider);
}

void SGH_GameManager::AddPongBall(SGH_PongBall* _pongBall)
{
	if (_pongBall)
		pong_balls.push_back(_pongBall);
}

void SGH_GameManager::GameOver(sf::RenderWindow& _w)
{
	if (playerTwo && HitRightWindow(_w))
	{
		UpdateScorePlayer(playerOne);
		ResetBalls(_w);
		SGH_GameObjectManager::GetInstance()->SetPauseAll();
		return;
	}

	if(HitLeftWindow(_w))
	{
		ResetBalls(_w);
		SGH_GameObjectManager::GetInstance()->SetPauseAll();

	}
}

bool SGH_GameManager::HitLeftWindow(sf::RenderWindow& _w)
{
	for (int i = 0; i < pong_balls.size(); ++i)
	{
		if (pong_balls[i]->GetPosition().x - pong_balls[i]->GetOrigin().x * pong_balls[i]->GetScale().x <= 0)
			return true;
	}
	return false;
}

bool SGH_GameManager::HitRightWindow(sf::RenderWindow& _w)
{
	for (int i = 0; i < pong_balls.size(); ++i)
	{
		if (pong_balls[i]->GetPosition().x + pong_balls[i]->GetOrigin().x * pong_balls[i]->GetScale().x > _w.getSize().x)
			return true;
	}
	return false;
}

void SGH_GameManager::UpdateScorePlayer(SGH_Player* _player)
{
	scores[_player] += 1;
}

void SGH_GameManager::ResetBalls(sf::RenderWindow& _w)
{
	for (int i = 0; i < pong_balls.size(); ++i)
	{
		pong_balls[i]->SetPosition(_w.getSize().x / 2, _w.getSize().y / 2);
	}
}
