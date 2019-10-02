#include "SGH_PongBall.h"
#include "SGH_BouncyBehaviour.h"

SGH_PongBall::SGH_PongBall(float size) : SGH_GameObject()
{
	shape = new sf::CircleShape(size/2);
	bouncy_behaviour = new SGH_BouncyBehaviour(this, 5);
	behaviours.push_back(bouncy_behaviour);
	transform = shape;
}

sf::FloatRect SGH_PongBall::GetLocalBounds()
{
	return shape->getGlobalBounds();
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

void SGH_PongBall::SetMoveVector(sf::Vector2f _moveVector)
{
	bouncy_behaviour->SetMoveVector(_moveVector);
}

sf::Vector2f SGH_PongBall::GetMoveVector()
{
	return bouncy_behaviour->GetMoveVector();
}


SGH_PongBall::~SGH_PongBall()
{
	delete shape;
}
