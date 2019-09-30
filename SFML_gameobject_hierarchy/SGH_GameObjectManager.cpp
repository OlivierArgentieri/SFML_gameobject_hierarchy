#include "SGH_GameObjectManager.h"

void SGH_GameObjectManager::Clear()
{
}

void SGH_GameObjectManager::AddGameObject(SGH_GameObject* _go)
{
	this->gameObjects.push_back(_go);
}	

void SGH_GameObjectManager::RemoveGameObject()
{
}

void SGH_GameObjectManager::UpdateAll(sf::RenderWindow& _w)
{
	for (int i = 0; i < this->gameObjects.size(); ++i)
	{
		this->gameObjects[i]->Update(_w);
	}
}
