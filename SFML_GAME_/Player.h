#pragma once
#include "Object.h"
#include <SFML/Graphics.hpp>
class Player :public Object{
	bool life;
	int health;
public:
	Player(String F, float X, float Y, float W, float H);

	void SetLife();
	void SetMove(float m_dir, float m_speed);
	void SetSprite(float cntFrame, int one, int two, int three);
	Sprite getSprite();
	void update(float time)override;                        //функция "оживления" объекта класса. работает бесконечно, давая персонажу движение.
	void interactionWithMap();
	int getX();
	int getY();
	bool getLife() { return life; }
	int getHealth() { return health; };
	FloatRect getRect() ;
};

