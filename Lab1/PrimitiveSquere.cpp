#include "PrimitiveSquere.h"
#include "PrimitiveRenderer.h"

PrimitiveSquere::PrimitiveSquere(int x, int y, int x1, int y1) {
	this->x0 = x;
	this->y0 = y;
	this->x1 = x1;
	this->y1 = y1;
}
PrimitiveSquere::PrimitiveSquere(int x, int y, int x1, int y1, sf::Color color){
	this->x0 = x;
	this->y0 = y;
	this->x1 = x1;
	this->y1 = y1;
	this->color = color;
}
void PrimitiveSquere::draw(sf::RenderWindow* target) {

	img.create(target->getSize().x, target->getSize().y, sf::Color::Transparent);
	drawLine(img, x0, y0, x1, y0);
	drawLine(img, x1, y0, x1, y1);
	drawLine(img, x1, y1, x0, y1);
	drawLine(img, x0, y1,x0, y0);
	txt.loadFromImage(img);
	arr.setTexture(txt);
	arr.setPosition(sf::Vector2f(0, 0));
	target->draw(arr);
}
void PrimitiveSquere::draw(sf::RenderWindow* target, sf::Color color) {
	img.create(target->getSize().x, target->getSize().y, sf::Color::Transparent);
	drawLine(img, x0, y0, x1, y0);
	drawLine(img, x1, y0, x1, y1);
	drawLine(img, x1, y1, x0, y1);
	drawLine(img, x0, y1, x0, y0);
	fillColor(img, this->color,color,(x0+x1)/2,(y0+y1)/2);
	txt.loadFromImage(img);
	arr.setTexture(txt);
	arr.setPosition(sf::Vector2f(0, 0));
	target->draw(arr);
}
void PrimitiveSquere::translate(sf::Vector2f translate)
{
	position = sf::Vector2f(x0 + position.x, y0 + position.y), sf::Vector2f(x1 + position.x, y1 + position.y);
}
void PrimitiveSquere::rotate(float rotation)
{

}
void PrimitiveSquere::scale(float k)
{
	this->x0 = this->x0 * k;
	this->y0 = this->y0 * k;
	this->x1 = this->x1 * k;
	this->y1 = this->y1 * k;

}