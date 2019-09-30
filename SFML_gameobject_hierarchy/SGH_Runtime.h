#pragma once
#include <SFML/Graphics.hpp>
#include "SGH_GameObjectManager.h"

class SGH_Runtime
{
private :
	SGH_GameObjectManager* gameManager;
	sf::RenderWindow renderWindow;
	void Run();
public:
	SGH_Runtime();
	
	~SGH_Runtime();

	void Render(sf::RenderWindow& _w);
	void Event(sf::RenderWindow& _w);
	
private:

};
