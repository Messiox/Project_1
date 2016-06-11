/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, vectors, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "LTexture.h"
#include "Avatar.h"
#include "Functions.h"
#include "Zombie.h"
#include <list>

//The dimensions of the level
const int LEVEL_WIDTH = 1024;
const int LEVEL_HEIGHT = 768;



//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Scene textures
LTexture gAvatarTexture;
LTexture gZombieTexture;
LTexture gMapTexture;






int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//The dot that will be moving around on the screen
			Avatar avatar;
			std::list<Zombie*> zombies;
			Zombie zombie;
			int mouseX, mouseY;


			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}

					//Handle input for the dot
					avatar.handleEvent(e);
				}

				//Move the dot
				avatar.move();
				zombie.move(avatar.getPosX(),avatar.getPosY());

				SDL_GetMouseState(&mouseX, &mouseY);
				avatar.calculateAngle(mouseX, mouseY);

				//Clear screen
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);

				//Render background
				gMapTexture.render(0, 0);

				//Render objects
				avatar.render();
				
				zombie.render();

				//Update screen
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}