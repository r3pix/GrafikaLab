#include "DrawableObject.h"
#include <iostream>
#include <cmath>
DrawableObject::DrawableObject() {
	this->position = sf::Vector2f(0.f, 0.f);
}
void DrawableObject::setColor(sf::Color color)
{
	this->color = color;
}
void DrawableObject::setPosition(sf::Vector2f position)
{
	this->position = position;
}
void DrawableObject::drawLine(sf::Image& ar,int x0,int y0,int x1,int y1)
{
    double xStart = x0;
    double yStart = y0;

    double xEnd = x1;
    double yEnd =y1;


    if (abs(xStart - xEnd) > abs(yStart - yEnd)) {




        if (x0 > x1) {
            xStart = x1;
            xEnd = x0;

            yStart =y1;
            yEnd = y0;
        }

        double m = (yEnd - yStart) / (xEnd - xStart);

        double y = yStart;
        for (double i = xStart; i <= xEnd; i += 1.f) {
            ar.setPixel(i, std::round(y), color);
            y += m;
        }
    }
    else {

        if (y0 >y1) {
            xStart = x1;
            xEnd = x0;

            yStart =y1;
            yEnd = y0;
        }

        double m = (xEnd - xStart) / (yEnd - yStart);

        double y = xStart;
        for (double i = yStart; i <= yEnd; i += 1.f) {

            ar.setPixel(std::round(y), i, color);

            y += m;
        }
    }
}

void DrawableObject::fillColor(sf::Image& img, sf::Color colorI, sf::Color colorIn, int x, int y)
{
	if (img.getPixel(x, y) == colorI) return;
	if (img.getPixel(x, y) == colorIn) return;

	img.setPixel(x, y, colorIn);

	fillColor(img, colorI, colorIn, x + 1, y);
	fillColor(img, colorI, colorIn, x - 1, y);
	fillColor(img, colorI, colorIn, x, y + 1);
	fillColor(img, colorI, colorIn, x, y - 1);
}

