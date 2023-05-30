#include "menu.h"
#include "drawer.h"

constexpr auto MENU_TITLE = "E&M Visualizer";
constexpr auto ROBOTO_FONT_LOC = "C:\\CppLibraries\\roboto\\Roboto-Regular.ttf";
constexpr int TITLESCREEN_FONT_SIZE = 60;
constexpr int BUTTON_LABEL_FONT_SIZE = 45;
constexpr SDL_Color WHITE = { 255, 255, 255 };

Menu::Menu(Visualizer* visualizer) {
	this->_visualizer = visualizer;
	this->_renderer = visualizer->get_renderer();
	this->_title_font = NULL;
	this->_menu_title = NULL;
	this->_successful_init = init();
}

Menu::~Menu() {
	TTF_CloseFont(this->_title_font);
	TTF_CloseFont(this->_button_label_font);
	free(_menu_title);
	free(_options_title);
	free(_quit_title);
	free(&_quit_button_dim);
	free(&_options_button_dim);
}

//Might want to do a complete redesign of the menu but it is functional
void Menu::render() {
	if (!_successful_init) return;

	//Menu title code!
	if (!_title_font == NULL) {
		SDL_Rect menu_dim;
		menu_dim.w = 450, menu_dim.h = 100;
		menu_dim.x = (_visualizer->get_width() / 2) - (menu_dim.w / 2), menu_dim.y = 40;
		SDL_RenderCopy(_renderer, _menu_title, NULL, &menu_dim);
	}

	//Making the options button layout
	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(_renderer, &_options_button_dim);

	//Simulations button label code
	if (!_button_label_font == NULL) {
		SDL_Rect options_dim;
		options_dim.w = _options_button_dim.w - 130, options_dim.h = 36;
		options_dim.x = (_visualizer->get_width() / 2) - (options_dim.w / 2), options_dim.y = _options_button_dim.y + 7;
		SDL_RenderCopy(_renderer, _options_title, NULL, &options_dim);
	}

	//Making the quit button layout
	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawRect(_renderer, &_quit_button_dim);

	//Quit button label code
	if (!_button_label_font == NULL) {
		SDL_Rect quit_dim;
		quit_dim.w = _quit_button_dim.w - 234, quit_dim.h = 36;
		quit_dim.x = (_visualizer->get_width() / 2) - (quit_dim.w / 2), quit_dim.y = _quit_button_dim.y + 7;
		SDL_RenderCopy(_renderer, _quit_title, NULL, &quit_dim);
	}
}

bool Menu::init() {
	bool success = true;

	//Open the title font - TODO NEEDS CHANGE IN LIBRARY PER COMPUTER
	this->_title_font = TTF_OpenFont(ROBOTO_FONT_LOC, TITLESCREEN_FONT_SIZE);
	if (_title_font == NULL) {
		printf("Failed to load title font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}

	//Open the button font - TODO NEEDS CHANGE IN LIBRARY PER COMPUTER
	this->_button_label_font = TTF_OpenFont(ROBOTO_FONT_LOC, BUTTON_LABEL_FONT_SIZE);
	if (_button_label_font == NULL) {
		printf("Failed to load button label font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}

	//Options button dimensional work
	_options_button_dim.w = 300, _options_button_dim.h = 50;
	_options_button_dim.x = (_visualizer->get_width() / 2) - (_options_button_dim.w / 2), _options_button_dim.y = 200;

	//Quit button dimensional work
	_quit_button_dim.w = 300, _quit_button_dim.h = 50;
	_quit_button_dim.x = (_visualizer->get_width() / 2) - (_quit_button_dim.w / 2), _quit_button_dim.y = 350;

	//Writing "menu"
	this->_menu_title = Drawer::render_text(_renderer, MENU_TITLE, WHITE, _title_font);

	//Writing "simulations"
	this->_options_title = Drawer::render_text(_renderer, "Simulations", WHITE, _button_label_font);

	//Writing "quit"
	this->_quit_title = Drawer::render_text(_renderer, "Quit", WHITE, _button_label_font);

	return success;
}

SDL_Rect Menu::get_options_dim() {
	return _options_button_dim;
}

SDL_Rect Menu::get_quit_dim() {
	return _quit_button_dim;
}