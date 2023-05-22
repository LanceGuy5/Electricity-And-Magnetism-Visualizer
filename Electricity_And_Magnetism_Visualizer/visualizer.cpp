#include "visualizer.h"
#include <stdio.h>
#include <cassert>

Visualizer::Visualizer(const char* title, int x, int y, int w, int h) {
	this->_title = title;
	this->_x = x;
	this->_y = y;
	this->_width = w;
	this->_height = h;

	//Fail-safe
	this->_window = NULL;
	this->_screenSurface = NULL;

	init();
}

Visualizer::Visualizer(const char* title, int w, int h) {
	this->_title = title;
	this->_x = SDL_WINDOWPOS_CENTERED;
	this->_y = SDL_WINDOWPOS_CENTERED;
	this->_width = w;
	this->_height = h;

	//Fail-safe
	this->_window = NULL;
	this->_screenSurface = NULL;

	init();
}

bool Visualizer::init() {

	//Success flag
	bool success = true;

	//Initializes SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}

	//Instantiating our window -> could add SDL_WINDOW_FULLSCREEN_DESKTOP as last arg
	this->_window = SDL_CreateWindow(this->_title, this->_x, this->_y, this->_width, this->_height, 0);

	//Check to make sure window was properly instantiated
	if (_window == NULL) {
		printf("Window could not successfully be opened. SDL_Error: %s\n", SDL_GetError());
		success = false;
	}

	//Get surface of window
	this->_screenSurface = SDL_GetWindowSurface(_window);

	//Give the surface a background
	SDL_FillRect(_screenSurface, NULL, SDL_MapRGB(_screenSurface->format, 0xFF, 0xFF, 0xFF));

	//Update the surface
	SDL_UpdateWindowSurface(_window);

	return success;
}

void Visualizer::close() {

}

SDL_Window* Visualizer::get_window() {
	assert(this->_window);
	return this->_window;
}

SDL_Surface* Visualizer::get_screen_surface() {
	assert(this->_screenSurface);
	return this->_screenSurface;
}
