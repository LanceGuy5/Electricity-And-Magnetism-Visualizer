#pragma once

//This header file is just an abstract class that represents a screen.
//For example, the menu is just a specific screen with a predetermined layout.
class Screen
{
public:
	//Each screen has a render method that is called when its visualizer state is achieved
	virtual void render() = 0;
private:
	bool init();
	bool _successful_init;
};

