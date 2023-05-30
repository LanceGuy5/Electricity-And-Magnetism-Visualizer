#pragma once

#include "screen.h"
#include "visualizer.h"

#include <SDL_ttf.h>

class SimulationsMenu : public Screen
{
public:
	SimulationsMenu(Visualizer* visualizer);
	~SimulationsMenu();

	//For eventManager
	SDL_Rect get_sim_one_dim();
	SDL_Rect get_sim_two_dim();
	SDL_Rect get_sim_three_dim();
	SDL_Rect get_sim_four_dim();
	SDL_Rect get_sim_five_dim();
	SDL_Rect get_sim_six_dim();
	SDL_Rect get_sim_seven_dim();
	SDL_Rect get_sim_eight_dim();
	SDL_Rect get_back_dim();

	//Inherited
	void render();
private:
	bool init();
	bool _successful_init;
	Visualizer* _visualizer;
	SDL_Renderer* _renderer;

	TTF_Font* _simu_title_font;
	TTF_Font* _button_label_font;

	SDL_Texture* _simu_title_tex;
	SDL_Texture* _simu_one_tex;

	SDL_Texture* _simu_back_tex;

	SDL_Rect _sim_one_dim;
	SDL_Rect _sim_two_dim;
	SDL_Rect _sim_three_dim;
	SDL_Rect _sim_four_dim;
	SDL_Rect _sim_five_dim;
	SDL_Rect _sim_six_dim;
	SDL_Rect _sim_seven_dim;
	SDL_Rect _sim_eight_dim;
	SDL_Rect _back_dim;
};

