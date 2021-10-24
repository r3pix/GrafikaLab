#include "Engine.h"
#include "PrimitiveRenderer.h"
#include <SFML/Graphics/CircleShape.hpp>

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
			PrimitiveRenderer::drawLine(this->window,100,50,150,500);
			PrimitiveRenderer::drawLine(this->window, 200, 50, 1100, 200);
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
