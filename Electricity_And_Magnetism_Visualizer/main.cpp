//General includes
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

//MY includes :)
#include "visualizer.h"
#include "drawer.h"

#define WIDTH 1280
#define HEIGHT 720

int main(int argc, char* argv[]) {

	//Image stuff TODO MOVE TO VISUALIZER CLASS
	//SDL_Texture* img = NULL;

	//More image stuff :)
	/*
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
	if (!visualizer.get_status()) return 1;

	//Drawer instantiation
	Drawer drawer(&visualizer);

	//Variable to keep track of tick speed
	Uint32 lastUpdateTime = 0;

	//Main loop
	while (1) {

		//Get an SDL_Event and call it e
		SDL_Event e;

		//If an event is qeued, add it to e and check conditions:
		if (SDL_PollEvent(&e)) {

			//Check to see if the event was to quit -> break loop and return out of program
			if (e.type == SDL_QUIT) {
				break;
			}

			//Check to see if the event was an escape press -> same quit as above
			else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE) {
				break;
			}

			drawer.draw();
		}
	}

	//TODO More to move to visualizer class
	/*SDL_DestroyTexture(img);
	SDL_DestroyRenderer(renderer);*/

	visualizer.close();
	//Returning out of program successfully
	return 0;

}
