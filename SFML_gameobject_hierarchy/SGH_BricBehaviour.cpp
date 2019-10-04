#include "SGH_BricBehaviour.h"

SGH_GameObject* SGH_BricBehaviour::GetBric()
{
	if (bric)
		return bric;

	throw std::invalid_argument("NULL BricGameObject");
}

SGH_BricBehaviour::SGH_BricBehaviour(SGH_PongBall* _pongBall, SGH_GameObject* _bric): SGH_Behaviour(_pongBall)
{
	pongBall = _pongBall;
	bric = _bric;
}

SGH_PongBall* SGH_BricBehaviour::GetBall()
{
	if (pongBall)
		return pongBall;

	throw std::invalid_argument("NULLPongBallGameObject");
}



void SGH_BricBehaviour::TriggerBehaviour(sf::RenderWindow& _w)
{
	if (HitLeftBric() || HitRightBric())
		SGH_BounceLeftRight();

	if (HitTopBric() || HitBotBric())
		SGH_BounceTopBot();
}

bool SGH_BricBehaviour::HitLeftBric()
{
	//return GetBall()->GetFloatRect().left ==  GetBric()->GetFloatRect().left ;
	return false;
}
bool SGH_BricBehaviour::HitRightBric()
{
	//return GetBall()->GetFloatRect().width == GetBric()->GetFloatRect().width;
	return false;
}

bool SGH_BricBehaviour::HitTopBric()
{
	float 
	float x_ball_min = GetBall()->GetPosition().x + GetBall()->GetOrigin().x * GetBall()->GetScale().x;
	float y_ball = GetBall()->GetPosition().y + GetBall()->GetOrigin().y * GetBall()->GetScale().y;

	
	bool test_x = GetBall()->GetPosition().x + GetBall()->GetFloatSize() > GetBric()->GetPosition().x + GetBric()->GetOrigin().x * GetBric()->GetScale();
	return GetBall()->GetFloatRect().top == GetBric()->GetFloatRect().top
}
bool SGH_BricBehaviour::HitBotBric()
{
	return false;

};

void SGH_BricBehaviour::SGH_BounceLeftRight()
{
	GetBall()->SetMoveVector(sf::Vector2f(-GetBall()->GetMoveVector().x, GetBall()->GetMoveVector().y));
}

void SGH_BricBehaviour::SGH_BounceTopBot()
{
	GetBall()->SetMoveVector(sf::Vector2f(GetBall()->GetMoveVector().x, -GetBall()->GetMoveVector().y));
}