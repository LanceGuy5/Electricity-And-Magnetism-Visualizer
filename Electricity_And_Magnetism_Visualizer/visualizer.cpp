#include "visualizer.h"

#include <SDL_ttf.h>
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
	this->_renderer = NULL;

	this->_status = init();
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
	this->_renderer = NULL;

	this->_status = init();
}

Visualizer::~Visualizer() {
	
	SDL_DestroyRenderer(this->_renderer);
	SDL_DestroyWindow(this->_window);
	TTF_Quit();
	SDL_Quit();
}

bool Visualizer::init() {

	//Success flag
	bool success = true;

	//Initializes SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}

	if (TTF_Init() == -1) {
		printf("SDL_ttf could not initialize! TTF_Error: %s\n", TTF_GetError());
		success = false;
	}

	//Instantiating our window -> could add SDL_WINDOW_FULLSCREEN_DESKTOP as last arg
	this->_window = SDL_CreateWindow(this->_title, this->_x, this->_y, this->_width, this->_height, SDL_WINDOW_RESIZABLE);

	//Check to make sure window was properly instantiated
	if (_window == NULL) {
		printf("Window could not successfully be opened. SDL_Error: %s\n", SDL_GetError());
		success = false;
	}

	//TODO Do I want to use screen surface or renderer?
	// 
	//Get surface of window
	this->_screenSurface = SDL_GetWindowSurface(_window);
	//Give the surface a background
	//SDL_FillRect(_screenSurface, NULL, SDL_MapRGB(_screenSurface->format, 0xFF, 0xFF, 0xFF));
	//Update the surface
	SDL_UpdateWindowSurface(_window);

	//Renderer code here
	this->_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (this->_renderer == NULL) {
		printf("Renderer was not instantiated properly. SDL_Error: %s\n", SDL_GetError());
		success = false;
	}

	set_curr_state(program_state::MENU);

	return success;
}

void Visualizer::tick() {
	//All mouse management stuff goes in here
}

SDL_Window* Visualizer::get_window() {
	assert(this->_window);
	return this->_window;
}

SDL_Surface* Visualizer::get_screen_surface() {
	assert(this->_screenSurface);
	return this->_screenSurface;
}

program_state Visualizer::get_curr_state() {
	return this->_currState;
}

void Visualizer::set_curr_state(program_state state) {
	this->_currState = state;
}

SDL_Renderer* Visualizer::get_renderer() {
	assert(this->_renderer);
	return this->_renderer;
}

bool Visualizer::get_status() {
	return this->_status;
}

int Visualizer::get_width() {
	return SDL_GetWindowSurface(_window)->w;
}

int Visualizer::get_height() {
	return SDL_GetWindowSurface(_window)->h;
}
