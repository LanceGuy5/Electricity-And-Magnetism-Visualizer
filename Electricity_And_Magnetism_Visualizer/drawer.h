#pragma once

#include <SDL.h>

class Drawer
{
public:
	Drawer(SDL_Renderer* renderer);
	~Drawer() = default;

	//Method that is called every frame that draws to the screen
	void draw();
private:

protected:
	SDL_Renderer* _renderer{};
};

