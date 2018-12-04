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
	//Toolbar* toolbar;	//���� ��ü
	HICON hicon;
public:
	TButton(string title);	//x��ġ�� Ÿ��Ʋ
	//void setX(int x);
	//int getX();
	void draw();	//view�� ȣ���� ���� ������
	void tempDraw();	//View�� ȣ���� ���� ������
	//void setToolbar(Toolbar*);
	bool click = false;
	void upClick();
	void downClick();

	//string getTitle();	//Ÿ��Ʋ��ȯ
	void setIcon(HICON h);
	void clicked();
	void addActionListener(actionListener*);
	~TButton();
};

