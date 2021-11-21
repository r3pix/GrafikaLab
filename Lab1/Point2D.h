#pragma once
#include <SFML/Graphics.hpp>
class Point2D
{
public:
	float x, y;
	sf::Image img;
	sf::Texture txt;
	sf::Sprite arr;
	void SetX(int x);
	void SetY(int y);

	float GetX();
	float GetY();


	Point2D();
	Point2D(int x, int y);
	void DrawPoint(sf::RenderWindow *target);

};

