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
	Clock clock;                      //������� ���������� �������, �.�. �������� �� �������(� �� �������������/�������� ����������).
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
		Image map_image;                                //������ ����������� ��� �����
		map_image.loadFromFile("sprite/mapSprite3.png"); //��������� ���� ��� �����
		Texture map;                                    //�������� �����
		map.loadFromImage(map_image);                   //�������� �������� ���������
		Sprite s_map;                                   //������ ������ ��� �����
		s_map.setTexture(map);                          //�������� �������� ��������
		if (p.getLife()==false || WIN == true) time = clock.getElapsedTime().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
			p.SetMove(1, 0.1); //dir =1 - ����������� �����, speed =0.1 - �������� ��������. �������� - ����� �� ��� ����� �� �� ��� �� �������� � ����� �� ���������� ������ ���
			cntFrame += 0.005 * time;
			if (cntFrame > 6) cntFrame -= 6;
			p.SetSprite(cntFrame, 90, 30, 30);//����� ������ p ������ player ������ ������, ����� �������� (��������� �������� �����)
		}

		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
			p.SetMove(0, 0.1);//����������� ������, �� ����
			cntFrame += 0.005 * time;
			if (cntFrame > 6) cntFrame -= 6;
			p.SetSprite(cntFrame, 30, 30, 30); //����� ������ p ������ player ������ ������, ����� �������� (��������� �������� �����)
		}

		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
			p.SetMove(3, 0.1);//����������� ����, �� ����
			cntFrame += 0.005 * time;
			if (cntFrame > 6) cntFrame -= 6;
			p.SetSprite(cntFrame, 0, 30, 30);  //����� ������ p ������ player ������ ������, ����� �������� (��������� �������� �����)

		}

		if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //���� ������ ������� ������� ����� ��� ���� ����� �
			p.SetMove(2, 0.1);//����������� �����, �� ����
			cntFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (cntFrame > 6) cntFrame -= 6; //���������� �� ������ � ������� �� ������ ������������. ���� ������ � �������� ����� - ������������ �����.
			p.SetSprite(cntFrame, 60, 30, 30);

		}
		//ememy.SetMove((RND(0, 4)), 0.1);
 		p.update(time);//�������� ������ p ������ Player � ������� ������� sfml, ��������� ����� � �������� ��������� ������� update. ��������� ����� �������� ����� ���������
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
		/////////////////////////////������ �����////////////////////////
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap1[i][j] == 's')  s_map.setTextureRect(IntRect(0, 0, 30, 30)); //���� ��������� ������ ������, �� ������ 1� ���������
				if (TileMap1[i][j] == '0')  s_map.setTextureRect(IntRect(32, 0, 30, 30));//���� ��������� ������ s, �� ������ 2� ���������
				if ((TileMap1[i][j] == ' ')) s_map.setTextureRect(IntRect(64, 0, 30, 30));//���� ��������� ������ 0, �� ������ 3� ���������
				if ((TileMap1[i][j] == 'b')) s_map.setTextureRect(IntRect(96, 0, 28, 28));;
				if ((TileMap1[i][j] == 'z'))s_map.setTextureRect(IntRect(0, 0, 30, 30));
				if ((TileMap1[i][j] == 'w')) {
					s_map.setTextureRect(IntRect(192, 0, 28, 28));
					WIN = true;
				};


				s_map.setPosition(j * 32, i * 32);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������

				window.draw(s_map);//������ ���������� �� �����
			}
		if (enemy.getRect().intersects(p.getRect())|| enemy2.getRect().intersects(p.getRect())) {
			p.SetLife();
		}

		std::ostringstream  gameTimeString;    // �������� ���������� �������� � �������
		gameTimeString << timeView;		//��������� ������
		text.setString("\n����� ����: " + gameTimeString.str());//������ ������ ������ � �������� �������������� ���� ������ ������� .str()
		text.setPosition (0, 0);//������ ������� ������
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
		window.draw(text);//����� ���� �����
		window.draw(p.getSprite());//������ ������ ������� p ������ player
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