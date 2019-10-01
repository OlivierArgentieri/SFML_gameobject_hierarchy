#include "SGH_MoveBehaviour.h"

void SGH_MoveBehaviour::SetMoveVector(sf::Vector2f _v2f)
{
	this->moveVector = _v2f;
}

void SGH_MoveBehaviour::SetMoveVector(float _x, float _y)
{
	SetMoveVector(sf::Vector2f(_x, _y));
}

sf::Vector2f SGH_MoveBehaviour::GetMoveVector()
{
	return moveVector;
}
