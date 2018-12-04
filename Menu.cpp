#include "stdafx.h"
#include "Menu.h"
#include "myView.h"
#include "MenuItem.h"
#include "Figure.h"
#include "Windows.h"

using std::string;

int Menu::itemCnt = 0;

Menu::Menu(string title) :Container(0, 0, 50, 32, title)
{
	//constructor
}

Menu::Menu(string title,View* v) : Container(0, 0, 50, 32, title)
{
	itemCnt++;
	m_view = v;
	count = 1;
	pushed = 0;
	//constructor
}

void Menu::draw() {
	//기본적으로 그리는 것
	if (m_view) {
		m_view->setPenColor(m_normal_bg_color);
		m_view->setFillColor(m_normal_bg_color);
		m_view->drawRectangle(m_startx, m_starty, m_startx + m_sizex, m_starty + m_sizey);
		SIZE s = m_view->textSize(m_title);
		int xoff = (m_sizex - s.cx) / 2;
		int yoff = (m_sizey - s.cy) / 2;
		m_view->setTextBkColor(m_normal_bg_color);
		m_view->drawText(m_title, m_startx + xoff, m_starty + yoff);
	}
	if (pushed) {	//눌려 있는 경우
		//m_view->invalidate();
		//debugOutput("눌렀따오\n");
		Container::draw();
	}
}

Component* Menu::find(int x, int y) {
	for (auto b : m_list) {
		if (b->inside(x, y))
			return (MenuItem*)b;	//캐스팅
	}
	return nullptr;
}

bool Menu::getPush() {
	return pushed;
}

void Menu::clearPush() {
	pushed = false;
}

void Menu::setPush() {
	if (pushed == true) {
		pushed = false;
	}
	else {
		pushed = true;
	}
}

void Menu::addComponent(Component* item) {
	item->setY(count * 32);	//들어온 개수 * 32크기
	item->setX((itemCnt-1) * 50);	//들어온 개수 * 50크기
	//btn->setToolbar(this);
	item->setView(m_view);

	m_list.push_back(item);
	count++;

}

Menu::~Menu()
{
}