#pragma once
#include "SGH_GameObject.h"
#include "SGH_Text.h"
#include "SGH_GameManager.h"

class SGH_Button :	public SGH_GameObject
{
	typedef void(SGH_GameManager::* SGH_GameManagerMethod)(sf::RenderWindow&);
private:
	SGH_Text* text;

	sf::RectangleShape* shape;
	
public:
	SGH_Button(const std::string _fontPath, sf::Vector2f _size);

	void SetColor(sf::Color _color) override;
	void CenterPivot() override;
	void Update(sf::RenderWindow& _w) override;
	bool Clicked(sf::RenderWindow& _w);
	void SetPosition(float _x, float _y) override;
	void SetString(std::string _string);
};

