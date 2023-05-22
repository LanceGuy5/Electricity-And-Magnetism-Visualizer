#pragma once

#include <SDL.h>

//Representation of every possible state that the game can be in
enum class game_state
{
	MENU,
};

class Visualizer
{
public:
	Visualizer(const char* title, int x, int y, int width, int height); //Constructor
	Visualizer(const char* title, int width, int height); //Another constructor that defualts to screen center
	~Visualizer() = default; //Might want to check about this?

	//Method to return window produced by constructor!
	SDL_Window* get_window();

	//Method to return surface given by window (assuming one exists)
	SDL_Surface* get_screen_surface();

	//Exit method for program
	void close();

	//Method to get certain state (for rendering and ticking purposes)
	game_state get_curr_state();

	//For setting the state of the game
	void set_curr_state(game_state state);

	//Method to get the renderer object
	SDL_Renderer* get_renderer();

	//Method to get the status after init
	bool get_status();

private:
	//Only want this to be used by in-class methods
	bool init();
protected:
	SDL_Window* _window;
	SDL_Surface* _screenSurface{};
	SDL_Renderer* _renderer{};
	const char* _title{};
	int _x{}, _y{}, _width{}, _height{};
	game_state _currState;
	bool _status{};
};

