#pragma once
#include "SGH_Player.h"

class SGH_PlayerManager
{
private:
	std::vector<SGH_Player*> players;

public:
	~SGH_PlayerManager();
	void AddPlayer(SGH_Player* _player);
	void TriggerAllPlayer(sf::Event _event, sf::RenderWindow& _w);
	void ClearPlayers();
};

