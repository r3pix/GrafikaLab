#pragma once
#include "Point2D.h"
class LineSegment
{public:
	Point2D A, B;

	void SetA(int x, int y);
	void SetB(int x, int y);

	Point2D GetA();
	Point2D GetB();

	LineSegment();
	LineSegment(int xa, int ya, int xb, int yb);

	void DrawLine(sf::RenderWindow *target);
};

