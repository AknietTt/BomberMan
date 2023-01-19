#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
class Object{
protected:
	float x, y, w, h, dx, dy, speed;     //���������� ������ � � �, ������ ������, ��������� (�� � � �� �), ���� ��������
	int dir = 0;                         //����������� (direction) �������� ������
	String File;                         //���� � �����������
	Image image;                         //���� �����������
	Texture texture;                     //���� ��������
	Sprite sprite;
public:
	virtual void update(float time) = 0;//������� "���������" ������� ������. �������� ����������, ����� ��������� ��������.
	~Object();
};

