#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Pole.h"
#include "Player.h"
#include "Enemy.h"
#include "Bomb.h"


using namespace sf;
RenderWindow window(VideoMode(1080, 720), "SFML Works!");
bool StartGame() {
	bool WIN = false;
	Font font;
	font.loadFromFile("CyrilicOld.ttf");
	Text text("", font, 25);
	text.setColor(Color::Blue);
	text.setStyle(Text::Bold);

	Player p("NeoEarlyBomberman.png", 32.0, 64.0, 32.0, 32.0);
	Enemy enemy("enemy.png", 140, 65, 32.0, 25);
	Enemy enemy2("enemy.png", 140, 447, 32.0, 25);
	Bomb bomb;
	Clock clock;                      //создаем переменную времени, т.о. привязка ко времени(а не загруженности/мощности процессора).
	Clock clockGame;                     
	Clock clockView;                     
	float cntFrame = 0;
	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		float timeGame = clockGame.getElapsedTime().asMicroseconds();
		float timeView = clockView.getElapsedTime().asMilliseconds();
		clock.restart();
		time = time / 800;
		timeGame = timeGame / 1000;
		timeView = timeView / 1000;
		int createObjectForMapTimer = 0;
		Image map_image;                                //объект изображения для карты
		map_image.loadFromFile("sprite/mapSprite3.png"); //загружаем файл для карты
		Texture map;                                    //текстура карты
		map.loadFromImage(map_image);                   //заряжаем текстуру картинкой
		Sprite s_map;                                   //создаём спрайт для карты
		s_map.setTexture(map);                          //заливаем текстуру спрайтом
		if (p.getLife()==false || WIN == true) time = clock.getElapsedTime().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
			p.SetMove(1, 0.1); //dir =1 - направление вверх, speed =0.1 - скорость движения. Заметьте - время мы уже здесь ни на что не умножаем и нигде не используем каждый раз
			cntFrame += 0.005 * time;
			if (cntFrame > 6) cntFrame -= 6;
			p.SetSprite(cntFrame, 90, 30, 30);//через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)
		}

		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
			p.SetMove(0, 0.1);//направление вправо, см выше
			cntFrame += 0.005 * time;
			if (cntFrame > 6) cntFrame -= 6;
			p.SetSprite(cntFrame, 30, 30, 30); //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)
		}

		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
			p.SetMove(3, 0.1);//направление вниз, см выше
			cntFrame += 0.005 * time;
			if (cntFrame > 6) cntFrame -= 6;
			p.SetSprite(cntFrame, 0, 30, 30);  //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)

		}

		if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //если нажата клавиша стрелка влево или англ буква А
			p.SetMove(2, 0.1);//направление вверх, см выше
			cntFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (cntFrame > 6) cntFrame -= 6; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
			p.SetSprite(cntFrame, 60, 30, 30);

		}
		//ememy.SetMove((RND(0, 4)), 0.1);
 		p.update(time);//оживляем объект p класса Player с помощью времени sfml, передавая время в качестве параметра функции update. благодаря этому персонаж может двигаться
		enemy.update(time);
		enemy2.update(time);
		window.clear();
		if (bomb.GetBombexploded() == true) {
			createObjectForMapTimer += timeGame;
		}
		if (bomb.GetBombexploded()== true && createObjectForMapTimer > 3000) {
			bomb.DeleteBom(bomb.getX(), bomb.getY());;
			createObjectForMapTimer = 0;
			clockGame.restart();
		}
		if ((Keyboard::isKeyPressed(Keyboard::Enter) || (Keyboard::isKeyPressed(Keyboard::Space)))) {
			if (bomb.GetBombexploded() == false) {
				bomb.CreateBomb(p.getX(), p.getY());
			}
		}
		/////////////////////////////Рисуем карту////////////////////////
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap1[i][j] == 's')  s_map.setTextureRect(IntRect(0, 0, 30, 30)); //если встретили символ пробел, то рисуем 1й квадратик
				if (TileMap1[i][j] == '0')  s_map.setTextureRect(IntRect(32, 0, 30, 30));//если встретили символ s, то рисуем 2й квадратик
				if ((TileMap1[i][j] == ' ')) s_map.setTextureRect(IntRect(64, 0, 30, 30));//если встретили символ 0, то рисуем 3й квадратик
				if ((TileMap1[i][j] == 'b')) s_map.setTextureRect(IntRect(96, 0, 28, 28));;
				if ((TileMap1[i][j] == 'z'))s_map.setTextureRect(IntRect(0, 0, 30, 30));
				if ((TileMap1[i][j] == 'w')) {
					s_map.setTextureRect(IntRect(192, 0, 28, 28));
					WIN = true;
				};


				s_map.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

				window.draw(s_map);//рисуем квадратики на экран
			}
		if (enemy.getRect().intersects(p.getRect())|| enemy2.getRect().intersects(p.getRect())) {
			p.SetLife();
		}

		std::ostringstream  gameTimeString;    // объявили переменную здоровья и времени
		gameTimeString << timeView;		//формируем строку
		text.setString("\nВремя игры: " + gameTimeString.str());//задаем строку тексту и вызываем сформированную выше строку методом .str()
		text.setPosition (0, 0);//задаем позицию текста
		std::ostringstream  winGame;
		if (WIN == true) {
			text.setCharacterSize(100);
			text.setString("\nWIN");
			text.setPosition(400, 200);
		}
		if (p.getHealth() <= 0) {
			text.setCharacterSize(100);
			text.setString("\nGAME OVER");
			text.setPosition(200, 200);
		}
		window.draw(text);//рисую этот текст
		window.draw(p.getSprite());//рисуем спрайт объекта p класса player
		window.draw(enemy.getSprite());
		window.draw(enemy2.getSprite());
		window.display();
	}
	return true;
}

void RuningGame() {
	if (StartGame()) {
		RuningGame();
	}
}