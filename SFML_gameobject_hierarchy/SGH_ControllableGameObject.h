#pragma once
#include "SGH_GameObject.h"

class SGH_ControllableGameObject : public SGH_GameObject
{
private:
public:
	SGH_ControllableGameObject(sf::Transformable* _transformable) : SGH_GameObject(_transformable){}
	virtual void Update(sf::RenderWindow& _w) override;
		
	virtual bool CanMoveUp(sf::RenderWindow& _w);
	virtual bool CanMoveDown(sf::RenderWindow& _w);
	virtual bool CanMoveLeft(sf::RenderWindow& _w);
	virtual bool CanMoveRight(sf::RenderWindow& _w);

	virtual void MoveUp();
	virtual void MoveDown();
	virtual void MoveLeft();
	virtual void MoveRight();

	void TryMoveUp(sf::RenderWindow& _w);
	void TryMoveDown(sf::RenderWindow& _w);
	void TryMoveLeft(sf::RenderWindow& _w);
	void TryMoveRight(sf::RenderWindow& _w);
};