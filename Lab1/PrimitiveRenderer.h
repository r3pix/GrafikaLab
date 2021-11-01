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
	static void drawLine(sf::RenderWindow* target, float x0, float y0, float x1, float y1);
	static void drawPoint(sf::RenderWindow *target, float x, float y);
	static void drawCustomLine(sf::RenderWindow * target, std::vector<LineSegment> lines);
	static void drawCustomCircle(sf::RenderWindow *target, float x0, float y0, float r);
	static void drawCustomElipse(sf::RenderWindow* target, float x0, float y0, float rx, float ry);
};

