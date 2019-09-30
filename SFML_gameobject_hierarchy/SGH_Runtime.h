#pragma once
#include "SGH_GameObjectManager.h"

class SGH_Runtime
{
private :
	SGH_GameObjectManager* gameManager;
	sf::RenderWindow renderWindow;
private :
	void Run(sf::RenderWindow& _w);
	void Render(sf::RenderWindow& _w);
	void Event(sf::RenderWindow& _w);
public:
	SGH_Runtime();
	~SGH_Runtime();
};
