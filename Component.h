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
	//생성자
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
	virtual void draw();	//버튼 그리기
	virtual void tempDraw();	//버튼 마우스오버
	bool inside(int x, int y);	//안에 있는지 확인
	//void action();
	void setView(View *);	//VIew 설정
	string getTitle();	//title 반환
	void setX(int x);	//x값 변경
	void setY(int y);	//y값 변경
	virtual void addComponent(Component*);	//Menu용 버츄얼
	virtual Component* find(int, int);					//menu용 버츄얼
	virtual bool getPush();	//Menu용 버츄얼
	//virtual void unpush();	//메뉴용 버츄얼
	virtual void addActionListener(actionListener*);
};

