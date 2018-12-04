#pragma once
#include "Container.h"
#include "actionListener.h"

class Menu;
class View;	//View객체

//메뉴의 크기는 50,32
class MenuBar : public Container
{
protected:
	//Component* File;	//File의주소
	//Component* Figure;	//Figure의주소

	Component *lastBtn;	//마지막버튼
public:
	MenuBar(View* v);
	bool findMenubar(int x, int y);	//메뉴바 내 여부
	void addComponent(Component* btn);	//메뉴추가
	~MenuBar();
	void draw();
	Component* find(int x, int y);
	Menu* pushCheck(Menu*);	//메뉴 있는지 체크
	void cleanCheck();
	void onMouseMove(MyEvent e);
	void clicked();
};

