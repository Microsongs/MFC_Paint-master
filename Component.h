#pragma once
#pragma once
#include "string"
#include <iostream>

using namespace std;
class View;
class actionListener;

class Component
{
public:
	//������
	Component();
	Component(int x, int y, int sizex, int siezy, std::string title);
	Component(std::string title);
	~Component();
protected:
	std::string m_title;
	int m_startx, m_starty, m_sizex, m_sizey;
	View *m_view = 0;
	COLORREF m_normal_bg_color = RGB(230, 230, 230);
	COLORREF m_temp_bg_color = RGB(200, 200, 200);
	COLORREF m_line_color = RGB(0, 0, 0);
public:
	virtual void draw();	//��ư �׸���
	virtual void tempDraw();	//��ư ���콺����
	bool inside(int x, int y);	//�ȿ� �ִ��� Ȯ��
	//void action();
	void setView(View *);	//VIew ����
	string getTitle();	//title ��ȯ
	void setX(int x);	//x�� ����
	void setY(int y);	//y�� ����
	virtual void addComponent(Component*);	//Menu�� �����
	virtual Component* find(int, int);					//menu�� �����
	virtual bool getPush();	//Menu�� �����
	//virtual void unpush();	//�޴��� �����
	virtual void addActionListener(actionListener*);
};

