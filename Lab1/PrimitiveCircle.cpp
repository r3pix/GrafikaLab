#include "PrimitiveCircle.h"
#include "PrimitiveRenderer.h"

PrimitiveCircle::PrimitiveCircle(int x, int y, int r) {
	this->x0 = x;
	this->y0 = y;
	this->r = r;
}

PrimitiveCircle::PrimitiveCircle(int x, int y, int r, sf::Color color) {
	this->x0 = x;
	this->y0 = y;
	this->r = r;
	this->color = color;
}

void PrimitiveCircle::draw(sf::RenderWindow* target, sf::Color color) {
	img.create(target->getSize().x, target->getSize().y, sf::Color::Transparent);
	float a, step;
	int x, y;
	PrimitiveRenderer prim;
	step = 1.0 / r;

	for (a = 0; a <= M_PI / 2; a += step)
	{
		x = std::ceil(r * cos(a));
		y = std::ceil(r * sin(a));

		prim.drawPoint(img, x0 + x, y0 + y,this->color);
		prim.drawPoint(img, x0 - x, y0 - y,this->color);
		prim.drawPoint(img, x0 + x, y0 - y,this->color);
		prim.drawPoint(img, x0 - x, y0 + y,this->color);

	}
	//domalowanie dziur
	//PrimitiveRenderer::drawPoint(target, x0 + r, y0);
	//PrimitiveRenderer::drawPoint(target, x0 - r, y0);
	prim.drawPoint(img, x0, y0 + r, this->color);
	prim.drawPoint(img, x0, y0 - r, this->color);
	fillColor(img, this->color, color, x0, y0);
	//prim.drawPoint(img, 600, 200,sf::Color::White);
	
	txt.loadFromImage(img);
	arr.setTexture(txt);
	arr.setPosition(sf::Vector2f(0, 0));
	target->draw(arr);

}

void PrimitiveCircle::draw(sf::RenderWindow* target)
{
	img.create(target->getSize().x, target->getSize().y, sf::Color::Transparent);
	float a, step;
	int x, y;
	PrimitiveRenderer prim;
	step = 1.0 / r;

	for (a = 0; a <= M_PI / 2; a += step)
	{
		x = std::ceil(r * cos(a));
		y = std::ceil(r * sin(a));
		
		prim.drawPoint(img, x0 + x, y0 + y, this->color);
		prim.drawPoint(img, x0 - x, y0 - y, this->color);
		prim.drawPoint(img, x0 + x, y0 - y, this->color);
		prim.drawPoint(img, x0 - x, y0 + y, this->color);

	}
	//domalowanie dziur
	//PrimitiveRenderer::drawPoint(target, x0 + r, y0);
	//PrimitiveRenderer::drawPoint(target, x0 - r, y0);
	prim.drawPoint(img, x0, y0 + r, this->color);
	prim.drawPoint(img, x0, y0 - r, this->color);
	txt.loadFromImage(img);
	arr.setTexture(txt);
	arr.setPosition(sf::Vector2f(0, 0));
	target->draw(arr);
}
void PrimitiveCircle::translate(int x, int y)
{
	position = sf::Vector2f(x + position.x, y + position.y);
}

void PrimitiveCircle::rotate(float rotation)
{

}
void PrimitiveCircle::scale(float k)
{
	this->r = this->r * k;
	
}

