#pragma once
#include "SGH_Behaviour.h"

class SGH_DestroyBehaviour : public SGH_Behaviour
{
private:
	SGH_GameObject* destructor;
	bool CanBeDestroy();

	SGH_GameObject* GetDestructor();
	SGH_GameObject* GetGameObject();
public:
	SGH_DestroyBehaviour(SGH_GameObject* _go, SGH_GameObject* _destructor) : SGH_Behaviour(_go) { destructor = _destructor; }
	~SGH_DestroyBehaviour();
	void TriggerBehaviour(sf::RenderWindow& _w) override;
	void Destroy();
};