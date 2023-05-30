#include "simulationsMenu.h"

#include <stdio.h>

#include "drawer.h"

constexpr int SIMU_TITLE_SIZE = 105;
constexpr int BUTTON_LABEL_FONT_SIZE = 45;
constexpr auto ROBOTO_FONT_LOC = "C:\\CppLibraries\\roboto\\Roboto-Regular.ttf";
constexpr SDL_Color WHITE = { 255, 255, 255 };

SimulationsMenu::SimulationsMenu(Visualizer* visualizer) {
	this->_visualizer = visualizer;
	this->_renderer = visualizer->get_renderer();
	this->_successful_init = init();
}

SimulationsMenu::~SimulationsMenu() {
	TTF_CloseFont(_simu_title_font);
	TTF_CloseFont(_button_label_font);

	free(_simu_title_tex);
	free(_simu_one_tex);
	free(_simu_back_tex);
	
	free(&_sim_one_dim);
	free(&_sim_two_dim);
	free(&_sim_three_dim);
	free(&_sim_four_dim);
	free(&_sim_five_dim);
	free(&_sim_six_dim);
	free(&_sim_seven_dim);
	free(&_sim_eight_dim);
	free(&_back_dim);

}

bool SimulationsMenu::init() {
	bool success = true;

	//Open the title font - TODO NEEDS CHANGE IN LIBRARY PER COMPUTER
	this->_simu_title_font = TTF_OpenFont(ROBOTO_FONT_LOC, SIMU_TITLE_SIZE);
	if (_simu_title_font == NULL) {
		printf("Failed to load simulation title font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}

	//Open the button font - TODO NEEDS CHANGE IN LIBRARY PER COMPUTER
	this->_button_label_font = TTF_OpenFont(ROBOTO_FONT_LOC, BUTTON_LABEL_FONT_SIZE);
	if (_button_label_font == NULL) {
		printf("Failed to load button label font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}

	//Dimensions for left half of buttons button:
	_sim_one_dim.w = 300, _sim_one_dim.h = 50;
	_sim_one_dim.x = (_visualizer->get_width() / 4) - (_sim_one_dim.w / 2), _sim_one_dim.y = 150;

	_sim_two_dim.w = 300, _sim_two_dim.h = 50;
	_sim_two_dim.x = (_visualizer->get_width() / 4) - (_sim_two_dim.w / 2), _sim_two_dim.y = 240;

	_sim_three_dim.w = 300, _sim_three_dim.h = 50;
	_sim_three_dim.x = (_visualizer->get_width() / 4) - (_sim_three_dim.w / 2), _sim_three_dim.y = 330;

	_sim_four_dim.w = 300, _sim_four_dim.h = 50;
	_sim_four_dim.x = (_visualizer->get_width() / 4) - (_sim_four_dim.w / 2), _sim_four_dim.y = 420;

	//Dimensions for right half of buttons button:
	_sim_five_dim.w = 300, _sim_five_dim.h = 50;
	_sim_five_dim.x = _visualizer->get_width() - (_visualizer->get_width() / 4) - (_sim_five_dim.w / 2);
	_sim_five_dim.y = _sim_one_dim.y;

	_sim_six_dim.w = 300, _sim_six_dim.h = 50;
	_sim_six_dim.x = _visualizer->get_width() - (_visualizer->get_width() / 4) - (_sim_six_dim.w / 2);
	_sim_six_dim.y = _sim_two_dim.y;

	_sim_seven_dim.w = 300, _sim_seven_dim.h = 50;
	_sim_seven_dim.x = _visualizer->get_width() - (_visualizer->get_width() / 4) - (_sim_seven_dim.w / 2);
	_sim_seven_dim.y = _sim_three_dim.y;

	_sim_eight_dim.w = 300, _sim_eight_dim.h = 50;
	_sim_eight_dim.x = _visualizer->get_width() - (_visualizer->get_width() / 4) - (_sim_eight_dim.w / 2);
	_sim_eight_dim.y = _sim_four_dim.y;

	//Back dimensions
	_back_dim.w = 120, _back_dim.h = 50;
	_back_dim.x = (_visualizer->get_width() / 2) - (_back_dim.w / 2);
	_back_dim.y = 510;

	//Writing "Simulations"
	this->_simu_title_tex = Drawer::render_text(_renderer, "Simulations", WHITE, _simu_title_font);

	//Writing "Electric Field"
	this->_simu_one_tex = Drawer::render_text(_renderer, "Electric Field", WHITE, _button_label_font);

	//Writing "Back"
	this->_simu_back_tex = Drawer::render_text(_renderer, "Back", WHITE, _button_label_font);

	return success;
}

//Different simulations:
//1-3. Electrostatics -> balloon with electrons, electrostatic forces, E-field, Conductor vs. non-conductor
//4. Gauss's Law (Electric Flux)
//5. Figure out rest later
//8 Total
void SimulationsMenu::render() {
	if (!_successful_init) return;

	//Menu title code!
	if (!_simu_title_font == NULL) {
		SDL_Rect simu_title_dim;
		simu_title_dim.w = 450, simu_title_dim.h = 100;
		simu_title_dim.x = (_visualizer->get_width() / 2) - (simu_title_dim.w / 2), simu_title_dim.y = 40;
		SDL_RenderCopy(_renderer, _simu_title_tex, NULL, &simu_title_dim);
	}

	//All button labeling in here!!!
	if (!_button_label_font == NULL) {
		//Simulation one button
		SDL_Rect simu_one;
		simu_one.w = 200, simu_one.h = 36;
		simu_one.x = _sim_one_dim.x + 50, simu_one.y = _sim_one_dim.y + 7;
		SDL_RenderCopy(_renderer, _simu_one_tex, NULL, &simu_one);

		//Back button
		SDL_Rect simu_back;
		simu_back.w = 70, simu_back.h = 36;
		simu_back.x = (_visualizer->get_width() / 2) - (simu_back.w / 2), simu_back.y = _back_dim.y + 7;
		SDL_RenderCopy(_renderer, _simu_back_tex, NULL, &simu_back);
	}

	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawRect(_renderer, &_sim_one_dim);
	SDL_RenderDrawRect(_renderer, &_sim_two_dim);
	SDL_RenderDrawRect(_renderer, &_sim_three_dim);
	SDL_RenderDrawRect(_renderer, &_sim_four_dim);
	SDL_RenderDrawRect(_renderer, &_sim_five_dim);
	SDL_RenderDrawRect(_renderer, &_sim_six_dim);
	SDL_RenderDrawRect(_renderer, &_sim_seven_dim);
	SDL_RenderDrawRect(_renderer, &_sim_eight_dim);
	SDL_RenderDrawRect(_renderer, &_back_dim);
}

SDL_Rect SimulationsMenu::get_sim_one_dim() {
	return this->_sim_one_dim;
}

SDL_Rect SimulationsMenu::get_sim_two_dim() {
	return this->_sim_two_dim;
}

SDL_Rect SimulationsMenu::get_sim_three_dim() {
	return this->_sim_three_dim;
}

SDL_Rect SimulationsMenu::get_sim_four_dim() {
	return this->_sim_four_dim;
}

SDL_Rect SimulationsMenu::get_sim_five_dim() {
	return this->_sim_five_dim;
}

SDL_Rect SimulationsMenu::get_sim_six_dim() {
	return this->_sim_six_dim;
}

SDL_Rect SimulationsMenu::get_sim_seven_dim() {
	return this->_sim_seven_dim;
}

SDL_Rect SimulationsMenu::get_sim_eight_dim() {
	return this->_sim_eight_dim;
}

SDL_Rect SimulationsMenu::get_back_dim() {
	return this->_back_dim;
}