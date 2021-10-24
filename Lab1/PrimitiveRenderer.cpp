#include "PrimitiveRenderer.h"
#include <SFML/Graphics.hpp>


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

void PrimitiveRenderer::drawLine(sf::RenderWindow* target, int x0, int y0, int x1, int y1)
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


