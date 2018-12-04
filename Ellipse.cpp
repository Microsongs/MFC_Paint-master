#include "stdafx.h"
#include "Ellipse.h"
#include "View.h"

CEllipse::CEllipse(int x, int y, int x2, int y2,int pen,int fill)
	:Figure(x, y, x2, y2,pen,fill)
{
	if (m_x1 > m_x2) {  // 좌-우를 바꾼다.
		int t = m_x1; m_x1 = m_x2; m_x2 = t;
	}
	if (m_y1 > m_y2) {  // 상-하를 바꾼다.
		int t = m_y1; m_y1 = m_y2; m_y2 = t;
	}
}


CEllipse::~CEllipse()
{
}


void CEllipse::draw()
{
	// TODO: 여기에 구현 코드 추가.
	//m_view->setPenColor(RGB(0, 0, 0));
	//m_view->setFillColor(RGB(255, 255, 255));  //  시험 삼아 타원은 채움색을 흰 색으로 해본다.
	m_view->setPenColor(m_pen);
	m_view->setFillColor(m_fill);  //  시험 삼아 타원은 채움색을 흰 색으로 해본다.
	m_view->drawEllipse(m_x1, m_y1, m_x2, m_y2);
}

