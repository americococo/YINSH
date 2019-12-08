#include "System.h"
#include "../Map/MapManager.h"
void System::setRenderer(SDL_Renderer * renderer)
{
	_renderer = renderer;
}
void System::Render()
{
	SDL_Renderer * renderer = System::GetInstance().GetRenderer();
	MapManager::GetInstance().Render();

}
System::System()
{
}