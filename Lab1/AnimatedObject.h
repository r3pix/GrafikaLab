#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
class AnimatedObject
{
public:
	std::vector<sf::Image>front;
	std::vector<sf::Image>back;
	std::vector<sf::Image>left;
	std::vector<sf::Image>right;
	virtual void animate(float dt)=0;

};

