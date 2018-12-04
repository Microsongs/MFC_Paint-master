#include "stdafx.h"
#include "CLine.h"
#include "View.h"

CLine::CLine(int x1, int y1, int x2, int y2,int pen)
	:Figure(x1, y1, x2, y2,pen)
{
}


CLine::~CLine()
{
}


void CLine::draw()
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	//m_view->setPenColor(RGB(0, 0, 0));
	m_view->setPenColor(m_pen);
	m_view->drawLine(m_x1, m_y1, m_x2, m_y2);
}