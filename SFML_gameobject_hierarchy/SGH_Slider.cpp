#include "SGH_Slider.h"
#include "SGH_PongBehaviour.h"

bool SGH_Slider::HitTop(sf::RenderWindow& _w, float offset)
{
	return shape->getPosition().y - shape->getOrigin().y * shape->getScale().y <= offset;
}

bool SGH_Slider::HitBottom(sf::RenderWindow& _w, float offset)
{
	return shape->getPosition().y + shape->getOrigin().y * shape->getScale().y > _w.getSize().y - offset;
}

SGH_Slider::SGH_Slider(float width, float height) : SGH_ControllableGameObject(shape)
{
	shape = new sf::RectangleShape(sf::Vector2f(width, height));
	transform = shape;
}

SGH_Slider::~SGH_Slider()
{
	delete shape;
}

void SGH_Slider::Update(sf::RenderWindow& _w)
{
	ApplyBehaviour(_w);
	_w.draw(*shape);
}

void SGH_Slider::SetPosition(sf::Vector2f _pos)
{
	shape->setPosition(_pos);
}

void SGH_Slider::SetPosition(float _width, float _height)
{
	SetPosition(sf::Vector2f(_width, _height));
}

sf::Vector2f SGH_Slider::GetSize()
{
	return shape->getSize();
}

/*
void SGH_Slider::SetPosition(sf::RenderWindow& _w)
{
	shape->setPosition(20, _w.getSize().y / 2);
}*/

sf::Vector2f SGH_Slider::GetPosition()
{
	return shape->getPosition();
}

void SGH_Slider::CenterPivot()
{
	shape->setOrigin(shape->getSize().x / 2, shape->getSize().y / 2);
}

sf::FloatRect SGH_Slider::GetLocalBounds()
{
	return shape->getGlobalBounds();
}

void SGH_Slider::AddPongBalls(SGH_PongBall* _pongBall)
{
	this->pongBalls.push_back(_pongBall);
	this->behaviours.push_back(new SGH_PongBehaviour(this, _pongBall, 10));
}

bool SGH_Slider::CanMoveUp(sf::RenderWindow& _w)
{
	return !HitTop(_w);
}

bool SGH_Slider::CanMoveDown(sf::RenderWindow& _w)
{
	return !HitBottom(_w);
}

void SGH_Slider::MoveUp()
{
	SetPosition(GetPosition() - sf::Vector2f(0, 10));
}

void SGH_Slider::MoveDown()
{
	SetPosition(GetPosition() + sf::Vector2f(0, 10));
}

void SGH_Slider::CatchEvent(sf::RenderWindow& _w, sf::Event _events)
{
	// if(player->PressUp());
	// 
	// if(player->PressDown());
	//todo
}