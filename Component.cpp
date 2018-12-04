#include "stdafx.h"
#include "Component.h"

#include "stdafx.h"
#include "View.h"
using namespace std;

/*
View* Component::getViewInstance(){
	if(getContainer() == nullptr)
		return (View*)this;
	else
		return getContainer()->getViewInstance();
}

Container* Component::getContainer(){
	return m_container;
}

*/

Component::Component(int x, int y, int sizex, int sizey, std::string title)
	:m_startx(x), m_starty(y), m_sizex(sizex), m_sizey(sizey), m_title(title)
{
}

void Component::addComponent(Component* c) {
	debugOutput("no use");
}

Component* Component::find(int x, int y) {
	debugOutput("no use");
	return nullptr;
}

Component::Component() {}

Component::Component(std::string title) {
	m_title = title;
}

Component::~Component()
{
}

// 평상시 그리는 함수 draw
void Component::draw()
{
	m_view->setPenColor(m_normal_bg_color);
	m_view->setFillColor(m_normal_bg_color);
	m_view->drawRectangle(m_startx, m_starty, m_startx + m_sizex, m_starty + m_sizey);
	SIZE s = m_view->textSize(m_title);
	int xoff = (m_sizex - s.cx) / 2;
	int yoff = (m_sizey - s.cy) / 2;
	m_view->setTextBkColor(m_normal_bg_color);
	m_view->drawText(m_title, m_startx + xoff, m_starty + yoff);
}

bool Component::getPush() {
	debugOutput("벛얼\n");
	return false;
}

void Component::setX(int x) {
	m_startx = x;	//x좌표 설정
}

void Component::setY(int y) {
	m_starty = y;	//y좌표 설정
}

string Component::getTitle() {
	return m_title;
}

void Component::addActionListener(actionListener*) {
	debugOutput("액션 리스너 추가");
}

// 버튼 위로 마우스가 올라왔을 때 그림 그리는 함수.
void Component::tempDraw() {
	m_view->setFillColor(m_temp_bg_color);
	m_view->setPenColor(m_temp_bg_color);
	m_view->drawRectangle(m_startx, m_starty, m_startx + m_sizex, m_starty + m_sizey);
	SIZE s = m_view->textSize(m_title);
	int xoff = (m_sizex - s.cx) / 2;
	int yoff = (m_sizey - s.cy) / 2;
	m_view->setTextBkColor(m_temp_bg_color);
	m_view->drawText(m_title, m_startx + xoff, m_starty + yoff);
}

// 마우스가 버튼 위치에 있는지 판별하는 함수
bool Component::inside(int x, int y) {
	return (m_startx <= x && x <= m_startx + m_sizex
		&& m_starty <= y && y <= m_starty + m_sizey);
}

/*
void MyButton::action() {
	debugOutput(m_title);
	m_view->buttonActions(this);
}
*/

void Component::setView(View *v) {
	m_view = v;
}