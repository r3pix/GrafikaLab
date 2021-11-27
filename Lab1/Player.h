#pragma once
#include <iostream>
#include "ShapeObject.h"
#include "PrimitiveSquere.h"
#include "UpdatableObject.h"
#include "ShapeObject.h"
#include "SpriteObject.h"
enum class Kierunek { left, right, up, down };
class Player : public SpriteObject,public UpdatableObject,public ShapeObject
{
public:
	int fps;
	void translate(int x,int y) ;
	void rotate(float k);
	void scale(float rotation);
	Kierunek kierunek = Kierunek::up;
	void update();
	void animate(float dt);
	int index = 0;
	void draw(sf::RenderWindow* target);
};

