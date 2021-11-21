#include "PrimitiveRenderer.h"
#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include <math.h>

void PrimitiveRenderer::drawCircleUnfilled(sf::RenderWindow* target, sf::Vector2f pos)
{
	sf::CircleShape circle(100);
	circle.setFillColor(sf::Color::Transparent);
	circle.setFillColor(sf::Color::Red);
	circle.setPosition(pos);
	circle.setOutlineThickness(3);
	circle.setOutlineColor(sf::Color::Red);
	target->draw(circle);
}

void PrimitiveRenderer::drawRectangleUnfilled(sf::RenderWindow* target, sf::Vector2f pos)
{
	sf::RectangleShape rectangle(sf::Vector2f(300,200));
	rectangle.setFillColor(sf::Color::Transparent);
	rectangle.setOutlineThickness(3);
	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setPosition(pos);
	target->draw(rectangle);
}

void PrimitiveRenderer::drawSquareUnfilled(sf::RenderWindow* target, sf::Vector2f pos)
{
	sf::CircleShape square(100, 4);
	square.setFillColor(sf::Color::Transparent);
	square.setPosition(pos);
	square.setOutlineThickness(3);
	square.setOutlineColor(sf::Color::Red);
	target->draw(square);
}

void PrimitiveRenderer::drawTringleUnfilled(sf::RenderWindow* target, sf::Vector2f pos)
{
	sf::CircleShape triangle(100,3);
	triangle.setFillColor(sf::Color::Transparent);
	triangle.setOutlineThickness(3);
	triangle.setFillColor(sf::Color::Transparent);
	triangle.setPosition(pos);
	target->draw(triangle);
}

void PrimitiveRenderer::drawCircle(sf::RenderWindow* target, sf::Vector2f pos, sf::Color color)
{
	sf::CircleShape circle(100);
	circle.setFillColor(color);
	circle.setPosition(pos);
	target->draw(circle);
}

void PrimitiveRenderer::drawRectangle(sf::RenderWindow* target, sf::Vector2f pos, sf::Color color)
{
	sf::RectangleShape rectangle(sf::Vector2f(300, 200));
	rectangle.setFillColor(color);
	rectangle.setPosition(pos);
	target->draw(rectangle);
}

void PrimitiveRenderer::drawSquare(sf::RenderWindow* target, sf::Vector2f pos, sf::Color color)
{
	sf::CircleShape square(100, 4);
	square.setFillColor(color);
	square.setPosition(pos);
	target->draw(square);
}

void PrimitiveRenderer::drawTringle(sf::RenderWindow* target, sf::Vector2f pos, sf::Color color)
{
	sf::CircleShape triangle(100, 3);
	triangle.setFillColor(color);
	triangle.setPosition(pos);
	target->draw(triangle);
}


void PrimitiveRenderer::drawPoint(sf::Image& target, int x, int y)
{
	img.setPixel(x, y, sf::Color::Blue);
}

void PrimitiveRenderer::drawPoint(sf::Image &target, int x, int y, sf::Color color)
{
	img.setPixel(x, y, color);
}


void PrimitiveRenderer::drawCustomLine(sf::RenderWindow* target, std::vector<LineSegment> lines)
{
	img.create(target->getSize().x, target->getSize().y, sf::Color::Transparent);
	for(int i=0; i<lines.size(); i++)
	{
		PrimitiveRenderer::drawLinee(img, lines[i].GetA().GetX(), lines[i].GetA().GetY(), lines[i].GetB().GetX(), lines[i].GetB().GetY());
	}
	txt.loadFromImage(img);
	arr.setTexture(txt);
	arr.setPosition(sf::Vector2f(0, 0));
	target->draw(arr);
}

