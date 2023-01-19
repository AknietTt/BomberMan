#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>
using namespace sf;
class Enemy :public Object{
public:
	Enemy(String F, float X, float Y, float W, float H);
	void checkCollisionWithMap(float Dx, float Dy);
	void update(float time)override;
	Sprite getSprite();
	FloatRect getRect();
	int getX();
	int getY();
};

