#pragma once
struct SDL_Renderer;
class System
{
private:
	System();

public:
	static System & GetInstance()
	{
		static System * sys = new System();
		return * sys;
	}
private:
	SDL_Renderer * _renderer;
public:
	void setRenderer(SDL_Renderer * renderer);
	SDL_Renderer * GetRenderer() { return _renderer; }
	void Render();
};

System::System()
{
}
