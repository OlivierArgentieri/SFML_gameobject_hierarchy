#pragma once
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics.hpp>

class SGH_GameObject
{
private:
	sf::Event gameEvent;

protected:
	sf::Transformable* transform;
	float height;
	float width;
	
public:
	SGH_GameObject();
	~SGH_GameObject();
	virtual void Update(sf::RenderWindow& _w);

	sf::Vector2f GetPosition();
	void SetPosition(float _width, float _height);
	void SetPosition(sf::Vector2f _newPosition);

	float GetRotation();
	void SetRotation(float _newRotation);

	sf::Vector2f GetScale();
	void SetScale(sf::Vector2f _newScale);

	sf::Vector2f GetOrigin();
	void SetOrigin(sf::Vector2f _newOrigin);

	virtual void CenterPivot();
};
