#pragma once
struct sPosition
{
    /* data */
    int _x;
    int _y;
};

sPosition  addPosition(sPosition  a, sPosition  b);
void setPosition(sPosition  to, sPosition  from);
bool samePostion(sPosition  a, sPosition b);

enum eDirection
{
    eNorth,
    eNorthEast,
    eSouthEast,
    eSouth,
    eSouthWest,
    eNorthWest,
};

static sPosition vector[6] =
{
	{  0,  1},
	{  1,  1},
	{  1,  0},
	{  0,  -1},
	{  -1,  -1},
	{  -1,  0}
};

        //  vector N  = ( 0,  1)
        //  vector NE = ( 1,  1)
        //  vector SE = ( 1,  0)
        //  vector S  = ( 0, -1)
        //  vector SW = (-1, -1)
        //  vector NW = (-1,  0)