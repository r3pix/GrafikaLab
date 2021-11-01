#include "Engine.h"
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include <SFML/Graphics/CircleShape.hpp>
#include "LineSegment.h"
#include <vector>

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

Point2D point(100, 100);
LineSegment line(100,100,200,200);
LineSegment line1(200, 200, 400, 500);
LineSegment line2(400, 500, 700, 100);
std::vector<LineSegment> lines = { line, line1, line2 };




void Engine::run()
{
	try
	{
		while (this->window->isOpen())
		{
			while(this->window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					this->window->close();
			}

			clear();
			//PrimitiveRenderer::drawRectangle(this->window);
			//PrimitiveRenderer::drawSquare(this->window);
			//PrimitiveRenderer::drawCircle(this->window);
			//PrimitiveRenderer::drawTringle(this->window);
			//PrimitiveRenderer::drawLine(this->window,100,50,150,500);
			//PrimitiveRenderer::drawLine(this->window, 200, 50, 1100, 200);
			
			//point.DrawPoint(this->window);
			//line.DrawLine(this->window);

			//PrimitiveRenderer::drawCustomLine(this->window, lines);
			PrimitiveRenderer::drawCustomCircle(this->window, 600, 200, 50);
			PrimitiveRenderer::drawCustomElipse(this->window, 900, 200, 150, 70);


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
