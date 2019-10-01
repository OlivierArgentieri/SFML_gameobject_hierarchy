#pragma once
#include "SGH_GameObject.h"
#include <iostream>

class SGH_Slider : public SGH_GameObject
{
private:
	
	sf::RectangleShape* shape;
	bool TriggerBoundary(sf::RenderWindow& _w);
public :
	SGH_Slider(float width, float height);
	~SGH_Slider();
	void Update(sf::RenderWindow& _w) override;
	void CatchEvent(sf::RenderWindow& _w, sf::Event _events) override;
	void SetPosition(sf::Vector2f _pos)override;
	void SetPosition(sf::RenderWindow& _w);
	sf::Vector2f GetPosition()override;
};