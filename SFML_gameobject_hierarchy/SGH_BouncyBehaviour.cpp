#include "SGH_BouncyBehaviour.h"
#include "SGH_GameObject.h"

bool SGH_BouncyBehaviour::IsHitLeftEdgeWindow(sf::RenderWindow& _w)
{
	bool test_left = gameObject->GetPosition().x - gameObject->GetOrigin().x * gameObject->GetScale().x <= 0;
	return test_left;
}

bool SGH_BouncyBehaviour::IsHitRightEdgeWindow(sf::RenderWindow& _w)
{
	bool test_right = gameObject->GetPosition().x + gameObject->GetOrigin().x * gameObject->GetScale().x > _w.getSize().x;
	return test_right;
}

bool SGH_BouncyBehaviour::IsHitTopEdgeWindow(sf::RenderWindow& _w)
{
	bool test_top = gameObject->GetPosition().y - gameObject->GetOrigin().y * gameObject->GetScale().y <= 0;
	return test_top;
}

bool SGH_BouncyBehaviour::IsHitBottomEdgeWindow(sf::RenderWindow& _w)
{
	bool test_bottom = gameObject->GetPosition().y + gameObject->GetOrigin().y * gameObject->GetScale().y > _w.getSize().y;
	return test_bottom;
}


void SGH_BouncyBehaviour::TriggerBehaviour(sf::RenderWindow& _w)
{
	Bounce(_w);
}

void SGH_BouncyBehaviour::Bounce(sf::RenderWindow& _w)
{
	if (IsHitTopEdgeWindow(_w) || IsHitBottomEdgeWindow(_w))
	{
		SetMoveVector(GetMoveVector().x, -GetMoveVector().y);
		return;
	}
	
	if (IsHitLeftEdgeWindow(_w) || IsHitRightEdgeWindow(_w))
	{
		SetMoveVector(-GetMoveVector().x, GetMoveVector().y);
	}
	gameObject->SetPosition(gameObject->GetPosition() + GetMoveVector());
}

SGH_BouncyBehaviour::SGH_BouncyBehaviour(SGH_GameObject* _go, sf::Vector2f _moveVector): SGH_MoveBehaviour(_go, _moveVector)
{
}
