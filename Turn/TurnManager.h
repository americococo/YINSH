#pragma once

#include "../DLinkedList.h"
class Player;

class TurnManager
{
private:
	TurnManager();
	int cirleNum;
public:
	static TurnManager & GetInstance()
	{
		static TurnManager * instance = new TurnManager();
		return * instance;
	}
	void Update();

	DLinkedList<Player*> _playerList;
	DLinkedListIterator<Player*> _playeritr;
	~TurnManager();


};

