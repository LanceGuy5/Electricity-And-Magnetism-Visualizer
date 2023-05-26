#include "simulationsMenu.h"

#include <stdio.h>

#include "drawer.h"

constexpr int SIMU_TITLE_SIZE = 105;
constexpr auto ROBOTO_FONT_LOC = "C:\\CppLibraries\\roboto\\Roboto-Regular.ttf";
constexpr SDL_Color WHITE = { 255, 255, 255 };

SimulationsMenu::SimulationsMenu(Visualizer* visualizer) {
	this->_visualizer = visualizer;
	this->_renderer = visualizer->get_renderer();
	this->_successful_init = init();
}

SimulationsMenu::~SimulationsMenu() {
	TTF_CloseFont(_simu_title_font);
	free(_simu_title_tex);
}

bool SimulationsMenu::init() {
	bool success = true;

	//Open the title font - TODO NEEDS CHANGE IN LIBRARY PER COMPUTER
	this->_simu_title_font = TTF_OpenFont(ROBOTO_FONT_LOC, SIMU_TITLE_SIZE);
	if (_simu_title_font == NULL) {
		printf("Failed to load simulation title font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}

	//Writing "menu"
	this->_simu_title_tex = Drawer::render_text(_renderer, "Simulations", WHITE, _simu_title_font);

	return success;
}

//Different simulations:
//1-3. Electrostatics -> balloon with electrons, electrostatic forces, E-field
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
}