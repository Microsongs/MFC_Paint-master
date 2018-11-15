#include "stdafx.h"
#include "TButton.h"
#include "Figure.h"

using namespace std;

TButton::TButton(string title) : 
	MyButton(0,0,32,32,title)
{

}
void TButton::setToolbar(Toolbar *bar) {
	toolbar = bar;
}

void TButton::setX(int x) {
	m_x = x;	//xÁÂÇ¥ ¼³Á¤
}

string TButton::getTitle() {
	return m_title;
}

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

int TButton::getX() {
	return m_x;
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

TButton::~TButton()
{
}
