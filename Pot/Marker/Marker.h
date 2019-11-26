#pragma once

enum eDirection;
struct sPosition;

class Marker
{
private:
	bool _color;
	sPosition _sPostion;
public:
	Marker(bool color, sPosition postition);
	~Marker();


	void reverse();

	bool GetColor() { return _color; }//0�� black , 1�� white

};

