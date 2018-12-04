#include "stdafx.h"
#include "actionListener.h"
#include "TButton.h"
#include "myView.h"
#include "Figure.h"

tButtonActionListener::tButtonActionListener(myView * v)
{
	m_view = v;
}

void tButtonActionListener::actionPerformed(Component *c)
{
	if (c->getTitle() == "R") {
		m_view->setFigure(Figure::RECT);
	}
	else if (c->getTitle() == "E") {
		m_view->setFigure(Figure::ELLIPSE);
	}
	else if (c->getTitle() == "L") {
		m_view->setFigure(Figure::LINE);
	}
	else if (c->getTitle() == "RL") {
		m_view->setPenColor(RGB(255,0,0));
	}
	else if (c->getTitle() == "GL") {
		m_view->setPenColor(RGB(0, 255, 0));
	}
	else if (c->getTitle() == "BL") {
		m_view->setPenColor(RGB(0, 0, 255));
	}
	else if (c->getTitle() == "RP") {
		m_view->setFillColor(RGB(255, 0, 0));
	}
	else if (c->getTitle() == "GP") {
		m_view->setFillColor(RGB(0, 255, 0));
	}
	else if (c->getTitle() == "BP") {
		m_view->setFillColor(RGB(0, 0, 255));
	}
}

menuItemActionListener::menuItemActionListener(myView * v)
{
	m_view = v;
}

void menuItemActionListener::actionPerformed(Component *c)
{
	if (c->getTitle() == "�簢��") {
		m_view->setDrawMode(Figure::RECT);
	}
	else if (c->getTitle() == "Ÿ��") {
		m_view->setDrawMode(Figure::ELLIPSE);
	}
	else if (c->getTitle() == "����") {
		m_view->setDrawMode(Figure::LINE);
	}
	else if (c->getTitle() == "������") {
		m_view->setPenColor(RGB(255, 0, 0));
	}
	else if (c->getTitle() == "�����") {
		m_view->setPenColor(RGB(0, 255, 0));
	}
	else if (c->getTitle() == "�Ķ���") {
		m_view->setPenColor(RGB(0, 0, 255));
	}
	else if (c->getTitle() == "������") {
		m_view->setFillColor(RGB(255, 0, 0));
	}
	else if (c->getTitle() == "���") {
		m_view->setFillColor(RGB(0, 255, 0));
	}
	else if (c->getTitle() == "�Ķ���") {
		m_view->setFillColor(RGB(0, 0, 255));
	}
}
