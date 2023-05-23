#pragma once

#include "visualizer.h"

#include <SDL.h>
#include <SDL_ttf.h>

class Drawer
{
public:
	Drawer(Visualizer* visualizer);
	~Drawer();

	//Initialization method
	bool init_media();

	//Method that is called every frame that draws to the screen
	void draw();

	//Method to get the font being used
	TTF_Font* get_title_font();

	//Method to render a text element
	SDL_Texture* render_text(const char* text_to_render, SDL_Color render_color);
private:
	Visualizer* _visualizer;
protected:
	SDL_Renderer* _renderer{};
	TTF_Font* _title_font{};
};

