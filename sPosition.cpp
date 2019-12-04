#include "sPosition.h"

bool samePostion(sPosition  a, sPosition b)
{
	if (a._x == b._x)
		if (a._y == b._y)
			return true;
	return false;
}
void setPosition(sPosition  to, sPosition  from)
{
	to = from;
}
sPosition  addPosition(sPosition  a, sPosition  b)
{
	int x = a._x + b._x;
	int y = a._y + b._y;
	sPosition  c;
	c._x = x;
	c._y = y;
	return c;
}