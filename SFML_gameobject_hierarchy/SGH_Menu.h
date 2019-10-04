#pragma once
#include <SFML/Graphics/Text.hpp>
#include "SGH_Text.h"
#include "SGH_Button.h"

class SGH_Menu
{
private:
	SGH_Text* title;
	SGH_Text* text_game_1;
	SGH_Text* text_game_2;
	SGH_Text* text_game_3;


	SGH_Button* testButton;
	SGH_Button* buttonGame1;
	SGH_Button* buttonGame2;
	SGH_Button* buttonGame3;
	
	void Display(sf::RenderWindow& _w);

public:
	SGH_Menu();
	~SGH_Menu();
	void Update(sf::RenderWindow& _w);
	
};
