#include "Turn/TurnManager.h"
#include "System/System.h"
#include "System/InputSystem.h"
#include <SDL.h>
#include <thread>
#include <future>


int main(int argc, char * argv[])
{
	bool isend;
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window * SDL_win =
		SDL_CreateWindow("YINSH", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			800, 600, SDL_WINDOW_OPENGL);

	System::GetInstance().setRenderer(SDL_CreateRenderer(SDL_win, -1, 0));
	SDL_SetRenderDrawColor(System::GetInstance().GetRenderer(), 255, 0, 0, 255);

	SDL_Event Event;

	int frame = 0, oldFrame = 0;
	int curtick = SDL_GetTicks();
	int oldTick = curtick;


	while (true)
	{
		curtick = SDL_GetTicks();//

		frame = (SDL_GetTicks() % 1000) * 60;

		frame /= 1000;

		if (oldFrame != frame)
		{
			oldFrame = frame;

			int deltaTime = curtick - oldTick;
			oldTick = curtick;

			if (SDL_PollEvent(&Event))
			{
				//InputSystem::GetInstance().EventPro(&Event);
				if (SDL_QUIT == Event.type)
					break;

				if (SDL_KEYUP == Event.type)
				{
					if (Event.key.keysym.sym == SDLK_ESCAPE)
					{
						SDL_Event quitEvent;
						quitEvent.type = SDL_QUIT;
						SDL_PushEvent(&quitEvent);
					}
					InputSystem::GetInstance().KeyUp(Event.key.keysym.sym);
				}
				if (SDL_KEYDOWN == Event.type)
				{
					InputSystem::GetInstance().KeyDown(Event.key.keysym.sym);
				}
				if (SDL_MOUSEMOTION == Event.type)
				{
					InputSystem::GetInstance().SetMousePosition(Event.button.x, Event.button.y);
				}

				if (SDL_MOUSEBUTTONDOWN == Event.type)
				{
					InputSystem::GetInstance().MouseDown();
				}
				if (SDL_MOUSEBUTTONUP == Event.type)
				{
					InputSystem::GetInstance().MouseUp();
				}

			}

			SDL_RenderClear(System::GetInstance().GetRenderer());
			System::GetInstance().Render();
			SDL_RenderPresent(System::GetInstance().GetRenderer());

			
			isend = TurnManager::GetInstance().Update();

			
			SDL_RenderClear(System::GetInstance().GetRenderer());
			System::GetInstance().Render();
			SDL_RenderPresent(System::GetInstance().GetRenderer());

			if (isend)
				break;
		}
	}
	SDL_DestroyRenderer(System::GetInstance().GetRenderer());
	return 0;
}