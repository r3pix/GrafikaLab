#pragma once
#include "ShapeObject.h"

class PrimitiveTriangle:public ShapeObject
{
private:
	int x0, y0, x1, y1;
public:
	PrimitiveTriangle(int x, int y, int x1, int y1);
	PrimitiveTriangle(int x, int y, int x1, int y1, sf::Color color);
	void draw(sf::RenderWindow* target);
	void draw(sf::RenderWindow* target, sf::Color color);
	void translate(sf::Vector2f translate);
	void rotate(float rotation) override;
	void scale(float k) override;
};

