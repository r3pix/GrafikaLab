#include "PrimitiveSquere.h"
#include "PrimitiveRenderer.h"

PrimitiveSquere::PrimitiveSquere(int x, int y, int x1, int y1) {
	this->x0 = x;
	this->y0 = y;
	this->x1 = x1;
	this->y1 = y1;

	this->x2 = x1;
	this->y2 = y;

	this->x3 = x;
	this->y3 = y1;
}
PrimitiveSquere::PrimitiveSquere(int x, int y, int x1, int y1, sf::Color color){
	this->x0 = x;
	this->y0 = y;
	this->x1 = x1;
	this->y1 = y1;

	this->x2 = x1;
	this->y2 = y;

	this->x3 = x;
	this->y3 = y1;
	this->color = color;
}
void PrimitiveSquere::draw(sf::RenderWindow* target) {

	img.create(target->getSize().x, target->getSize().y, sf::Color::Transparent);
	drawLine(img, position.x + x0, position.y + y0, position.x + x2, position.y + y2);
	drawLine(img, position.x + x2, position.y + y2, position.x + x1, position.y + y1);
	drawLine(img, position.x + x1, position.y + y1, position.x + x3, position.y + y3);
	drawLine(img, position.x + x3, position.y + y3, position.x + x0, position.y + y0);
	std::cout << position.x << " dsds" << position.y << std::endl;
	txt.loadFromImage(img);
	arr.setTexture(txt);
	arr.setPosition(sf::Vector2f(0, 0));
	target->draw(arr);
}
void PrimitiveSquere::draw(sf::RenderWindow* target, sf::Color color) {
	img.create(target->getSize().x, target->getSize().y, sf::Color::Transparent);
	drawLine(img, position.x + x0, position.y + y0, position.x + x2, position.y + y2);
	drawLine(img, position.x + x2, position.y + y2, position.x + x1, position.y + y1);
	drawLine(img, position.x + x1, position.y + y1, position.x + x3, position.y + y3);
	drawLine(img, position.x + x3, position.y + y3, position.x + x0, position.y + y0);
	fillColor(img, this->color,color,(x0+x1)/2,(y0+y1)/2);
	txt.loadFromImage(img);
	arr.setTexture(txt);
	arr.setPosition(sf::Vector2f(0, 0));
	target->draw(arr);
}
void PrimitiveSquere::translate(int x, int y)
{
	position = sf::Vector2f(x + position.x, y + position.y);
}
void PrimitiveSquere::rotate(float rotation)
{
	rotation = rotation * (M_PI / 180);
	x0 = x0 * cos(rotation) - y0 * sin(rotation);
	y0 = x0 * sin(rotation) + y0 * cos(rotation);
	x1 = x1 * cos(rotation) - y1 * sin(rotation);
	y1 = x1 * sin(rotation) + y1 * cos(rotation);
	x2 = x2 * cos(rotation) - y2 * sin(rotation);
	y2 = x2 * sin(rotation) + y2 * cos(rotation);
	x3 = x3 * cos(rotation) - y3 * sin(rotation);
	y3 = x3 * sin(rotation) + y3 * cos(rotation);
}
void PrimitiveSquere::scale(float k)
{
	this->x0 = this->x0 * k;
	this->y0 = this->y0 * k;
	this->x1 = this->x1 * k;
	this->y1 = this->y1 * k;

}