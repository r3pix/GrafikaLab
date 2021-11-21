#pragma once
#include "ShapeObject.h"

class PrimitiveCircle : public ShapeObject
{
private:
	int x0, y0, r;
public:
	PrimitiveCircle(int x, int y, int r);
	PrimitiveCircle(int x, int y, int r, sf::Color color);
	void draw(sf::RenderWindow* target) override;
	void draw(sf::RenderWindow* target, sf::Color color);
	void translate(sf::Vector2f translate) override;
	void rotate(float rotation) override;
	void scale(float k) override;
};

