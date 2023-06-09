#include "drawer.h"

#include <stdio.h>
#include <cassert>

Drawer::Drawer(Visualizer* visualizer) {
	this->_visualizer = visualizer;
	this->_renderer = _visualizer->get_renderer();

	this->_menu = NULL;
	this->_sim_menu = NULL;
}

Drawer::~Drawer() {
	_menu->~Menu();
	_sim_menu->~SimulationsMenu();
}

//TODO Maybe depricate?
bool Drawer::init_media() {
    bool success = true;

	return success;
}

void Drawer::draw() {

	//Make sure the renderer is empty at the beginning of each render method
	SDL_RenderClear(_renderer);

	switch (_visualizer->get_curr_state()) {
		case program_state::MENU:
			assert(this->_menu);
			_menu->render();
			break;
		case program_state::SIMULATIONS_MENU:
			assert(this->_sim_menu);
			_sim_menu->render();
			break;
	}

	//Background
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);

	// Show the renderer contents
	SDL_RenderPresent(_renderer);

}

SDL_Texture* Drawer::render_text(SDL_Renderer* _renderer, std::string text_to_render, SDL_Color render_color, TTF_Font* font) {
	SDL_Surface* text_element = TTF_RenderText_Solid(font, text_to_render.c_str(), render_color);
	if (text_element == NULL) {
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
		return NULL;
	}
	else {
		SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, text_element);
		SDL_FreeSurface(text_element);
		if (texture == NULL) {
			printf("Unable to create texture from renderer text! SDL Error: %s\n", SDL_GetError());
			return NULL;
		}
		else {
			return texture;
		}
		
	}
}

void Drawer::add_menu(Menu* menu) {
	this->_menu = menu;
}

void Drawer::add_sim_menu(SimulationsMenu* sim_menu) {
	this->_sim_menu = sim_menu;
}