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
	count = 0;	//���� ����
}

void MenuBar::clicked() {
	//m_view->
}

Component* MenuBar::find(int x, int y) {
	for (auto b : m_list) {
		if (b->inside(x, y))
			return (Menu*)b;	//ĳ����
	}
	return nullptr;
}

void MenuBar::addComponent(Component* menu) {
	menu->setX(count * 50);	//���� ���� * 32ũ��
	menu->setView(m_view);
	
	/*
	if (menu->getTitle() == "����") {
		menu->setView(m_view);
		File = menu;
		File->addComponent(new MenuItem("����"));
		File->addComponent(new MenuItem("����"));
	}
	else if (menu->getTitle() == "����") {
		menu->setView(m_view);
		Figure = menu;
		Figure->addComponent(new MenuItem("�簢��"));
		Figure->addComponent(new MenuItem("Ÿ��"));
		Figure->addComponent(new MenuItem("����"));
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
	//menubar �Ʒ� ����
	Container::m_view->drawRectangle(0, 0, m_sizex, m_sizey);	//0,0���� size_x,sizey����
	Container::draw();	//�޴� ���巯��
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
		if (i == menu && check->getPush() == true) {	//�޴� ��ü�� �ٸ��鼭 �������� ��
			return check;
		}
	}
	return nullptr;
}


MenuBar::~MenuBar()
{
}
