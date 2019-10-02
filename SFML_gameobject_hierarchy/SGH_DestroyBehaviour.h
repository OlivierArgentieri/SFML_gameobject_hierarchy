#pragma once
#include "SGH_Behaviour.h"

class SGH_DestroyBehaviour : public SGH_Behaviour
{
private:
	void DestroyByObject(SGH_GameObject* _go);

public:

	~SGH_DestroyBehaviour();
	SGH_DestroyBehaviour(SGH_GameObject* _go) : SGH_Behaviour(_go) {}
	void TriggerBehaviour(sf::RenderWindow& _w) override;
};

