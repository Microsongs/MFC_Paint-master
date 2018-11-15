#include "stdafx.h"
#include "myView.h"
#include "View.h"
#include "Figure.h"
#include "CLine.h"
#include "Ellipse.h"
#include "Rect.h"

myView::myView(HINSTANCE hInstance) : View(hInstance)
{
	//constructor
}

void myView::onInitialize() {
	View::onInitialize();
	toolbar->addButton(new TButton("R"));
	toolbar->addButton(new TButton("E"));
	toolbar->addButton(new TButton("L"));
}

void myView::OnLButtonDown(MyEvent e)
{
	//debugOutput("Click\n");  // IDE의 '출력' 창에 나온다.
	m_startX = e.x; m_startY = e.y;

	//툴바는 그대로 있음
	if (toolbar->findToolbar(e.x, e.y)) {
		is_drawing = false;
		currentFig = toolbar->selectBtn(e.x, e.y);
	}
	else
		is_drawing = true;

}

void myView::OnLButtonUp(MyEvent e) {
	//View::OnLButtonUp(e);
	//조건 만족 안하면 바로 종료해야하므로 부모호출하지 않고 재정의한다.

	if (currentFig == toolbar->selectBtn(e.x, e.y) && currentFig != 0) {	//전의 버튼과 현재 버튼이 동일할 경우, 둘다 0일경우 제외
	//debugOutput(currentFig);
		drawmode = currentFig;
		return;
	}
	
	else if (is_drawing == false || toolbar->findToolbar(e.x, e.y)) {	//전이나 현재 위치가 toolbar 위일경우 종료
		debugOutput("EE");
		return;
	}

	if (drawmode == Figure::LINE) { // 선분
		//figType = Figure::LINE;
		debugOutput("l");
		addFigure(new CLine(m_startX, m_startY, e.x, e.y));
	}
	else if (drawmode == Figure::ELLIPSE) {  // 타원
		debugOutput("E");
		addFigure(new CEllipse(m_startX, m_startY, e.x, e.y));
	}
	else if (drawmode == Figure::RECT) {  // 사각형
		debugOutput("R");
		addFigure(new Rect(m_startX, m_startY, e.x, e.y));
	}
	currentFig = 0;
	invalidate();
}

// 모든  내용물들을 다시 그려주는 함수.  수정이 필요할 것이다.
void myView::redrawAll()
{
	if (toolbar) {
		toolbar->draw();
		toolbar->buttonDraw();	//버튼을그림
		//툴바 그린 이후 다시 원색으로 변경
		setFillColor(RGB(255, 255, 255));
		setTextBkColor(RGB(255, 255, 255));
		for (auto r : m_rectList) {
			r->draw();
		}
	}
}


void myView::addFigure(Figure *r) {
	m_rectList.push_back(r);
	r->setView(this);
}

myView::~myView()
{
}
