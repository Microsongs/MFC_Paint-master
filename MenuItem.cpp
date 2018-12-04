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
	if (m_title == "저장") {
		debugOutput("저장 버튼 클릭");
	}
	else if (m_title == "열기") {
		debugOutput("열기 버튼 클릭");
	}
	else if (m_title == "사각형") {
		return Figure::RECT;
	}
	else if (m_title == "타원") {
		return Figure::ELLIPSE;
	}
	else if (m_title == "선분") {
		return Figure::LINE;
	}
	return 0;
}
*/

MenuItem::~MenuItem()
{
}
