#include "SGH_Button.h"
#include <iostream>

SGH_Button::SGH_Button(const std::string _fontPath, sf::Vector2f _size)
{
	text = new SGH_Text(_fontPath);
	shape = new sf::RectangleShape(_size);
}

void SGH_Button::SetColor(sf::Color _color)
{
	shape->setFillColor(_color);
}

void SGH_Button::CenterPivot()
{
	text->CenterPivot();
	shape->setOrigin(shape->getSize().x / 2, shape->getSize().y / 2);
}

void SGH_Button::Update(sf::RenderWindow& _w)
{
	_w.draw(*shape);

	text->Update(_w);

}

bool SGH_Button::Clicked(sf::RenderWindow& _w)
{
	return shape->getGlobalBounds().contains(_w.mapPixelToCoords(sf::Mouse::getPosition(_w))) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

void SGH_Button::SetPosition(float _x, float _y)
{
	shape->setPosition(_x, _y);
	text->SetPosition(_x, _y);
}

void SGH_Button::SetString(std::string _string)
{
	text->SetString(_string);
}
