#pragma once
#include <map>
#include <SDL.h>
class InputSystem
{

public:
	InputSystem();
	static InputSystem & GetInstance()
	{
		static InputSystem * instance = new InputSystem();
		return * instance;
	}


	~InputSystem() {}



private:
	bool _mouseDown;
	int _x, _y;
public:
	void SetMousePosition(int x, int y) { _x = x; _y = y; }

	void MouseDown() { _mouseDown = true;  }
	void MouseUp() { _mouseDown = false;}

	int GetMousePositionX() { return _x; }
	int GetMousePositionY() { return _y; }

	bool isMouseDown() { return _mouseDown; }



private:
	std::map<int, bool> _input;

public:
	void KeyUp(int code) { _input[code] = true; }
	void KeyDown(int code){ _input[code] = false; }

	bool IsInputKey(int code) { return _input[code]; }
};

