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
	if (HitBric())
		SGH_Bounce();

}

bool SGH_BricBehaviour::HitBric()
{
	
	return GetBall()->GetFloatRect().intersects(GetBric()->GetFloatRect());
}
void SGH_BricBehaviour::SGH_Bounce()
{
	GetBall()->SetMoveVector(sf::Vector2f(-GetBall()->GetMoveVector().x, -GetBall()->GetMoveVector().y));
}