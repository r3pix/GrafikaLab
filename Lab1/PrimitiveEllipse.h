#pragma once
#include "ShapeObject.h"

class PrimitiveEllipse : public ShapeObject
{
private:
	int x0, y0;
public:
	PrimitiveEllipse(int x, int y);
	PrimitiveEllipse(int x, int y, sf::Color color);
	void draw(sf::RenderWindow* target) override;
	void draw(sf::RenderWindow* target, sf::Color color);
	void translate(int x, int y) override;
	void rotate(float rotation) override;
	void scale(float k) override;
};


