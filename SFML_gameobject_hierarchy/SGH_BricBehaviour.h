#pragma once
#include "SGH_Behaviour.h"
#include "SGH_PongBall.h"
#include "SGH_Bric.h"


class SGH_BricBehaviour :public SGH_Behaviour
{
private:
	SGH_PongBall* pongBall;
	SGH_GameObject* bric;

	SGH_GameObject* GetBric();
public:
	SGH_BricBehaviour(SGH_PongBall* _pongBall, SGH_GameObject* _bric);
	SGH_PongBall* GetBall();
	void TriggerBehaviour(sf::RenderWindow& _w) override;
	bool HitBric();
	void SGH_Bounce();
};