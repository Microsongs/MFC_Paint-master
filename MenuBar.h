#pragma once
#include "Container.h"
#include "actionListener.h"

class Menu;
class View;	//View��ü

//�޴��� ũ��� 50,32
class MenuBar : public Container
{
protected:
	//Component* File;	//File���ּ�
	//Component* Figure;	//Figure���ּ�

	Component *lastBtn;	//��������ư
public:
	MenuBar(View* v);
	bool findMenubar(int x, int y);	//�޴��� �� ����
	void addComponent(Component* btn);	//�޴��߰�
	~MenuBar();
	void draw();
	Component* find(int x, int y);
	Menu* pushCheck(Menu*);	//�޴� �ִ��� üũ
	void cleanCheck();
	void onMouseMove(MyEvent e);
	void clicked();
};

