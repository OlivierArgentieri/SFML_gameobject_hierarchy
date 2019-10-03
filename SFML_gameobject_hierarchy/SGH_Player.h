#pragma once
#include "SGH_ControllableGameObject.h"

class SGH_Player
{
private:
	SGH_ControllableGameObject* controllableGameObject;

	SGH_ControllableGameObject* GetControllableGameObject();

	sf::Keyboard::Key upKey;
	sf::Keyboard::Key downKey;
	sf::Keyboard::Key leftKey;
	sf::Keyboard::Key rightKey;

	sf::Keyboard::Key GetUpKey();
	sf::Keyboard::Key GetDownKey();
	sf::Keyboard::Key GetLeftKey();
	sf::Keyboard::Key GetRightKey();

public:
	SGH_Player(SGH_ControllableGameObject* _cgo);
	void SGH_MoveGameObject(sf::Event _event, sf::RenderWindow& _w);

	void MoveUpGameObject(sf::Event _event, sf::RenderWindow& _w);
	void MoveDownGameObject(sf::Event _event, sf::RenderWindow& _w);
	void MoveLeftGameObject(sf::Event _event, sf::RenderWindow& _w);
	void MoveRightGameObject(sf::Event _event, sf::RenderWindow& _w);

	void SetUpKey(sf::Keyboard::Key _upKey);
	void SetDownKey(sf::Keyboard::Key _downKey);
	void SetLeftKey(sf::Keyboard::Key _leftKey);
	void SetRightKey(sf::Keyboard::Key _rightKey);
	
};
