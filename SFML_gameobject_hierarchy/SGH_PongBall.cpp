#include "SGH_PongBall.h"
#include "SGH_BouncyBehaviour.h"

SGH_PongBall::~SGH_PongBall()
{
	delete shape;
}

SGH_PongBall::SGH_PongBall(float size) : SGH_GameObject()
{
	shape = new sf::CircleShape(size);
	behaviours.push_back(SGH_BouncyBehaviour(this));
	transform = shape;
}
