#include "SGH_Bric.h"


SGH_Bric::SGH_Bric(float width, float height)
{
	rectangle = new sf::RectangleShape(sf::Vector2f(width, height));
}

SGH_Bric::~SGH_Bric()
{
	delete rectangle;
}