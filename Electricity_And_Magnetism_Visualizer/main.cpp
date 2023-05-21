#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#define WIDTH 1280
#define HEIGHT 720

int main(int argc, char* argv[]) {

	//Window we will be rendering to
	SDL_Window* win = NULL;

	//Surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Image stuff :)
	//SDL_Renderer* renderer = NULL;
	//SDL_Texture* img = NULL;

	//Initializes SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	//Instantiating our window -> could add SDL_WINDOW_FULLSCREEN_DESKTOP as last arg
	win = SDL_CreateWindow("Electricity and Magnetism Visualizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0); 

	//Check to make sure window was properly instantiated
	if (win == NULL) {
		printf("Window could not successfully be opened. SDL_Error: %s\n", SDL_GetError());
		return 1;
	}

	//Get surface of window for purposes :()
	screenSurface = SDL_GetWindowSurface(win);

	//Give the surface a background
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

	//Update the surface
	SDL_UpdateWindowSurface(win);

	//More image stuff :)
	/*renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	img = IMG_LoadTexture(renderer, "C:\\Users\\lance\\Desktop\\Prof2.PNG");
	if (img == nullptr) {
		std::cout << "IMG_LoadTexture Error: " << SDL_GetError() << "\n";
		return 1;
	}
	int w, h;
	SDL_QueryTexture(img, NULL, NULL, &w, &h);
	SDL_Rect texr; texr.x = 0; texr.y = 0; texr.w = w; texr.h = h;*/

	Uint32 lastUpdateTime = 0;

	//"Game" loop
	while (1) {

		//Get an SDL_Event and call it e
		SDL_Event e;

		if (SDL_PollEvent(&e)) {

			//Check to see if the event was to quit -> break loop and return out of program
			if (e.type == SDL_QUIT) {
				break;
			}

			//Check to see if the event was an escape press -> same quit as above
			else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE) {
				break;
			}

			//Re-rendering screen every 30 ticks
			/*if (lastUpdateTime + 30 < SDL_GetTicks) {
				lastUpdateTime = SDL_GetTicks();
				SDL_RenderClear(renderer);
				SDL_RenderCopy(renderer, img, NULL, &texr);
				SDL_RenderPresent(renderer);
			}*/
		}
	}

	/*SDL_DestroyTexture(img);
	SDL_DestroyRenderer(renderer);*/
	
	//Destroying window at end of loop
	SDL_DestroyWindow(win);

	//Quitting SDL at end of loop
	SDL_Quit();

	//Returning out of program successfully
	return 0;

}
