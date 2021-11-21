#include "DrawableObject.h"
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
void DrawableObject::drawLine(sf::RenderWindow* target, int x0, int y0, int x1, int y1)
{
	img.create(target->getSize().x, target->getSize().y, sf::Color::Transparent);
	float deltay, deltax, m;
	deltay = y1 - y0;
	deltax = x1 - x0;
	float yy = y0;
	float xx = x0;
	m = deltay / deltax;
	if (x0 > x1) {
		float tmp = x0;
		x0 = x1;
		x1 = tmp;
		tmp = y0;
		y0 = y1;
		y1 = tmp;

		if (m > 1)
		{
			m = deltax / deltay;
			for (int y = y0; y <= y1; y++)
			{
				img.setPixel((int)(xx + 0.5), y, sf::Color::Blue);
				xx += m;
			}
		}
		else
		{
			for (int x = x0; x <= x1; x++)
			{
				img.setPixel(x, (int)(yy + 0.5), sf::Color::Blue);
				yy += m;
			}
		}
		txt.loadFromImage(img);
		arr.setTexture(txt);
		arr.setPosition(sf::Vector2f(0, 0));
		target->draw(arr);
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

