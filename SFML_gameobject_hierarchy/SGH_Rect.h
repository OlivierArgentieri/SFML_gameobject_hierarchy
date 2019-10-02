#pragma once
#include "SGH_GameObject.h"

class SGH_Rect : public SGH_GameObject
{
private:
	sf::RectangleShape* rectangle;
public:
	SGH_Rect(const SGH_Rect& _ref);
	SGH_Rect() : SGH_Rect(10,10){}
	SGH_Rect(float _width_x, float _width_y) : SGH_Rect(sf::Vector2f(_width_x, _width_y)) {}
	SGH_Rect(sf::Vector2f _size);
	~SGH_Rect();
	void Update(sf::RenderWindow& _w) override;
	void SetSize(sf::Vector2f _size);
	sf::Vector2f GetSize();
	void CenterPivot() override;
};