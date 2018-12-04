#include "stdafx.h"
#include "MenuBar.h"
#include "View.h"
#include "Menu.h"
#include "MenuItem.h"

MenuBar::MenuBar(View* v) : Container(v)
{
	//constructor
	m_sizex = m_view->getWindowWidth();
	m_sizey = 32;
	count = 0;	//들어온 개수
}

void MenuBar::clicked() {
	//m_view->
}

Component* MenuBar::find(int x, int y) {
	for (auto b : m_list) {
		if (b->inside(x, y))
			return (Menu*)b;	//캐스팅
	}
	return nullptr;
}

void MenuBar::addComponent(Component* menu) {
	menu->setX(count * 50);	//들어온 개수 * 32크기
	menu->setView(m_view);
	
	/*
	if (menu->getTitle() == "파일") {
		menu->setView(m_view);
		File = menu;
		File->addComponent(new MenuItem("저장"));
		File->addComponent(new MenuItem("열기"));
	}
	else if (menu->getTitle() == "도형") {
		menu->setView(m_view);
		Figure = menu;
		Figure->addComponent(new MenuItem("사각형"));
		Figure->addComponent(new MenuItem("타원"));
		Figure->addComponent(new MenuItem("선분"));
	}
	*/

	m_list.push_back(menu);
	count++;
}

bool MenuBar::findMenubar(int x, int y) {
	return (0 <= x && x <= m_sizex
		&& 0 <= y && y <= m_sizey);
}

void MenuBar::onMouseMove(MyEvent e) {
	Component *b = find(e.x, e.y);
	if (lastBtn == b) return;
	// hover in or out
	if (lastBtn != nullptr) {
		lastBtn->draw();
	}
	if (b != nullptr) {
		b->tempDraw();
	}
	lastBtn = b;
}

void MenuBar::draw() {
	m_view->setPenColor(RGB(230, 230, 230));
	m_view->setFillColor(RGB(230, 230, 230));
	Container::m_view->setTextBkColor(RGB(230, 230, 230));
	//menubar 아래 툴바
	Container::m_view->drawRectangle(0, 0, m_sizex, m_sizey);	//0,0에서 size_x,sizey까지
	Container::draw();	//메뉴 리드러우
}

void MenuBar::cleanCheck() {
	for (auto i : m_list) {
		Menu* clean = (Menu*)i;
		clean->clearPush();
	}
}

Menu* MenuBar::pushCheck(Menu* menu) {
	Menu* check;
	for (auto i : m_list) {
		check = (Menu*)i;
		//debugOutput(i->)
		if (i == menu && check->getPush() == true) {	//메뉴 객체와 다르면서 눌려있을 때
			return check;
		}
	}
	return nullptr;
}


MenuBar::~MenuBar()
{
}
