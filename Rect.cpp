#include "stdafx.h"
#include "Rect.h"
#include "View.h"

Rect::Rect(int group, int type,int x, int y, int x2, int y2,int pen,int fill)
	:Figure(group,type,x,y,x2,y2,pen,fill)
{
	if (m_x1 > m_x2) {  // 좌-우를 바꾼다.
		int t = m_x1; m_x1 = m_x2; m_x2 = t;
	}
	if (m_y1 > m_y2) {  // 상-하를 바꾼다.
		int t = m_y1; m_y1 = m_y2; m_y2 = t;
	}
}


Rect::~Rect()
{
}


void Rect::draw()
{
	// 시험삼아서 사각형은 채움 색을 지정하지 않았다. 직전에 어떤 도형을 그렸느냐에 따라서 색이 달라지게 된다.
	//m_view->setPenColor(RGB(0, 0, 0));
	m_view->setPenColor(m_pen);
	m_view->setFillColor(m_fill);  //  시험 삼아 타원은 채움색을 흰 색으로 해본다.
	m_view-> drawRectangle(m_x1, m_y1, m_x2, m_y2);
}
