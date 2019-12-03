#pragma once

#include <list>
#include <vector>

class Pot;
class Marker;
class Player;
struct sPosition;
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
	bool Update();


	~TurnManager();

	void CheckDelete();

	bool CHEAKY(int direction,Marker * marker);


private:
	std::vector<Player*> _playerch;	
	std::vector<Marker*> _deleteMarker;
	std::list<Player*> _playerList;
	std::list<Player*>::iterator _playerListitr;

public:
	std::vector<Player *> GetPlayer();
};

