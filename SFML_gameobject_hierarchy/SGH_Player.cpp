#include "SGH_GameObject.h"
#include "SGH_Player.h"


SGH_ControllableGameObject* SGH_Player::GetControllableGameObject()
{
	if (controllableGameObject)
		return controllableGameObject;
	throw std::invalid_argument("NULL ControllableGameObject");
}

sf::Keyboard::Key SGH_Player::GetUpKey()
{
	return upKey;
}

sf::Keyboard::Key SGH_Player::GetDownKey()
{
	return downKey;
}

sf::Keyboard::Key SGH_Player::GetLeftKey()
{
	return leftKey;
}

sf::Keyboard::Key SGH_Player::GetRightKey()
{
	return rightKey;
}

SGH_Player::SGH_Player(SGH_ControllableGameObject* _cgo)
{
	controllableGameObject = _cgo;
}

void SGH_Player::SGH_MoveGameObject(sf::Event _event, sf::RenderWindow& _w)
{
	if(GetUpKey() != -1)
	{
		MoveUpGameObject(_event, _w);
	}
	if (GetDownKey() != -1)
	{
		MoveDownGameObject(_event, _w);
	}
	if (GetLeftKey() != -1)
	{
		MoveLeftGameObject(_event, _w);
	}
	if (GetRightKey() != -1)
	{
		MoveRightGameObject(_event, _w);
	}
}

void SGH_Player::MoveUpGameObject(sf::Event _event, sf::RenderWindow& _w)
{
	if (_event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(GetUpKey()))
	{
		GetControllableGameObject()->TryMoveUp(_w);
	}
}

void SGH_Player::MoveDownGameObject(sf::Event _event, sf::RenderWindow& _w)
{
	if (_event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(GetDownKey()))
	{
		GetControllableGameObject()->TryMoveDown(_w);
	}
}

void SGH_Player::MoveLeftGameObject(sf::Event _event, sf::RenderWindow& _w)
{
	if (_event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(GetLeftKey()))
	{
		GetControllableGameObject()->TryMoveLeft(_w);
	}
}

void SGH_Player::MoveRightGameObject(sf::Event _event, sf::RenderWindow& _w)
{
	if (_event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(GetRightKey()))
	{
		GetControllableGameObject()->TryMoveRight(_w);
	}
}

void SGH_Player::SetUpKey(sf::Keyboard::Key _upKey)
{
	upKey = _upKey;
}

void SGH_Player::SetDownKey(sf::Keyboard::Key _downKey)
{
	downKey = _downKey;
}

void SGH_Player::SetLeftKey(sf::Keyboard::Key _leftKey)
{
	leftKey = _leftKey;
}

void SGH_Player::SetRightKey(sf::Keyboard::Key _rightKey)
{
	rightKey = _rightKey;
}
