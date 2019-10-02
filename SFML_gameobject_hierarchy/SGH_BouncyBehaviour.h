#pragma once
#include "SGH_MoveBehaviour.h"

class SGH_BouncyBehaviour : public SGH_MoveBehaviour
{
protected:
	bool IsHitLeftEdgeWindow(sf::RenderWindow& _w);
	bool IsHitRightEdgeWindow(sf::RenderWindow& _w);
	bool IsHitTopEdgeWindow(sf::RenderWindow& _w);
	bool IsHitBottomEdgeWindow(sf::RenderWindow& _w);
	virtual void Bounce(sf::RenderWindow& _w);

public:
	SGH_BouncyBehaviour(SGH_GameObject* _go, float _speed) : SGH_MoveBehaviour(_go) { SetMoveVector(_speed, _speed); }
	void TriggerBehaviour(sf::RenderWindow& _w) override;
};