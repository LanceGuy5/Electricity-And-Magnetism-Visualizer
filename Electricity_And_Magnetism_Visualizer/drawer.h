#pragma once

#include "visualizer.h"
#include "menu.h"

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class Drawer
{
public:
	Drawer(Visualizer* visualizer);
	~Drawer();

	//Initialization method
	bool init_media();

	//Method that is called every frame that draws to the screen
	void draw();

	//Method to add Menu
	void add_menu(Menu* menu);

//Static public methods
public:
	//Method to render a text element
	static SDL_Texture* render_text(SDL_Renderer* _renderer, std::string text_to_render, SDL_Color render_color, TTF_Font* font);

private:
	Visualizer* _visualizer;

protected:
	SDL_Renderer* _renderer{};
	Menu* _menu;
};

