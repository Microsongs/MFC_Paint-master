#pragma once

#include "MyButton.h"
#include "View.h"
#include "Toolbar.h"
#include <iostream>

using namespace std;

class Toolbar;

class TButton : public MyButton
{
private:
	Toolbar* toolbar;	//툴바 객체
public:
	TButton(string title);	//x위치와 타이틀
	void setX(int x);
	int getX();
	void draw();	//view의 호출을 위해 재정의
	void setToolbar(Toolbar*);
	void tempDraw();	//View의 호출을 위해 재정의
	string getTitle();	//타이틀반환
	~TButton();
};

