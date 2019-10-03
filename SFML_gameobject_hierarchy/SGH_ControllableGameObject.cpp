#pragma once
#include "SGH_ControllableGameObject.h"


void SGH_ControllableGameObject::TryMoveUp(sf::RenderWindow& _w)
{
	if (CanMoveUp(_w))
	{
		MoveUp();
	}
}

void SGH_ControllableGameObject::TryMoveDown(sf::RenderWindow& _w)
{
	if(CanMoveDown(_w))
	{
		MoveDown();
	}
}

void SGH_ControllableGameObject::TryMoveLeft(sf::RenderWindow& _w)
{
	if(CanMoveLeft(_w))
	{
		MoveLeft();
	}
}

void SGH_ControllableGameObject::TryMoveRight(sf::RenderWindow& _w)
{
	if(CanMoveRight(_w))
	{
		MoveRight();
	}
}

void SGH_ControllableGameObject::Update(sf::RenderWindow& _w)
{
	TryMoveUp(_w);
	TryMoveDown(_w);
	TryMoveRight(_w);
	TryMoveLeft(_w);
}

bool SGH_ControllableGameObject::CanMoveUp(sf::RenderWindow& _w)
{
	return false;
}

bool SGH_ControllableGameObject::CanMoveDown(sf::RenderWindow& _w)
{
	return false;

}

bool SGH_ControllableGameObject::CanMoveLeft(sf::RenderWindow& _w)
{
	return false;

}

bool SGH_ControllableGameObject::CanMoveRight(sf::RenderWindow& _w)
{
	return false;

}


void SGH_ControllableGameObject::MoveUp()
{
}

void SGH_ControllableGameObject::MoveDown()
{
}

void SGH_ControllableGameObject::MoveLeft()
{
}

void SGH_ControllableGameObject::MoveRight()
{
}
