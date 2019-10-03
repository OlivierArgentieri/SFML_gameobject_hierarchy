#pragma once
#include <SFML/Window/Keyboard.hpp>

class SGH_InputManager
{
private:

public:
	static sf::Keyboard::Key GetInputUpPlayerOne();
	static sf::Keyboard::Key GetInputDownPlayerOne();
	static sf::Keyboard::Key GetInputLeftPlayerOne();
	static sf::Keyboard::Key GetInputRightPlayerOne();
	
	static sf::Keyboard::Key GetInputUpPlayerTwo();
	static sf::Keyboard::Key GetInputDownPlayerTwo();
	static sf::Keyboard::Key GetInputLeftPlayerTwo();
	static sf::Keyboard::Key GetInputRightPlayerTwo();
};