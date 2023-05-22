#include "drawer.h"

#include <stdio.h>

constexpr int TITLESCREEN_FONT_SIZE = 28;

Drawer::Drawer(SDL_Renderer* renderer) {
	this->_renderer = renderer;
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
}

void Drawer::draw() {

	//Make sure the renderer is empty at the beginning of each render method
	SDL_RenderClear(_renderer);

	//Background
	SDL_SetRenderDrawColor(_renderer, 100, 149, 237, 255);

	// Show the renderer contents
	SDL_RenderPresent(_renderer);
}

SDL_Texture* Drawer::render_text(const char* text_to_render, SDL_Color render_color) {

}

TTF_Font* Drawer::get_title_font() {
    return this->_title_font;
}