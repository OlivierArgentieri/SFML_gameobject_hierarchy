#pragma once
#include "SGH_Rect.h"
#include "SGH_PongBall.h"

class SGH_Bric : public SGH_Rect
{
private:
	sf::RectangleShape* rectangle;
	SGH_PongBall* destructor;

	SGH_PongBall* GetDestructor();
	
public:
	SGH_Bric() : SGH_Bric(20,10, nullptr){}
	SGH_Bric(float width, float height, SGH_PongBall* _destructor);
	void CenterPivot() override;
	void Update(sf::RenderWindow& _w) override;
	sf::Rect<float> GetFloatRect() override;
	sf::Vector2f GetVector2fSize() override;
	~SGH_Bric();
};
