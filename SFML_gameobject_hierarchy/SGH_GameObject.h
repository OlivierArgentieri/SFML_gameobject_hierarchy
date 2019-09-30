#pragma once
#include <SFML/Graphics/Transformable.hpp>

class SGH_GameObject
{
private:
	sf::Transformable* transform;
	SGH_GameObject();

public:
	SGH_GameObject(const SGH_GameObject& _ref);
	SGH_GameObject(sf::Transformable& _refTransform);
	~SGH_GameObject();
	virtual void Update();

	sf::Vector2f GetPosition();
	void SetPosition(sf::Vector2f _newPosition);

	float GetRotation();
	void SetRotation(float _newRotation);

	sf::Vector2f GetScale();
	void SetScale(sf::Vector2f _newScale);

	sf::Vector2f GetOrigin();
	void SetOrigin(sf::Vector2f _newOrigin);
};
