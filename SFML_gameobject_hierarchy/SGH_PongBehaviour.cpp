#include "SGH_PongBehaviour.h"

bool SGH_PongBehaviour::IsHitSlider()
{
	return this->slider->GetLocalBounds().intersects(this->pongBall->GetLocalBounds());
}

void SGH_PongBehaviour::Bounce(sf::RenderWindow& _w)
{
	pongBall->SetMoveVector(sf::Vector2f(-pongBall->GetMoveVector().x, pongBall->GetMoveVector().y));
	pongBall->SetPosition(pongBall->GetPosition() + GetMoveVector());
}

void SGH_PongBehaviour::TriggerBehaviour(sf::RenderWindow& _w)
{
	if(IsHitSlider())
	{
		Bounce(_w);
	}
}