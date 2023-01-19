#include <SFML/Graphics.hpp>
#include "Pole.h"


const int HEIGHT_MAP = 22;//размер карты высота
const int WIDTH_MAP = 32;//размер карты ширина 

sf::String TileMap1[HEIGHT_MAP] = {
	"00000000000000000000000000000000s",
	"0   s   sssssssss    s    s    s0",
	"0   ssss        sss  s    s    s0",
	"0   ss         ssss       s    s0",
	"0   00sss  00 sss00ssss00      s0",
	"0   00s    00   s00    00      s0",
	"0   z         ssssssssssssssssss0",
	"0   ssssssss    sss            s0",
	"0   s      s    s     ssssssssss0",
	"0   s      s    s              s0",
	"0   00    00    s00ssss00s     s0",
	"0   00    00    s00    00      s0",
	"0          s    s              s0",
	"0sssssss        ss             s0",
	"0     s                        s0",
	"0     s              sss sssssss0",
	"0   00ssss00    s00ssss00      s0",
	"0   00s   00    000  ss00  sssss0",
	"0   ss     ss   00   ss        s0",
	"0     sssssss   ss   ss        s0",
	"0               ss   ss        s0",
	"000000000000000000000000000000000",
};
