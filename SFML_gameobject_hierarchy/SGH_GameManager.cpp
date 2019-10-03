#include "SGH_GameManager.h"
#include "SGH_GameObjectManager.h"


SGH_GameManager* SGH_GameManager::instance;

SGH_GameManager::SGH_GameManager()
{
}

SGH_GameManager* SGH_GameManager::GetInstance()
{
	if (!instance)
		instance = new SGH_GameManager();
	return instance;
}

void SGH_GameManager::AddPlayer(SGH_Player* _player)
{
	if (_player)
		players.push_back(_player);

	scores.insert(std::pair<SGH_Player*, int>(_player, 0));
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
	if (players.size()==2 && HitRightWindow(_w))
	{
		UpdateScorePlayer(players[0]);
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