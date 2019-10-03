#include "SGH_GameManager.h"


SGH_GameManager* SGH_GameManager::instance;

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
