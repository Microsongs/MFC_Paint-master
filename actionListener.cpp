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
	if (c->getTitle() == "사각형") {
		m_view->setDrawMode(Figure::RECT);
	}
	else if (c->getTitle() == "타원") {
		m_view->setDrawMode(Figure::ELLIPSE);
	}
	else if (c->getTitle() == "선분") {
		m_view->setDrawMode(Figure::LINE);
	}
	else if (c->getTitle() == "붉은선") {
		m_view->setPenColor(RGB(255, 0, 0));
	}
	else if (c->getTitle() == "녹색선") {
		m_view->setPenColor(RGB(0, 255, 0));
	}
	else if (c->getTitle() == "파란선") {
		m_view->setPenColor(RGB(0, 0, 255));
	}
	else if (c->getTitle() == "붉은색") {
		m_view->setFillColor(RGB(255, 0, 0));
	}
	else if (c->getTitle() == "녹색") {
		m_view->setFillColor(RGB(0, 255, 0));
	}
	else if (c->getTitle() == "파란색") {
		m_view->setFillColor(RGB(0, 0, 255));
	}
}
