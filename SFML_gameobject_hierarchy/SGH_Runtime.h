#pragma once
#include "SGH_GameObjectManager.h"
#include "SGH_PlayerManager.h"

class SGH_GameManager;


class SGH_Runtime
{
private :
	
	
	sf::RenderWindow renderWindow;
	sf::Time frameRate = sf::seconds(1 / 60.0f);

private :
	void Run(sf::RenderWindow& _w);
	void Render(sf::RenderWindow& _w);
	void Event(sf::RenderWindow& _w);
	
public:
	SGH_Runtime();
	~SGH_Runtime();
};
