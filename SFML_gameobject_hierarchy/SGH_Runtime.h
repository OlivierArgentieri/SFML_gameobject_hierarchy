#pragma once
#include <SFML/Graphics.hpp>

class SGH_Runtime
{
private :
	//ref GameObjectManager
	sf::RenderWindow window;
public:
	SGH_Runtime();
	SGH_Runtime(const SGH_Runtime& _ref);
	SGH_Runtime(sf::RenderWindow& _w);
	~SGH_Runtime();

private:

};