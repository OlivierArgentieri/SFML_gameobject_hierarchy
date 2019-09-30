#pragma once
#include <vector>
#include "SGH_GameObject.h"

class SGH_GameObjectManager
{
private:
	std::vector<SGH_GameObject&> gameObjects;
	void Clear();
	
public:
	void AddGameObject();
	void RemoveGameObject();


};