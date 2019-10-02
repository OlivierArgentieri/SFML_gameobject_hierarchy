#include "SGH_Circle.h"

SGH_Circle::SGH_Circle()
{
	circle = new sf::CircleShape(100.0f);
	transform = circle;
}

SGH_Circle::SGH_Circle(float _size)
{
	circle = new sf::CircleShape(_size / 2);
	transform = circle;
}

SGH_Circle::SGH_Circle(const SGH_Circle& _ref)
{
	circle = _ref.circle;
	transform = _ref.transform;
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