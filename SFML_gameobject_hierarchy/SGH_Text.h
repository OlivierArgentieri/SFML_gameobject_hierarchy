#pragma once
#include "SGH_GameObject.h"

class SGH_Text : public SGH_GameObject
{
private:
	sf::Font font;
	sf::Text text;

public:
	SGH_Text();

	SGH_Text(std::string _fontPath);
	sf::Vector2f GetPosition() override;
	void SetPosition(float _x, float _y) override;
	void Update(sf::RenderWindow& _w) override;
	void CenterPivot() override;
	sf::Rect<float> GetFloatRect() override;
	void Display(sf::RenderWindow& _w);
	bool FontLoaded(std::string _path);
	void SetString(std::string _text);
	void SetSize(int _size);

	
};