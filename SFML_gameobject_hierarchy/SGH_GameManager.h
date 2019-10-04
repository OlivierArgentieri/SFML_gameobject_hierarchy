#pragma once
#include "SGH_Player.h"
#include "SGH_Slider.h"

class SGH_Menu;

class SGH_GameManager
{
private:
	static SGH_GameManager* instance;
	SGH_Player* playerOne;
	SGH_Player* playerTwo;
	
	std::vector<SGH_Slider*> sliders;
	std::vector<SGH_PongBall*> pong_balls;

	std::map<SGH_Player*, int> scores;

	SGH_Menu* menu;
	bool isGameselected = false;
	SGH_GameManager();

public:
	
	static SGH_GameManager* GetInstance();

	void AddPlayer(SGH_Player* _player);
	void AddSlider(SGH_Slider* _slider);
	void AddPongBall(SGH_PongBall* _pongBall);
	void GameOver(sf::RenderWindow& _w);
	bool HitLeftWindow(sf::RenderWindow& _w);
	bool HitRightWindow(sf::RenderWindow& _w);
	void UpdateScorePlayer(SGH_Player* _player);
	void ResetBalls(sf::RenderWindow& _w);

	void PongOnePlayer(sf::RenderWindow& _w);
	void PongTwoPlayer(sf::RenderWindow& _w);
	void Bric(sf::RenderWindow& _w);


	void Update(sf::RenderWindow& _w);
};
