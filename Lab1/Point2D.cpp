#include "Point2D.h"
#include "PrimitiveRenderer.h"

void Point2D::SetX(int x)
{
	this->x = x;
}

void Point2D::SetY(int y)
{
	this->y = y;
}

float Point2D::GetX()
{
	return this->x;
}

float Point2D::GetY()
{
	return this->y;
}

void Point2D::DrawPoint(sf::RenderWindow* target)
{
	img.create(target->getSize().x, target->getSize().y, sf::Color::Transparent);
	PrimitiveRenderer prim;
	prim.drawPoint(img, this->GetX(), this->GetY());
	txt.loadFromImage(img);
	arr.setTexture(txt);
	arr.setPosition(sf::Vector2f(0, 0));
	target->draw(arr);
}

Point2D::Point2D(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point2D::Point2D()
{
	
}
