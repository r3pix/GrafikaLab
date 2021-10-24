#pragma once

#include <SFML/Graphics.hpp>

class PrimitiveRenderer
{
public:
	static void drawCircle(sf::RenderWindow *target);
	static void drawRectangle(sf::RenderWindow *target);
	static void drawTringle(sf::RenderWindow *target);
	static void drawSquare(sf::RenderWindow *target);
	static void drawLine(sf::RenderWindow* target, int x0, int y0, int x1, int y1);
	static void drawPixel(sf::RenderWindow *target);
};

