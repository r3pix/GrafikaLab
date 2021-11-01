#pragma once
#include "Point2D.h"
class LineSegment
{public:
	Point2D A, B;

	void SetA(float x, float y);
	void SetB(float x, float y);

	Point2D GetA();
	Point2D GetB();

	LineSegment();
	LineSegment(float xa, float ya, float xb, float yb);

	void DrawLine(sf::RenderWindow *target);
};

