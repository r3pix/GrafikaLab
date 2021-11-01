#pragma once
#include <SFML/Graphics.hpp>
class Point2D
{
public:
	float x, y;

	void SetX(float x);
	void SetY(float y);

	float GetX();
	float GetY();


	Point2D();
	Point2D(float x, float y);
	void DrawPoint(sf::RenderWindow *target);
};

