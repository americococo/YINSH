#include "System.h"
#include "../Map/MapManager.h"
void System::setRenderer(SDL_Renderer * renderer)
{
	_renderer = renderer;
}
void System::Render()
{
	MapManager::GetInstance().Render();

	//���콺 ���ٴ�� ��ġ
}
System::System()
{
}