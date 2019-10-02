#pragma once
#include "SGH_GameObject.h"
#include <iostream>
#include "SGH_PongBall.h"

class SGH_Slider : public SGH_GameObject
{
private:
	sf::RectangleShape* shape;
	std::vector<SGH_PongBall*> pongBalls;
	bool HitTop(sf::RenderWindow& _w, float offset = 10);
	bool HitBottom(sf::RenderWindow& _w, float offset = 20);
	
public:
	SGH_Slider(float width, float height);
	~SGH_Slider();
	void Update(sf::RenderWindow& _w) override;
	void CatchEvent(sf::RenderWindow& _w, sf::Event _events) override;
	void SetPosition(sf::Vector2f _pos)override;
	void SetPosition(sf::RenderWindow& _w);
	sf::Vector2f GetPosition() override;
	void CenterPivot() override;
	sf::FloatRect GetLocalBounds();
	void AddPongBalls(SGH_PongBall* _pongBall);
	
};