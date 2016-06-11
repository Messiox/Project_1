#include "Functions.h"
#include "LTexture.h"
#include "Zombie.h"

extern const int SCREEN_WIDTH = 1024;
extern const int SCREEN_HEIGHT = 768;



extern SDL_Renderer* gRenderer;
extern SDL_Window* gWindow;
extern LTexture gAvatarTexture;
extern LTexture gMapTexture;
extern LTexture gZombieTexture;
extern list<Zombie*> zombie;
bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("Project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load dot texture
	if (!gAvatarTexture.loadFromFile("Avatar.png"))
	{
		printf("Failed to load Av texture!\n");
		success = false;
	}

	if (!gZombieTexture.loadFromFile("Zombie.png"))
	{
		printf("Failed to load zombie texture!\n");
		success = false;
	}

	//Load background texture
	if (!gMapTexture.loadFromFile("Map.png"))
	{
		printf("Failed to load Map texture!\n");
		success = false;
	}

	return success;
}

void close()
{
	//Free loaded images
	gAvatarTexture.free();
	gMapTexture.free();
	gZombieTexture.free();

	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}