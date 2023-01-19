#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Object{
protected:
	float x, y, w, h, dx, dy, speed;     //координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
	int dir = 0;                         //направление (direction) движения игрока
	String File;                         //файл с расширением
	Image image;                         //сфмл изображение
	Texture texture;                     //сфмл текстура
	Sprite sprite;
public:
	virtual void update(float time) = 0;//функция "оживления" объекта класса. работает бесконечно, давая персонажу движение.
	~Object();
};

