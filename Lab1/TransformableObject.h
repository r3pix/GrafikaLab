#pragma once
#include <SFML/System/Vector2.hpp>

class TransformableObject
{
public:
	virtual void translate(sf::Vector2f translate) = 0;
	virtual void rotate(float rotation) = 0;
	virtual void scale(float k) = 0;
};

