#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>
using namespace sf;

#define RND(min, max)  (rand()%((max)-(min)+1)+(min))

bool StartGame();
void RuningGame();