#include "drawer.h"

Drawer::Drawer(SDL_Renderer* renderer) {
	this->_renderer = renderer;
}

void Drawer::draw() {
	SDL_SetRenderDrawColor(_renderer, 100, 149, 237, 255);
	SDL_RenderClear(_renderer);

	// Show the renderer contents
	SDL_RenderPresent(_renderer);
}