#include "SGH_GameObjectManager.h"

void SGH_GameObjectManager::Clear()
{
	for (int i = gameObjects.size() - 1; i >= 0; --i)
	{
		delete gameObjects[i];
	}
}

SGH_GameObjectManager::~SGH_GameObjectManager()
{
	Clear();
}

void SGH_GameObjectManager::AddGameObject(SGH_GameObject* _go)
{
	this->gameObjects.push_back(_go);
}	

void SGH_GameObjectManager::RemoveGameObject()
{
	// todo
}

void SGH_GameObjectManager::UpdateAll(sf::RenderWindow& _w)
{
	for (int i = 0; i < this->gameObjects.size(); ++i)
	{
		this->gameObjects[i]->Update(_w);
	}
}

void SGH_GameObjectManager::CatchAllEvents(sf::RenderWindow& _w, sf::Event _events)
{
	for (int i = 0; i < this->gameObjects.size(); ++i)
	{
		this->gameObjects[i]->CatchEvent(_w, _events);
	}
}

void SGH_GameObjectManager::SetPauseAll()
{
	for (int i = 0; i < this->gameObjects.size(); ++i)
	{
		this->gameObjects[i]->SetPause();
	}
}