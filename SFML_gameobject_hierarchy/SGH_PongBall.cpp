#include "SGH_PongBall.h"
#include "SGH_BouncyBehaviour.h"

SGH_PongBall::SGH_PongBall(float size) : SGH_GameObject()
{
	shape = new sf::CircleShape(size/2);
	behaviours.push_back(new SGH_BouncyBehaviour(this, 5));
	transform = shape;

}

void SGH_PongBall::Update(sf::RenderWindow& _w)
{
	ApplyBehaviour(_w);
	_w.draw(*shape);
}

void SGH_PongBall::CenterPivot()
{
	this->SetOrigin(sf::Vector2f(shape->getRadius(), shape->getRadius()));
}


SGH_PongBall::~SGH_PongBall()
{
	delete shape;
}
