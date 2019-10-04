#include "SGH_Text.h"

SGH_Text::SGH_Text(const std::string _fontPath)
{
	if (!FontLoaded(_fontPath))
		throw std::invalid_argument("Error loading font");

	text.setFont(font);
}

sf::Vector2f SGH_Text::GetPosition()
{
	return text.getPosition();
}

void SGH_Text::SetPosition(float _x, float _y)
{
	text.setPosition(_x, _y);
}

void SGH_Text::Update(sf::RenderWindow& _w)
{
	Display(_w);
}

void SGH_Text::CenterPivot()
{
	text.setOrigin(text.getPosition().x / 2, text.getPosition().y / 2);
}

sf::Rect<float> SGH_Text::GetFloatRect()
{
	return text.getGlobalBounds();
}

void SGH_Text::Display(sf::RenderWindow& _w)
{
	_w.draw(text);
}


bool SGH_Text::FontLoaded(std::string _path)
{
	return font.loadFromFile(_path);
}

void SGH_Text::SetString(std::string _text)
{
	text.setString(_text);
}

void SGH_Text::SetSize(int _size)
{
	text.setCharacterSize(_size);
}