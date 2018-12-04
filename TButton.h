#pragma once

#include "MyButton.h"
#include "View.h"
#include "Toolbar.h"
#include <iostream>
#include <list>
#include "Figure.h"

using namespace std;

class Toolbar;

class TButton : public MyButton
{
private:
	list <actionListener*> myListener;
	//Toolbar* toolbar;	//툴바 객체
	HICON hicon;
public:
	TButton(string title);	//x위치와 타이틀
	//void setX(int x);
	//int getX();
	void draw();	//view의 호출을 위해 재정의
	void tempDraw();	//View의 호출을 위해 재정의
	//void setToolbar(Toolbar*);
	bool click = false;
	void upClick();
	void downClick();

	//string getTitle();	//타이틀반환
	void setIcon(HICON h);
	void clicked();
	void addActionListener(actionListener*);
	~TButton();
};

