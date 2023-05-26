#pragma once

#include "screen.h"
#include "visualizer.h"

#include <SDL_ttf.h>

class SimulationsMenu : public Screen
{
public:
	SimulationsMenu(Visualizer* visualizer);
	~SimulationsMenu();

	//Inherited
	void render();
private:
	bool init();
	bool _successful_init;
	Visualizer* _visualizer;
	SDL_Renderer* _renderer;

	TTF_Font* _simu_title_font;

	SDL_Texture* _simu_title_tex;
};

