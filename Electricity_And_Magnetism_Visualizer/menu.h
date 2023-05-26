#pragma once

#include "SDL.h"
#include "SDL_ttf.h"

#include "screen.h"
#include "visualizer.h"

class Menu : public Screen
{
public:
	Menu(Visualizer* visualizer);
	~Menu();
	//Inherited render method
	void render();

	//Methods to get certain elements of the menu
	SDL_Rect get_options_dim();
	SDL_Rect get_quit_dim();
private:
	bool init();
	bool _successful_init;

	Visualizer* _visualizer;
	SDL_Renderer* _renderer;

	//Different sized fonts
	TTF_Font* _title_font;
	TTF_Font* _button_label_font;

	//Actual renderer elements
	SDL_Texture* _menu_title;
	SDL_Texture* _options_title;
	SDL_Texture* _quit_title;
protected:
	SDL_Rect _options_button_dim;
	SDL_Rect _quit_button_dim;
};

