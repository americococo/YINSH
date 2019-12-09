#pragma once
#include <vector>
class Pot;
enum ePotType;

enum ePlayerType
{
	eNonting = 1000,
	eUser,
	eCom
};

class Player
{
public:
	Player();
	~Player();

protected:
	std::vector<Pot *> _markers;
	std::vector<Pot * > _rings;
	int _score;
	ePlayerType _playerType;
public:
	std::vector<Pot *> GetPot(ePotType type);

	int RingCount();
	int MarkerCount();
	virtual bool settingRing();
	virtual bool SettingMarker();

	bool GetScore();

	void ResetMarker(Pot * marker);
	void GainScore();

	ePlayerType GetPlayerType() { return _playerType; }
};
