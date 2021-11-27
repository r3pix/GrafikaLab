#include "PrimitiveEllipse.h"
#include "PrimitiveRenderer.h"

PrimitiveEllipse::PrimitiveEllipse(int x, int y) {
	this->x0 = x;
	this->y0 = y;
}

PrimitiveEllipse::PrimitiveEllipse(int x, int y, sf::Color color) {
	this->x0 = x;
	this->y0 = y;
	this->color = color;
}

void PrimitiveEllipse::draw(sf::RenderWindow* target, sf::Color color) {
	img.create(target->getSize().x, target->getSize().y, sf::Color::Transparent);
	float a, step;
	int x, y;
	PrimitiveRenderer prim;
	step = 1.0 / std::max(x0,y0);

	for (a = 0; a <= M_PI / 2; a += step)
	{
		x = std::ceil(x0 * cos(a));
		y = std::ceil(y0 * sin(a));

		prim.drawPoint(img, x0 + x, y0 + y, this->color);
		prim.drawPoint(img, x0 - x, y0 - y, this->color);
		prim.drawPoint(img, x0 + x, y0 - y, this->color);
		prim.drawPoint(img, x0 - x, y0 + y, this->color);

	}
	//domalowanie dziur
	//PrimitiveRenderer::drawPoint(target, x0 + r, y0);
	//PrimitiveRenderer::drawPoint(target, x0 - r, y0);
	prim.drawPoint(img, x0, y0+y, this->color);
	prim.drawPoint(img, x0, y0-y , this->color);
	fillColor(img, this->color, color, x0, y0);
	//prim.drawPoint(img, 600, 200,sf::Color::White);

	txt.loadFromImage(img);
	arr.setTexture(txt);
	arr.setPosition(sf::Vector2f(0, 0));
	target->draw(arr);

}

void PrimitiveEllipse::draw(sf::RenderWindow* target)
{
	img.create(target->getSize().x, target->getSize().y, sf::Color::Transparent);
	float a, step;
	int x, y;
	PrimitiveRenderer prim;
	step = 1.0 / std::max(x0,y0);

	for (a = 0; a <= M_PI / 2; a += step)
	{
		x = std::ceil(x0 * cos(a));
		y = std::ceil(y0 * sin(a));

		prim.drawPoint(img, x0 + x, y0 + y, this->color);
		prim.drawPoint(img, x0 - x, y0 - y, this->color);
		prim.drawPoint(img, x0 + x, y0 - y, this->color);
		prim.drawPoint(img, x0 - x, y0 + y, this->color);

	}
	//domalowanie dziur
	//PrimitiveRenderer::drawPoint(target, x0 + r, y0);
	//PrimitiveRenderer::drawPoint(target, x0 - r, y0);
	prim.drawPoint(img, x0, y0 , this->color);
	prim.drawPoint(img, x0, y0, this->color);
	txt.loadFromImage(img);
	arr.setTexture(txt);
	arr.setPosition(sf::Vector2f(0, 0));
	target->draw(arr);
}
void PrimitiveEllipse::translate(int x, int y)
{
}

void PrimitiveEllipse::rotate(float rotation)
{

}
void PrimitiveEllipse::scale(float k)
{
}

