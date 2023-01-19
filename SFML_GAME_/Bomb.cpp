#include "Bomb.h"
Bomb::Bomb():bombexploded(false) {}
void Bomb::CreateBomb(float X, float Y) {
	int _X = X / 32;
	int _Y = Y / 32;
	x_b = _X;
	y_b = _Y;
	char t = TileMap1[_Y][_X];
	if (TileMap1[_Y][_X] == ' ') {
		TileMap1[_Y][_X] = 'b';
	}
	bombexploded = true;
}
void Bomb::DeleteBom(float X, float Y) {
	int _X = X ;
	int _Y = Y ;
	char t = TileMap1[_Y][_X];
	TileMap1[_Y][_X] = ' ';

	if(TileMap1[_Y + 1 ][_X] == 's'){
		TileMap1[_Y + 1][_X] == ' ';
	}
	if (TileMap1[_Y][_X + 1] == 's') {
		TileMap1[_Y][_X + 1] = ' ';
	}
	if (TileMap1[_Y - 1][_X] == 's') {
		TileMap1[_Y - 1][_X] = ' ';
	}
	if (TileMap1[_Y][_X - 1] == 's') {
		TileMap1[_Y][_X - 1] = ' ';
	}


	if (TileMap1[_Y + 1][_X] == 'z') {
		TileMap1[_Y + 1][_X] == 'w';
	}
	if (TileMap1[_Y][_X + 1] == 'z') {
		TileMap1[_Y][_X + 1] = 'w';
	}
	if (TileMap1[_Y - 1][_X] == 'z') {
		TileMap1[_Y - 1][_X] = 'w';
	}
	if (TileMap1[_Y][_X - 1] == 'z') {
		TileMap1[_Y][_X - 1] = 'w';
	}
	bombexploded = false;

}

int Bomb::getY() { return y_b; }
int Bomb::getX() { return x_b; }
bool Bomb::GetBombexploded() {return bombexploded;}