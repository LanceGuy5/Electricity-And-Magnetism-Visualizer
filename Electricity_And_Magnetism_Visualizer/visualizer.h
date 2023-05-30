#pragma once

#include <SDL.h>

//Representation of every possible state that the game can be in
enum class program_state
{
	MENU,
	SIMULATIONS_MENU,
	E_FIELD_SIM
};

class Visualizer
{
public:
	Visualizer(const char* title, int x, int y, int width, int height); //Constructor
	Visualizer(const char* title, int width, int height); //Another constructor that defualts to screen center
	~Visualizer(); //Might want to check about this?

	//Method to return window produced by constructor!
	SDL_Window* get_window();

	//Method to return surface given by window (assuming one exists)
	SDL_Surface* get_screen_surface();

	//Method to get certain state (for rendering and ticking purposes)
	program_state get_curr_state();

	//For setting the state of the game
	void set_curr_state(program_state state);

	//Method to get the renderer object
	SDL_Renderer* get_renderer();

	//Method to get the status after init
	bool get_status();

	//Methods to get the width and height of the window
	int get_width();
	int get_height();

	//Method to tick and handle different events from the PollEvent thing
	void tick();

private:
	//Only want this to be used by in-class methods
	bool init();
protected:
	SDL_Window* _window;
	SDL_Surface* _screenSurface{};
	SDL_Renderer* _renderer{};
	const char* _title{};
	int _x{}, _y{}, _width{}, _height{};
	program_state _currState;
	bool _status{};
};

