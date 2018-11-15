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
	Toolbar* toolbar;	//���� ��ü
public:
	TButton(string title);	//x��ġ�� Ÿ��Ʋ
	void setX(int x);
	int getX();
	void draw();	//view�� ȣ���� ���� ������
	void setToolbar(Toolbar*);
	void tempDraw();	//View�� ȣ���� ���� ������
	string getTitle();	//Ÿ��Ʋ��ȯ
	~TButton();
};

