#include "stdafx.h"
#include "Figure.h"
#include "View.h"

Figure::Figure(int x, int y, int x2, int y2, int pen, int fill)
	:m_x1(x), m_y1(y), m_x2(x2), m_y2(y2), m_pen(pen), m_fill(fill)
{

}

Figure::Figure(int x, int y, int x2, int y2, int pen)
	: m_x1(x), m_y1(y), m_x2(x2), m_y2(y2), m_pen(pen)
{
}


Figure::~Figure()
{
}

void Figure::setView(View *v) {
	m_view = v;
}
/*
int Figure::m_pen = RGB(0, 0, 0);	//초기화
int Figure::m_fill = RGB(255, 255, 255);	//초기화

void Figure::setPenColor(int color)
{
	if (color == redLINE) {
		m_pen = RGB(255, 0, 0);
	}
	else if (color == greenLINE) {
		m_pen = RGB(0, 255, 0);
	}
	else if (color == blueLINE) {
		m_pen = RGB(0, 0, 255);
	}
}

void Figure::setFillColor(int color)
{
	if (color == redPAINT) {
		m_fill = RGB(255, 0, 0);
	}
	else if (color == greenPAINT) {
		m_fill = RGB(0, 255, 0);
	}
	else if (color == bluePAINT) {
		m_fill = RGB(0, 0, 255);
	}
}

*/