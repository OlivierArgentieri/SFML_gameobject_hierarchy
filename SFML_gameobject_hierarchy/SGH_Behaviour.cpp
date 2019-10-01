#include "SGH_Behaviour.h"
#include "SGH_GameObject.h"

SGH_Behaviour::SGH_Behaviour(SGH_GameObject* _go)
{
	gameObject = _go;
}

void SGH_Behaviour::TriggerBehaviour(sf::RenderWindow& _w)
{
}