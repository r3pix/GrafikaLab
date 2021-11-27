#pragma once
#include <SFML/System/Vector2.hpp>

class TransformableObject
{
public:
	virtual void translate(int x,int y) = 0;
	virtual void rotate(float rotation) = 0;
	virtual void scale(float k) = 0;
};

