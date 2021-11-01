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
	PrimitiveRenderer::drawPoint(target, this->GetX(), this->GetY());
}

Point2D::Point2D(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point2D::Point2D()
{
	
}
