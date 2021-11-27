#pragma once
#include <iostream>
#include "ShapeObject.h"
#include "PrimitiveSquere.h"
#include "UpdatableObject.h"
#include "ShapeObject.h"
class Player : public PrimitiveSquere,public UpdatableObject
{
public:
	Player(int x, int y,int x1,int y1,sf::Color color)  :PrimitiveSquere(x, y, x1, y1,color){}
		void update();
};

