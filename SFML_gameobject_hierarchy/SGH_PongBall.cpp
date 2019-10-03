#include "SGH_PongBall.h"
#include "SGH_BouncyBehaviour.h"

void SGH_PongBall::ResetBall(sf::RenderWindow& _w)
{
	shape->setPosition(_w.getSize().x / 2, _w.getSize().y / 2);
}

bool SGH_PongBall::HitLeftWindow()
{
	return shape->getPosition().x - shape->getOrigin().x * shape->getScale().x <= 0;
}

SGH_PongBall::SGH_PongBall(float size) : SGH_GameObject()
{
	shape = new sf::CircleShape(size / 2);
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
	_w.draw(*shape);

	if (IsPause()) return;

		ApplyBehaviour(_w);
		if (HitLeftWindow())
			ResetBall(_w);
	
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

float SGH_PongBall::GetSize()
{
	return shape->getRadius();
}

SGH_PongBall::~SGH_PongBall()
{
	delete shape;
}