void PrimitiveRenderer::drawLine(sf::RenderWindow *target, int x0, int y0, int x1, int y1)
{
	img.create(target->getSize().x, target->getSize().y, sf::Color::Transparent);
	float deltay, deltax, m;
	deltay = y1 - y0;
	deltax = x1 - x0;
	float yy = y0;
	float xx = x0;
	m = deltay / deltax;
	if (x0 > x1) 
	{
		float tmp = x0;
		x0 = x1;
		x1 = tmp;
		tmp = y0;
		y0 = y1;
		y1 = tmp;
	}

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


void PrimitiveRenderer::drawCustomCircle(sf::RenderWindow* target, int x0, int y0, int r)
{
	img.create(target->getSize().x, target->getSize().y, sf::Color::Transparent);

	float a, step;
	int x, y;

	step = 1.0 / r;

	for(a=0; a<=M_PI/2; a+=step)
	{
		x = std::ceil(r * cos(a));
		y = std::ceil(r * sin(a));
		drawPoint(img,x0+x, y0+y);
		drawPoint(img,x0-x, y0-y);
		drawPoint(img,x0+x, y0-y);
		drawPoint(img,x0-x, y0+y);
	}
	//domalowanie dziur
	//PrimitiveRenderer::drawPoint(target, x0 + r, y0);
	//PrimitiveRenderer::drawPoint(target, x0 - r, y0);
	drawPoint(img, x0, y0+r);
	drawPoint(img, x0, y0-r);
	txt.loadFromImage(img);
	arr.setTexture(txt);
	arr.setPosition(sf::Vector2f(0, 0));
	target->draw(arr);

}

void PrimitiveRenderer::drawCustomElipse(sf::RenderWindow* target, int x0, int y0, int rx, int ry)
{
	img.create(target->getSize().x, target->getSize().y, sf::Color::Transparent);
	float a, step;
	int x, y;

	step = 1.0 / std::max(rx,ry);

	for (a = 0; a <= M_PI / 2; a += step)
	{
		x = rx * cos(a) + 0.5;
		y = ry * sin(a) + 0.5;
		PrimitiveRenderer::drawPoint(img, x0 + x, y0 + y);
		PrimitiveRenderer::drawPoint(img, x0 - x, y0 - y);
		PrimitiveRenderer::drawPoint(img, x0 + x, y0 - y);
		PrimitiveRenderer::drawPoint(img, x0 - x, y0 + y);
	}
	PrimitiveRenderer::drawPoint(img, x0, y0 + ry);
	PrimitiveRenderer::drawPoint(img, x0, y0 - ry);

	txt.loadFromImage(img);
	arr.setTexture(txt);
	arr.setPosition(sf::Vector2f(0, 0));
	target->draw(arr);
}



void PrimitiveRenderer::drawLinee(sf::Image &target, int x0, int y0, int x1, int y1)
{
	float deltay, deltax, m;
	deltay = y1 - y0;
	deltax = x1 - x0;
	float yy = y0;
	float xx = x0;
	m = deltay / deltax;

	if(m>1)
	{
		m = deltax / deltay;
		for (int y = y0; y <= y1; y++)
		{
			target.setPixel((int)(xx -1 + 0.5), y+1,sf::Color::Blue);
			target.setPixel((int)(xx -1 + 0.5), y-1, sf::Color::Blue);
			target.setPixel((int)(xx-1 + 0.5), y, sf::Color::Blue);
			target.setPixel((int)(xx +1 + 0.5), y+1, sf::Color::Blue);
			target.setPixel((int)(xx+1 + 0.5), y-1, sf::Color::Blue);
			target.setPixel((int)(xx+1 + 0.5), y, sf::Color::Blue);
			target.setPixel((int)(xx + 0.5), y+1, sf::Color::Blue);
			target.setPixel((int)(xx + 0.5), y-1, sf::Color::Blue);
			target.setPixel((int)(xx + 0.5), y, sf::Color::Blue);

			
			xx += m;
		}
	}
	else
	{
		for (int x = x0; x <= x1; x++)
		{
			target.setPixel(x+1, (int)(yy - 1 + 0.5),sf::Color::Blue);
			target.setPixel(x+1, (int)(yy + 0.5), sf::Color::Blue);
			target.setPixel(x+1, (int)(yy+1 + 0.5), sf::Color::Blue);
			target.setPixel(x-1, (int)(yy -1 + 0.5), sf::Color::Blue);
			target.setPixel(x-1, (int)(yy +1 + 0.5), sf::Color::Blue);
			target.setPixel(x-1, (int)(yy + 0.5), sf::Color::Blue);
			target.setPixel(x, (int)(yy -1 + 0.5), sf::Color::Blue);
			target.setPixel(x, (int)(yy+1 + 0.5), sf::Color::Blue);
			target.setPixel(x, (int)(yy  + 0.5), sf::Color::Blue);


			yy += m;
		}
	}
	

}

void PrimitiveRenderer::drawCustomFigure(sf::RenderWindow* target, std::vector<LineSegment> lines)
{
	img.create(target->getSize().x, target->getSize().y, sf::Color::Transparent);
	for (int i = 0; i < lines.size(); i++)
	{
		drawLinee(img, lines[i].GetA().GetX(), lines[i].GetA().GetY(), lines[i].GetB().GetX(), lines[i].GetB().GetY());
	}
	txt.loadFromImage(img);
	arr.setTexture(txt);
	arr.setPosition(sf::Vector2f(0, 0));
	target->draw(arr);
}

void PrimitiveRenderer::drawCustomFigureWithFill(sf::RenderWindow* target, std::vector<LineSegment> lines)
{
	img.create(target->getSize().x, target->getSize().y, sf::Color::Transparent);
	for (int i = 0; i < lines.size(); i++)
	{
		drawLinee(img, lines[i].GetA().GetX(), lines[i].GetA().GetY(), lines[i].GetB().GetX(), lines[i].GetB().GetY());
	}
	fillFigure(img, sf::Color::Blue,sf::Color::White,lines[0].GetA().GetX() + 20,lines[0].GetA().GetX() + 10);
	//img.setPixel(15,13,sf::Color::White);
	txt.loadFromImage(img);
	arr.setTexture(txt);
	arr.setPosition(sf::Vector2f(0, 0));
	target->draw(arr);
}

void PrimitiveRenderer::fillFigure(sf::Image &target, sf::Color colorI, sf::Color colorIn, int x, int y)
{
	if (img.getPixel(x, y) == colorI) return;
	if (img.getPixel(x, y) == colorIn) return;

	img.setPixel(x, y, colorIn);

	fillFigure(img, colorI, colorIn, x + 1, y);
	fillFigure(img, colorI, colorIn, x - 1, y);
	fillFigure(img, colorI, colorIn, x, y + 1);
	fillFigure(img, colorI, colorIn, x, y - 1);
}




