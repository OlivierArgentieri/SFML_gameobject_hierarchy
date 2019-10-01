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
	float height;
	float width;
	
public:
	SGH_GameObject();
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


	virtual void CenterPivot();

	
};
