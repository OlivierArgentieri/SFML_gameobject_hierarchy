#include "SGH_Circle.h"

SGH_Circle::SGH_Circle() : SGH_GameObject(*this)
{
	circle = new sf::CircleShape(100.0f);
}
SGH_Circle::SGH_Circle(const SGH_Circle& _ref) : SGH_GameObject(*this)
{
	circle = _ref.circle;
}
SGH_Circle::~SGH_Circle()
{
	delete circle;
}
void SGH_Circle::Update(sf::RenderWindow& _w)
{
	if (circle == nullptr)
		return;

	_w.draw(*circle);
}