#include "Enemy.h"
#include "Pole.h"

Enemy::Enemy(String F, float X, float Y, float W, float H) {
	speed = 0;
	File = F;
	w = W; h = H;
	image.loadFromFile("sprite/" + File);
	texture.loadFromImage(image);                   //закидываем наше изображение в текстуру
	sprite.setTexture(texture);                    //заливаем спрайт текстурой
	x = X; y = Y;                                 //координата появления спрайта
	sprite.setTextureRect(IntRect(0, 0, w, h));  //Задаем спрайту один прямоугольник для вывода одного Персонажа	
}
void Enemy::checkCollisionWithMap(float Dx, float Dy) {
	for (int i = y / 32; i < (y + h) / 32; i++)//проходимся по элементам карты
		for (int j = x / 32; j < (x + w) / 32; j++)
		{
			if (i < 0 || j < 0 || i >= HEIGHT_MAP || j >= WIDTH_MAP) {
				continue;
			}
			if (TileMap1[i][j] == '0' || TileMap1[i][j] == 's')
			{
				if (Dy > 0) { y = i * 32 - h; }
				if (Dy < 0) { y = i * 32 + 32; }//столкновение с верхними краями карты(может и не пригодиться)
				if (Dx > 0) { x = j * 32 - w; dx = -0.1; sprite.scale(-1, 1); }//с правым краем карты
				if (Dx < 0) { x = j * 32 + 32; dx = 0.1; sprite.scale(-1, 1); }// с левым краем карты
			}
		}
}
void Enemy::update(float time) {
	checkCollisionWithMap(dx, 0);//обрабатываем столкновение по Х
	x += dx * time;
	sprite.setPosition(x + w / 2, y + h / 2); //задаем позицию спрайта в место его центра
}
Sprite Enemy::getSprite() { return sprite; }
int Enemy::getX() { return x; }
int Enemy::getY() { return y; };
FloatRect Enemy::getRect() {
	return FloatRect(x, y, w, h);
}