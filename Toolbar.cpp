#include "stdafx.h"
#include "Toolbar.h"
#include "View.h"
#include "Figure.h"

Toolbar::Toolbar(View* v) : Container(v)
{
	//m_view = v;
	m_sizex = m_view->getWindowWidth();
	m_sizey = 32;
	count = 0;	//들어온 개수
}

void Toolbar::draw() {
	m_view->setPenColor(RGB(230, 230, 230));
	m_view->setFillColor(RGB(230, 230, 230));
	Container::m_view->setTextBkColor(RGB(230, 230, 230));
	//menubar 아래 툴바
	Container::m_view->drawRectangle(0, 32, m_sizex, 32 + m_sizey);	//0,32에서 size_x,32+sizey까지
	Container::draw();
}

int Toolbar::selectBtn(int x,int y) {
	Component* b = find(x, y);
	if (b == RECT) {
		return Figure::RECT;
	}
	else if (b == ELLIPSE) {
		return Figure::ELLIPSE;
	}
	else if (b == LINE) {
		return Figure::LINE;
	}
	/*
	if (y >= 0 && y <= 32) {
		return (int)(x / 32) + 1;
	}
	*/
	return 0;	//선택된 것이 없음
}

void Toolbar::addComponent(Component* btn) {
	
	btn->setX(count * 32);	//들어온 개수 * 32크기
	//btn->setToolbar(this);
	btn->setView(m_view);
	if (btn->getTitle() == "R") {
		RECT = btn;
	}
	else if (btn->getTitle() == "E") {
		ELLIPSE = btn;
	}
	else if (btn->getTitle() == "L") {
		LINE = btn;
	}
	m_list.push_back(btn);
	count++;
}

View* Toolbar::getView() {
	return m_view;
}

bool Toolbar::findToolbar(int x,int y) {
	return (0 <= x && x <= m_sizex
		&& 32 <= y && y <= 32 + m_sizey);
}

/*
TButton* Toolbar::find(int x,int y) {
	for (auto b : m_list) {
		if (b->inside(x, y)) 
			return (TButton*)b;	//캐스팅
	}
	return nullptr;
}
*/

Component* Toolbar::find(int x, int y) {
	for (auto b : m_list) {
		if (b->inside(x, y))
			return (TButton*)b;	//캐스팅
	}
	return nullptr;
}


void Toolbar::onMouseMove(MyEvent e) {
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

Toolbar::~Toolbar()
{
}
