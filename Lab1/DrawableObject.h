#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#define M_PI 3.14159265358979323846

class DrawableObject
{
protected:
	sf::Vector2f position;
	sf::Image img;
	sf::Color color;
	sf::Texture txt;
public:
	virtual ~DrawableObject() = default;
	sf::Sprite arr;
	DrawableObject();
	void setColor(sf::Color color);
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
	void drawLine(sf::Image& image, int x0, int y0, int x1, int y1);
	void fillColor(sf::Image& img, sf::Color colorI, sf::Color colorIn, int x, int y);
	virtual void draw(sf::RenderWindow* window) = 0;
};


