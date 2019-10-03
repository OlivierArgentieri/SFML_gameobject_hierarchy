#include "SGH_PlayerManager.h"

SGH_PlayerManager::~SGH_PlayerManager()
{
	ClearPlayers();
}

void SGH_PlayerManager::AddPlayer(SGH_Player* _player)
{
	players.push_back(_player);
}

void SGH_PlayerManager::TriggerAllPlayer(sf::Event _event, sf::RenderWindow& _w)
{
	for (int i = 0; i < players.size() ; ++i)
	{
		players[i]->SGH_MoveGameObject(_event, _w);
	}
}

void SGH_PlayerManager::ClearPlayers()
{
	for (int i = 0; i < players.size(); ++i)
	{
		delete players[i];
	}
}