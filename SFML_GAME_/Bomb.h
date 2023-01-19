#pragma once
#include <SFML/Graphics.hpp>
#include "Pole.h"

using namespace sf;
class Bomb{
private:
	int x_b, y_b;
	bool bombexploded;
public:
	Bomb();
	void CreateBomb(float X, float Y);
	void DeleteBom(float X, float Y);
	bool GetBombexploded();
	int getY();
	int getX();
};

