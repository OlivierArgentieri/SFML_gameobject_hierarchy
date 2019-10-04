#pragma once
#include "SGH_Player.h"

class SGH_PlayerManager
{
private:
	static SGH_PlayerManager* instance;
	
	std::vector<SGH_Player*> players;
	SGH_PlayerManager();
public:
	
	static SGH_PlayerManager* GetInstance();
	~SGH_PlayerManager();
	void AddPlayer(SGH_Player* _player);
	void TriggerAllPlayer(sf::Event _event, sf::RenderWindow& _w);
	void ClearPlayers();
};