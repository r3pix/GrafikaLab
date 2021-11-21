#pragma once

#include <SFML/Graphics.hpp>
#include<vector>
#include "LineSegment.h"

class PrimitiveRenderer
{
public:

	sf::Image img;
	sf::Texture txt;
	sf::Sprite arr;
	void drawCircleUnfilled(sf::RenderWindow *target, sf::Vector2f pos);
	void drawRectangleUnfilled(sf::RenderWindow *target, sf::Vector2f pos);
	void drawTringleUnfilled(sf::RenderWindow *target, sf::Vector2f pos);
	void drawSquare(sf::RenderWindow *target, sf::Vector2f pos, sf::Color color);
	void drawSquareUnfilled(sf::RenderWindow* target, sf::Vector2f pos);
	void drawCircle(sf::RenderWindow* target, sf::Vector2f pos, sf::Color color);
	void drawRectangle(sf::RenderWindow* target, sf::Vector2f pos, sf::Color color);
	void drawTringle(sf::RenderWindow* target, sf::Vector2f pos, sf::Color color);
	void drawLine(sf::RenderWindow *target, int x0, int y0, int x1, int y1);
	void drawLinee(sf::Image& target, int x0, int y0, int x1, int y1);
	void drawPoint(sf::Image& target, int x, int y);
	void drawCustomLine(sf::RenderWindow * target, std::vector<LineSegment> lines);
	void drawCustomCircle(sf::RenderWindow *target, int x0, int y0, int r);
	void drawCustomElipse(sf::RenderWindow* target, int x0, int y0, int rx, int ry);
	void drawCustomFigure(sf::RenderWindow* target, std::vector<LineSegment>points);
	void fillFigure(sf::Image &target, sf::Color colorI, sf::Color colorIn, int x, int y);
	void drawPoint(sf::Image& target, int x, int y, sf::Color color);
	void drawCustomFigureWithFill(sf::RenderWindow* target, std::vector<LineSegment> lines);
};

