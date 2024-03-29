#pragma once
#include "SGH_GameObject.h"
#include "SGH_BouncyBehaviour.h"

class SGH_PongBall : public SGH_GameObject 
{
private:
	
	sf::CircleShape* shape;
	SGH_BouncyBehaviour* bouncy_behaviour;
public:
	SGH_PongBall(float size);
	sf::FloatRect GetLocalBounds();
	void Update(sf::RenderWindow& _w) override;
	void CenterPivot() override;
	void SetMoveVector(sf::Vector2f _moveVector);
	sf::Vector2f GetMoveVector();
	
	sf::Rect<float> GetFloatRect() override;
	
	float GetSize();
	float GetFloatSize() override;
	~SGH_PongBall();
};
