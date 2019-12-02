#pragma once
#include <vector>
class Pot;
enum ePotType;
class Player
{
public:
	Player();
	~Player();

private:
	std::vector<Pot *> _markers;
	std::vector<Pot * > _rings;
	int _score;

public:
	std::vector<Pot *> GetPot(ePotType type);

	int RingCount();

	void settingRing();
	void SettingMarker();

};
