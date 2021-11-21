#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Engine
{
	sf::RectangleShape background;
	sf::Event event;
	int width, height, style;
	int fps;
	std::string title;
	sf::RenderWindow* window;

public:
	Engine(std::string title, int width, int height);
	Engine(std::string title, int width, int height, int mode);
	~Engine();
	void SetFps(int fps);
	void run();
	void clear();
};

