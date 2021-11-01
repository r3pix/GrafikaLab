#include "PrimitiveRenderer.h"
#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include <math.h>

void PrimitiveRenderer::drawCircle(sf::RenderWindow* target)
{
	sf::CircleShape circle(100);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(sf::Vector2f(300,300));
	target->draw(circle);
}

void PrimitiveRenderer::drawRectangle(sf::RenderWindow* target)
{
	sf::RectangleShape rectangle(sf::Vector2f(300,200));
	rectangle.setFillColor(sf::Color::Green);
	target->draw(rectangle);
}

void PrimitiveRenderer::drawSquare(sf::RenderWindow* target)
{
	sf::CircleShape square(100, 4);
	square.setFillColor(sf::Color::Cyan);
	square.setPosition(sf::Vector2f(1000, 300));
	target->draw(square);
}

void PrimitiveRenderer::drawTringle(sf::RenderWindow* target)
{
	sf::CircleShape triangle(100,3);
	triangle.setFillColor(sf::Color::Yellow);
	triangle.setPosition(sf::Vector2f(600, 300));
	target->draw(triangle);
}

void PrimitiveRenderer::drawPoint(sf::RenderWindow* target, float x, float y)
{
	sf::RectangleShape pixel(sf::Vector2f(1, 1));
	pixel.setFillColor(sf::Color::Blue);
	pixel.setPosition(sf::Vector2f(x, y));
	target->draw(pixel);
}

void PrimitiveRenderer::drawCustomLine(sf::RenderWindow* target, std::vector<LineSegment> lines)
{
	for(int i=0; i<lines.size(); i++)
	{
		PrimitiveRenderer::drawLine(target, lines[i].GetA().GetX(), lines[i].GetA().GetY(), lines[i].GetB().GetX(), lines[i].GetB().GetY());
	}
}

void PrimitiveRenderer::drawCustomCircle(sf::RenderWindow* target, float x0, float y0, float r)
{
	float a, step;
	int x, y;

	step = 1.0 / r;

	for(a=0; a<=M_PI/2; a+=step)
	{
		x = std::ceil(r * cos(a));
		y = std::ceil(r * sin(a));
		PrimitiveRenderer::drawPoint(target,x0+x, y0+y);
		PrimitiveRenderer::drawPoint(target,x0-x, y0-y);
		PrimitiveRenderer::drawPoint(target,x0+x, y0-y);
		PrimitiveRenderer::drawPoint(target,x0-x, y0+y);
	}
	//domalowanie dziur
	//PrimitiveRenderer::drawPoint(target, x0 + r, y0);
	//PrimitiveRenderer::drawPoint(target, x0 - r, y0);
	PrimitiveRenderer::drawPoint(target, x0, y0+r);
	PrimitiveRenderer::drawPoint(target, x0, y0-r);
}

void PrimitiveRenderer::drawCustomElipse(sf::RenderWindow* target, float x0, float y0, float rx, float ry)
{
	float a, step;
	int x, y;

	step = 1.0 / std::max(rx,ry);

	for (a = 0; a <= M_PI / 2; a += step)
	{
		x = rx * cos(a) + 0.5;
		y = ry * sin(a) + 0.5;
		PrimitiveRenderer::drawPoint(target, x0 + x, y0 + y);
		PrimitiveRenderer::drawPoint(target, x0 - x, y0 - y);
		PrimitiveRenderer::drawPoint(target, x0 + x, y0 - y);
		PrimitiveRenderer::drawPoint(target, x0 - x, y0 + y);
	}
	PrimitiveRenderer::drawPoint(target, x0, y0 + ry);
	PrimitiveRenderer::drawPoint(target, x0, y0 - ry);
}



void PrimitiveRenderer::drawLine(sf::RenderWindow* target, float x0, float y0, float x1, float y1)
{
	float deltay, deltax, m;
	deltay = y1 - y0;
	deltax = x1 - x0;
	float yy = y0;
	float xx = x0;
	m = deltay / deltax;
	sf::RectangleShape pixel(sf::Vector2f(1, 1));
	pixel.setFillColor(sf::Color::Blue);

	if(m>1)
	{
		m = deltax / deltay;
		for (int y = y0; y <= y1; y++)
		{
			pixel.setPosition(sf::Vector2f((int)(xx + 0.5), y));
			target->draw(pixel);
			xx += m;
		}
	}
	else
	{
		for (int x = x0; x <= x1; x++)
		{
			pixel.setPosition(sf::Vector2f(x, (int)(yy + 0.5)));
			target->draw(pixel);
			yy += m;
		}
	}
	

}


