#include "SGH_PongBall.h"
#include "SGH_BouncyBehaviour.h"

SGH_PongBall::SGH_PongBall(float size) : SGH_GameObject()
{
	shape = new sf::CircleShape(size);
	behaviours.push_back(new SGH_BouncyBehaviour(this, 0.1));
	transform = shape;
	
}

void SGH_PongBall::Update(sf::RenderWindow& _w)
{
	ApplyBehaviour(_w);
	_w.draw(*shape);
}


SGH_PongBall::~SGH_PongBall()
{
	delete shape;
}
