#pragma once
#include "SGH_GameObject.h"

class SGH_PongBall : public SGH_GameObject 
{
private:
	
	sf::CircleShape* shape;
public:
	SGH_PongBall(float size);
	void Update(sf::RenderWindow& _w) override;
	void CenterPivot() override;
	~SGH_PongBall();
};
