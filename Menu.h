#pragma once

#include <list>
#include "Container.h"
#include "actionListener.h"

class View;

class Menu : public Container
{
private:
	static int itemCnt;
	bool pushed;
	static Menu* state;

	list<actionListener*> listener;
public:
	Menu(string title);
	Menu(string title, View*);
	~Menu();
	void draw();	//�޴� �׸���
	Component* find(int x, int y);	//menuitemã��
	void addComponent(Component* item);

	//��������
	bool getPush();
	void clearPush();	//Ǫ�� �ʱ�ȭ
	void setPush();	//������ ����, �ӽú���
};
