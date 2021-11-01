#include "LineSegment.h"
#include "Point2D.h"
#include "PrimitiveRenderer.h"

void LineSegment::SetA(float x, float y)
{
	this->A.SetX(x);
	this->A.SetY(y);
}
void LineSegment::SetB(float x, float y)
{
	this->B.SetX(x);
	this->B.SetY(y);
}

Point2D LineSegment::GetA()
{
	return this->A;
}
Point2D LineSegment::GetB()
{
	return this->B;
}


LineSegment::LineSegment(float xa, float ya, float xb, float yb)
{
	this->SetA(xa, ya);
	this->SetB(xb, yb);
}

LineSegment::LineSegment()
{
	
}


void LineSegment::DrawLine(sf::RenderWindow* target)
{
	PrimitiveRenderer::drawLine(target,this->A.GetX(), this->A.GetY(), this->B.GetX(), this->B.GetY());
}