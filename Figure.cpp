#include "stdafx.h"
#include "Figure.h"
#include "View.h"

Figure::Figure(int group, int type, int x, int y, int x2, int y2, int pen, int fill)
	:m_group(group),m_type(type), m_x1(x), m_y1(y), m_x2(x2), m_y2(y2), m_pen(pen), m_fill(fill)
{

}

Figure* Figure::inside(int x, int y) {
	if (m_x1 <= x && x <= m_x2 && m_y1 <= y && y <= m_y2) {
		return this;
	}
	return nullptr;
}

void Figure::setGroup(int g)
{
	m_group = g;
}

void Figure::setStartX(int x1)
{
	m_x1 = x1;
}

void Figure::setStartY(int y1)
{
	m_y1 = y1;
}

void Figure::setEndX(int x2)
{
	m_x2 = x2;
}

void Figure::setEndY(int y2)
{
	m_y2 = y2;
}

/*
Figure::Figure(int type, int x, int y, int x2, int y2, int pen)
	: m_type(type), m_x1(x), m_y1(y), m_x2(x2), m_y2(y2), m_pen(pen)
{
}
*/


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

int Figure::getGroup()
{
	return m_group;
}

int Figure::getType()
{
	return m_type;
}

int Figure::getStartX()
{
	return m_x1;
}

int Figure::getStartY()
{
	return m_y1;
}

int Figure::getEndX()
{
	return m_x2;
}

int Figure::getEndY()
{
	return m_y2;
}

int Figure::getPen()
{
	return m_pen;
}

int Figure::getFill()
{
	return m_fill;
}
