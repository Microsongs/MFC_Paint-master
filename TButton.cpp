#include "stdafx.h"
#include "TButton.h"
#include "Figure.h"

using namespace std;

TButton::TButton(string title) : 
	MyButton(0,32,32,32,title)
{

}

void TButton::clicked() {	//액션 리스너들의 액션퍼폼드 실행
	for (auto i : myListener) {
		i->actionPerformed(this);
	}
}

void TButton::addActionListener(actionListener *e)
{
	myListener.push_back(e);
}

// 평상시 그리는 함수 draw
void TButton::draw()
{
	if (click == true) {
		m_view->setFillColor(RGB(170,170,170));
		m_view->setPenColor(RGB(170,170,170));
	}
	else {
		m_view->setFillColor(m_normal_bg_color);
		m_view->setPenColor(m_normal_bg_color);
	}
	m_view->drawRectangle(m_startx, m_starty, m_startx + m_sizex, m_starty + m_sizey);
	m_view->drawIcon(m_startx, m_starty, hicon);
}

void TButton::setIcon(HICON h) {
	hicon = h;
}

void TButton::tempDraw() {
	m_view->setFillColor(m_temp_bg_color);
	m_view->setPenColor(m_temp_bg_color);
	m_view->drawRectangle(m_startx, m_starty, m_startx + m_sizex, m_starty + m_sizey);
	m_view->drawIcon(m_startx, m_starty, hicon);
}

void TButton::downClick()
{
	click = true;
}
void TButton::upClick()
{
	click = false;
	this->tempDraw();
}
/*
void TButton::setToolbar(Toolbar *bar) {
	toolbar = bar;
}
*/
/*
void TButton::setX(int x) {
	m_x = x;	//x좌표 설정
}
*/

/*
string TButton::getTitle() {
	return m_title;
}
*/

/*
void TButton::draw() {
	toolbar->getView()->setPenColor(m_normal_bg_color);
	toolbar->getView()->setFillColor(m_normal_bg_color);
	toolbar->getView()->drawRectangle(m_x, m_y, m_x + m_sizex, m_y + m_sizey);

	SIZE s = toolbar->getView()->textSize(m_title);
	int xoff = (m_sizex - s.cx) / 2;
	int yoff = (m_sizey - s.cy) / 2;
	
	toolbar->getView()->setTextBkColor(m_normal_bg_color);
	toolbar->getView()->drawText(m_title, m_x+xoff, m_y+yoff);
}

void TButton::tempDraw() {
	toolbar->getView()->setPenColor(m_normal_bg_color);
	toolbar->getView()->setFillColor(m_temp_bg_color);
	toolbar->getView()->drawRectangle(m_x, m_y, m_x + m_sizex, m_y + m_sizey);
	SIZE s = toolbar->getView()->textSize(m_title);
	int xoff = (m_sizex - s.cx) / 2;
	int yoff = (m_sizey - s.cy) / 2;
	toolbar->getView()->setPenColor(m_normal_bg_color);
	toolbar->getView()->setTextBkColor(m_temp_bg_color);
	toolbar->getView()->drawText(m_title, m_x + xoff, m_y + yoff);
}
*/

/*
int TButton::getX() {
	return m_sizex;
}
*/


TButton::~TButton()
{
}
