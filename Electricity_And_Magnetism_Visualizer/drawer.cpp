#include "drawer.h"

#include <stdio.h>

constexpr int TITLESCREEN_FONT_SIZE = 28;

Drawer::Drawer(Visualizer* visualizer) {
	this->_visualizer = visualizer;
	this->_renderer = _visualizer->get_renderer();
	this->_title_font = NULL;
}

Drawer::~Drawer() {
	TTF_CloseFont(this->_title_font);
}

bool Drawer::init_media() {
    bool success = true;

    //Open the title font
    this->_title_font = TTF_OpenFont("D:\\FontLibraries\\roboto\\Roboto - Regular.ttf", TITLESCREEN_FONT_SIZE);
    if (_title_font == NULL)
    {
        printf("Failed to load font title! SDL_ttf Error: %s\n", TTF_GetError());
        success = false;
    }

	return success;
}

void Drawer::draw() {

	//Make sure the renderer is empty at the beginning of each render method
	SDL_RenderClear(_renderer);

	//Making a button
	SDL_Rect rect;
	rect.x = 100, rect.y = 100, rect.w = 300, rect.h = 50;
	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(_renderer, &rect);

	//Background
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);

	// Show the renderer contents
	SDL_RenderPresent(_renderer);

}

SDL_Texture* Drawer::render_text(const char* text_to_render, SDL_Color render_color) {
	return NULL; //TODO FIX
}

TTF_Font* Drawer::get_title_font() {
    return this->_title_font;
}