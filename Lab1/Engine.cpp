#include "Engine.h"
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include <SFML/Graphics/CircleShape.hpp>
#include "LineSegment.h"
#include <vector>
#include "PrimitiveSquere.h"
#include "PrimitiveCircle.h"
#include "PrimitiveEllipse.h"
#include "PrimitiveTriangle.h"
#include "Player.h"
#include "BitmapHandler.h"
Engine::Engine(std::string title, int width, int height)
{
	this->window = new sf::RenderWindow(sf::VideoMode(width,height),title);
	this->window->setFramerateLimit(60);
	this->background.setSize(sf::Vector2f(width, height));
	this->background.setFillColor(sf::Color::Black);
	this->window->draw(background);
	this->window->display();
	run();
}


Engine::Engine(std::string title, int width, int height, int mode)
{
	this->window = new sf::RenderWindow(sf::VideoMode(width,height),title);
	this->window->setFramerateLimit(60);
	this->background.setSize(sf::Vector2f(width, height));
	this->background.setFillColor(sf::Color::Black);
	this->window->draw(background);
	this->window->display();
	run();
}

Engine::~Engine()
{
	delete this->window;
}

void Engine::clear()
{
	this->window->clear();
	this->window->draw(this->background);
}
/*
Point2D point(100, 100);
LineSegment line(100,100,200,200);
LineSegment line1(200, 200, 400, 500);
LineSegment line2(400, 500, 700, 100);
LineSegment line3(100, 100,700,100);
std::vector<LineSegment> lines = { line, line1, line2 };


std::vector<LineSegment> figure = { line, line1, line2, line3 };
*/
auto Engine::getCurrentTime()
{
	return std::chrono::steady_clock::now();
}
void Engine::run()
{
	auto tp = getCurrentTime();
	Player player;
	player.back.push_back(BitmapHandler::getImageFromFile("Image/13.png"));
	player.back.push_back(BitmapHandler::getImageFromFile("Image/14.png"));
	player.back.push_back(BitmapHandler::getImageFromFile("Image/15.png"));
	player.back.push_back(BitmapHandler::getImageFromFile("Image/16.png"));
	player.front.push_back(BitmapHandler::getImageFromFile("Image/9.png"));
	player.front.push_back(BitmapHandler::getImageFromFile("Image/10.png"));
	player.front.push_back(BitmapHandler::getImageFromFile("Image/11.png"));
	player.front.push_back(BitmapHandler::getImageFromFile("Image/12.png"));
	player.left.push_back(BitmapHandler::getImageFromFile("Image/5.png"));
	player.left.push_back(BitmapHandler::getImageFromFile("Image/6.png"));
	player.left.push_back(BitmapHandler::getImageFromFile("Image/7.png"));
	player.left.push_back(BitmapHandler::getImageFromFile("Image/8.png"));
	player.right.push_back(BitmapHandler::getImageFromFile("Image/1.png"));
	player.right.push_back(BitmapHandler::getImageFromFile("Image/2.png"));
	player.right.push_back(BitmapHandler::getImageFromFile("Image/3.png"));
	player.right.push_back(BitmapHandler::getImageFromFile("Image/4.png"));


	try
	{
		PrimitiveRenderer prim;
		while (this->window->isOpen())
		{
			while(this->window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					this->window->close();
			}
			float dt;
			{
				const auto new_tp = std::chrono::steady_clock::now();
				dt = std::chrono::duration<float>(new_tp - tp).count();
				tp = new_tp;
			}
			clear();
			//prim.drawCustomCircle(this->window, 600, 200, 50);
			

			/*PrimitiveCircle circle(600, 200, 50, sf::Color::Green);
			circle.draw(this->window, sf::Color::White);*/
			//circle.draw(this->window);
			//prim.drawRectangleUnfilled(this->window,sf::Vector2f(200,200));
			//PrimitiveRenderer::drawSquare(this->window);
			//PrimitiveRenderer::drawCircle(this->window);
			//PrimitiveRenderer::drawTringle(this->window);
			//PrimitiveRenderer::drawLine(this->window,100,50,150,500);
			//prim.drawLine(this->window, 200, 50, 1100, 200);
			
			//point.DrawPoint(this->window);
			//line.DrawLine(this->window);

			//prim.drawCustomLine(this->window, lines);
			//prim.drawCustomFigure(this->window,figure);
			//prim.drawCustomFigureWithFill(this->window, figure);
			//prim.drawCustomCircle(this->window, 600, 200, 50);
			//prim.drawCustomElipse(this->window, 900, 200, 150, 70);
		/*	PrimitiveSquere squere(50, 50, 300, 100, sf::Color::White);
			PrimitiveTriangle triangle(600, 250, 700, 500, sf::Color::White);
			PrimitiveEllipse elip(50, 100, sf::Color::White);
			elip.draw(this->window,sf::Color::Red);
			triangle.rotate(50);
			triangle.draw(this->window);
			squere.rotate(10);	
			squere.translate(100, 100);
			squere.draw(this->window);*/
			
			player.update();
			player.animate(dt);
			player.draw(window);
			this->window->display();

		}
	}
	catch (std::exception e)
	{
		
	}
}

void Engine::SetFps(int fps)
{
	this->window->setFramerateLimit(fps);
}
