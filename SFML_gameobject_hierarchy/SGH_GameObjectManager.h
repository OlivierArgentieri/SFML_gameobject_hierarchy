#pragma once
#include <vector>
#include "SGH_GameObject.h"


class SGH_GameObjectManager
{
private:
	static SGH_GameObjectManager* instance;
	std::vector<SGH_GameObject*> gameObjects;
	void Clear();
	bool paused;

	SGH_GameObjectManager();
public:
	static SGH_GameObjectManager* GetInstance();
	~SGH_GameObjectManager();
	void AddGameObject(SGH_GameObject* _go);
	void RemoveGameObject();
	void UpdateAll(sf::RenderWindow& _w);
	void CatchAllEvents(sf::RenderWindow& _w, sf::Event _events);
	void SetPauseAll();
};