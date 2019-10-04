#include "SGH_Bric.h"
#include "SGH_DestroyBehaviour.h"
#include "SGH_BricBehaviour.h"

SGH_Bric::SGH_Bric(float width, float height, SGH_PongBall* _destructor)
{
	// todo get destructor
	// todo get Shape
	 rectangle = new sf::RectangleShape(sf::Vector2f(width, height));
	 behaviours.push_back(new SGH_DestroyBehaviour(this, _destructor));
	 behaviours.push_back(new SGH_BricBehaviour(_destructor, this));
	 destructor = _destructor;
	 transform = rectangle;
}

SGH_PongBall* SGH_Bric::GetDestructor()
{
	if (destructor)
		return destructor;
	
	throw std::invalid_argument("NULL DestructorGameObject");
	
}

void SGH_Bric::CenterPivot()
{
	float x = this->rectangle->getSize().x / 2;
	float y = this->rectangle->getSize().y / 2;
	this->SetOrigin(sf::Vector2f(x, y));
}

void SGH_Bric::Update(sf::RenderWindow& _w)
{
	if (IsVisible())
		_w.draw(*rectangle);

	ApplyBehaviour(_w);
}

sf::Rect<float> SGH_Bric::GetFloatRect()
{
	return rectangle->getGlobalBounds();
}

sf::Vector2f SGH_Bric::GetVector2fSize()
{
	return rectangle->getSize();
}

SGH_Bric::~SGH_Bric()
{
	delete rectangle;
}
