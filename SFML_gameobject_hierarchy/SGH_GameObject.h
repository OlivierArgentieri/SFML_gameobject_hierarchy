#pragma once
//#include "SGH_Behaviour.h"
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class SGH_Behaviour;

class SGH_GameObject
{
private:
	bool isPause;
	bool isVisible = true;
protected:
	sf::Transformable* transform;
	std::vector<SGH_Behaviour*> behaviours;
	
	void ClearBehaviours();

public:
	SGH_GameObject();
	~SGH_GameObject();
	SGH_GameObject(sf::Transformable* _tranformable);

	virtual void Update(sf::RenderWindow& _w);
	virtual void ApplyBehaviour(sf::RenderWindow& _w);
	virtual void CatchEvent(sf::RenderWindow& _w, sf::Event _events);

	virtual sf::Vector2f GetPosition();
	virtual void SetPosition(float _x, float _y);
	virtual void SetPosition(sf::Vector2f _newPosition);

	float GetRotation();
	void SetRotation(float _newRotation);

	sf::Vector2f GetScale();
	void SetScale(sf::Vector2f _newScale);

	sf::Vector2f GetOrigin();
	void SetOrigin(sf::Vector2f _newOrigin);

	virtual void CenterPivot();

	bool IsPause();

	void SetPause();
	void SetPause(bool _pause);
	
	virtual void SetVisibility(bool _visibility);
	bool IsVisible();

	virtual sf::Rect<int> GetIntRect();
	virtual sf::Rect<float> GetFloatRect();

	virtual float GetFloatSize();
	virtual sf::Vector2f GetVector2fSize();
	virtual void SetColor(sf::Color _color);
};

