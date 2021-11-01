#pragma once

#include <SFML/Graphics.hpp>
#include<vector>
#include "LineSegment.h"

class PrimitiveRenderer
{
public:
	static void drawCircle(sf::RenderWindow *target);
	static void drawRectangle(sf::RenderWindow *target);
	static void drawTringle(sf::RenderWindow *target);
	static void drawSquare(sf::RenderWindow *target);
	static void drawLine(sf::RenderWindow* target, int x0, int y0, int x1, int y1);
	static void drawPoint(sf::RenderWindow *target, int x, int y);
	static void drawCustomLine(sf::RenderWindow * target, std::vector<LineSegment> lines);
	static void drawCustomCircle(sf::RenderWindow *target, int x0, int y0, int r);
	static void drawCustomElipse(sf::RenderWindow* target, int x0, int y0, int rx, int ry);
};

