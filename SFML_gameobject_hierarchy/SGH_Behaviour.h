#pragma once
#include <SFML/Graphics.hpp>
class SGH_GameObject;


class SGH_Behaviour
{
protected:
	SGH_GameObject* gameObject;
public:
	SGH_Behaviour(SGH_GameObject* _go);
	virtual void TriggerBehaviour(sf::RenderWindow& _w);
};
