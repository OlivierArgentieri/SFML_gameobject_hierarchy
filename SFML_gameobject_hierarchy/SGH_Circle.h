#pragma once
#include "SGH_GameObject.h"

class SGH_Circle : public SGH_GameObject
{
private:
	sf::CircleShape* circle;
public :
	SGH_Circle();
	SGH_Circle(float _size);
	SGH_Circle(const SGH_Circle& _ref);
	~SGH_Circle();
	void Update(sf::RenderWindow& _w) override;
};