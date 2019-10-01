#pragma once
#include "SGH_Behaviour.h"
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class SGH_GameObject
{
private:
	
protected:
	sf::Transformable* transform;
	std::vector<SGH_Behaviour> behaviours;
	float height = 0;
	float width = 0;
	float radius = 0;

public:
	SGH_GameObject();
	SGH_GameObject(sf::Vector2f _size);
	SGH_GameObject(float _radius);
	~SGH_GameObject();
	virtual void Update(sf::RenderWindow& _w);
	virtual void ApplyBehaviour(sf::RenderWindow& _w);
	virtual void CatchEvent(sf::RenderWindow& _w, sf::Event _events);

	virtual sf::Vector2f GetPosition();
	void SetPosition(float _width, float _height);
	virtual void SetPosition(sf::Vector2f _newPosition);

	float GetRotation();
	void SetRotation(float _newRotation);

	sf::Vector2f GetScale();
	void SetScale(sf::Vector2f _newScale);

	sf::Vector2f GetOrigin();
	void SetOrigin(sf::Vector2f _newOrigin);

	sf::Vector2f GetSize();
	void SetSize(sf::Vector2f _newSize);


	virtual void CenterPivot();
};