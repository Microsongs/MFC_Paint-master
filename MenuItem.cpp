#include "stdafx.h"
#include "MenuItem.h"
#include "Figure.h"

MenuItem::MenuItem(string title) : MyButton(0, 0, 50, 32, title)
{

}

void MenuItem::addActionListener(actionListener *e)
{
	m_listener.push_back(e);
}

void MenuItem::clicked() {
	for (auto i : m_listener) {
		i->actionPerformed(this);
	}
}

/*
int MenuItem::modeChange() {
	if (m_title == "����") {
		debugOutput("���� ��ư Ŭ��");
	}
	else if (m_title == "����") {
		debugOutput("���� ��ư Ŭ��");
	}
	else if (m_title == "�簢��") {
		return Figure::RECT;
	}
	else if (m_title == "Ÿ��") {
		return Figure::ELLIPSE;
	}
	else if (m_title == "����") {
		return Figure::LINE;
	}
	return 0;
}
*/

MenuItem::~MenuItem()
{
}
