#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "visualizer.h"

#define WIDTH 1280
#define HEIGHT 720

int main(int argc, char* argv[]) {

	//Image stuff TODO MOVE TO VISUALIZER CLASS
	//SDL_Renderer* renderer = NULL;
	//SDL_Texture* img = NULL;

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

	//Should create everything and successfully initialize everything
	Visualizer visualizer("Electricity and Magnetism Visualizer", WIDTH, HEIGHT);

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

	//TODO More to move to visualizer class
	/*SDL_DestroyTexture(img);
	SDL_DestroyRenderer(renderer);*/

	visualizer.close();
	//Returning out of program successfully
	return 0;

}
