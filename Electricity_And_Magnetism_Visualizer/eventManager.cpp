#include "eventManager.h"

#include <cassert>
#include <iostream>

constexpr bool NONFUNCTIONAL = false;
constexpr bool FUNCTIONAL = true;

EventManager::EventManager(Visualizer* visualizer) {
	this->_visualizer = visualizer;
	this->_menu = NULL;
	this->_sim_menu = NULL;
}

void EventManager::add_menu(Menu* menu) {
	this->_menu = menu;
}

void EventManager::add_sim_menu(SimulationsMenu* sim_menu) {
	this->_sim_menu = sim_menu;
}

//This is gonna be a long method
//Make sure if statement stays in order of screen initialization :)
bool EventManager::event_handler(SDL_Event* e) {
	if (_visualizer->get_curr_state() == program_state::MENU) {
		return menu_event_handler(e);
	}
}

//Menu event handling
bool EventManager::menu_event_handler(SDL_Event* e) {
	assert(_menu);
	if (e->type == SDL_MOUSEBUTTONUP) {
		if (click_between(e->button.x,
				_menu->get_options_dim().x, _menu->get_options_dim().w + _menu->get_options_dim().x) &&
			click_between(e->button.y,
				_menu->get_options_dim().y, _menu->get_options_dim().h + _menu->get_options_dim().y)){
			_visualizer->set_curr_state(program_state::SIMULATIONS_MENU);
			return FUNCTIONAL;
		}else if(click_between(e->button.x,
				_menu->get_quit_dim().x, _menu->get_quit_dim().w + _menu->get_quit_dim().x) &&
			click_between(e->button.y,
				_menu->get_quit_dim().y, _menu->get_quit_dim().h + _menu->get_quit_dim().y)){
			return NONFUNCTIONAL;
		}
	}
	return FUNCTIONAL;
}

bool EventManager::click_between(int click, int v1, int v2) {
	return (click > v1 && click < v2);
}