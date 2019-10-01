#pragma once
#include "SGH_Behaviour.h"

class SGH_MoveBehaviour : public SGH_Behaviour
{
private:
	sf::Vector2f moveVector;
public:
	SGH_MoveBehaviour(SGH_GameObject* _go) : SGH_Behaviour(_go){}
	void SetMoveVector(sf::Vector2f	_v2f);
	void SetMoveVector(float _x, float _y);
	sf::Vector2f GetMoveVector();
};