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
	void draw();	//메뉴 그리기
	Component* find(int x, int y);	//menuitem찾기
	void addComponent(Component* item);

	//누른여부
	bool getPush();
	void clearPush();	//푸쉬 초기화
	void setPush();	//누르게 해줌, 임시변수
};
