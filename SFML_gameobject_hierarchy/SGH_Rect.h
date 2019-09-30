#pragma once
#include "SGH_GameObject.h"

class SGH_Rect : public SGH_GameObject
{
private:
	sf::RectangleShape* rectangle;
public:
	SGH_Rect();
	SGH_Rect(const SGH_Rect& _ref);
	~SGH_Rect();
	void Update(sf::RenderWindow& _w) override;
	void CenterPivot() override;
};
