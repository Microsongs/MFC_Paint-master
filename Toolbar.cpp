#include "stdafx.h"
#include "Toolbar.h"
#include "View.h"
#include "Figure.h"

Toolbar::Toolbar(View* v)
{
	m_view = v;
	m_xBar = m_view->getWindowWidth();
	m_yBar = 32;
	count = 0;	//들어온 개수
}

void Toolbar::draw() {
	m_view->setPenColor(RGB(230, 230, 230));
	m_view->setFillColor(RGB(230, 230, 230));
	m_view->setTextBkColor(RGB(230, 230, 230));
	m_view->drawRectangle(0, 0, m_xBar, m_yBar);
}
void Toolbar::buttonDraw() {
	for (auto i : m_btn) {
		i->draw();
	}
}

int Toolbar::selectBtn(int x,int y) {
	TButton* b = findButton(x, y);
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

void Toolbar::addButton(TButton* btn) {
	btn->setX(count * 32);	//들어온 개수 * 32크기
	btn->setToolbar(this);
	if (btn->getTitle() == "R") {
		RECT = btn;
	}
	else if (btn->getTitle() == "E") {
		ELLIPSE = btn;
	}
	else if (btn->getTitle() == "L") {
		LINE = btn;
	}
	m_btn.push_back(btn);
	count++;
}

View* Toolbar::getView() {
	return m_view;
}

bool Toolbar::findToolbar(int x,int y) {
	return (0 <= x && x <= m_xBar
		&& 0 <= y && y <= m_yBar);
}

TButton* Toolbar::findButton(int x,int y) {
	for (auto b : m_btn) {
		if (b->inside(x, y)) 
			return b;
	}
	return nullptr;
}

void Toolbar::onMouseMove(int x, int y) {
	TButton *b = findButton(x, y);
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
