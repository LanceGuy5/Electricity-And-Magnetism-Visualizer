#pragma once

#include "SDL.h"
#include "SDL_ttf.h"

#include "screen.h";
#include "visualizer.h"

class Menu : public Screen
{
public:
	Menu(Visualizer* visualizer);
	~Menu();
	//Inherited render method
	void render();
private:
	bool init();
	bool _successful_init;
protected:
	Visualizer* _visualizer;
	SDL_Renderer* _renderer;

	//Different sized fonts
	TTF_Font* _title_font;
	TTF_Font* _button_label_font;

	//Actual renderer elements
	SDL_Texture* _menu_title;
	SDL_Texture* _options_title;
};

