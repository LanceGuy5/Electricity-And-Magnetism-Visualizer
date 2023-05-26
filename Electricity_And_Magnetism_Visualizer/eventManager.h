#pragma once

#include "visualizer.h"
#include "menu.h"
#include "simulationsMenu.h"

class EventManager
{
public:
	EventManager(Visualizer* visualizer);
	~EventManager() = default;

	//Method to actually handle the events
	bool event_handler(SDL_Event* e);

	//Have to unfortunately add each screen to eventmanager as well :(
	void add_menu(Menu* menu);
	void add_sim_menu(SimulationsMenu* sim_menu);

//All events for each different screen exist here
private:
	bool menu_event_handler(SDL_Event* e);
	bool click_between(int click, int v1, int v2);
private:
	Visualizer* _visualizer;
	Menu* _menu;
	SimulationsMenu* _sim_menu;
};

