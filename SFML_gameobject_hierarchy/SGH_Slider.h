#pragma once
#include "SGH_GameObject.h"
#include <iostream>

class SGH_Slider : public SGH_GameObject
{
private:
	sf::RectangleShape* rectangle;
public :
	SGH_Slider();
	~SGH_Slider();
	void Update(sf::RenderWindow& _w) override;
	void CatchEvent(sf::RenderWindow& _w, sf::Event _events) override;
};

