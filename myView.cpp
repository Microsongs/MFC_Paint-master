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
	//debugOutput("Click\n");  // IDE�� '���' â�� ���´�.
	m_startX = e.x; m_startY = e.y;

	//���ٴ� �״�� ����
	if (toolbar->findToolbar(e.x, e.y)) {
		is_drawing = false;
		currentFig = toolbar->selectBtn(e.x, e.y);
	}
	else
		is_drawing = true;

}

void myView::OnLButtonUp(MyEvent e) {
	//View::OnLButtonUp(e);
	//���� ���� ���ϸ� �ٷ� �����ؾ��ϹǷ� �θ�ȣ������ �ʰ� �������Ѵ�.

	if (currentFig == toolbar->selectBtn(e.x, e.y) && currentFig != 0) {	//���� ��ư�� ���� ��ư�� ������ ���, �Ѵ� 0�ϰ�� ����
	//debugOutput(currentFig);
		drawmode = currentFig;
		return;
	}
	
	else if (is_drawing == false || toolbar->findToolbar(e.x, e.y)) {	//���̳� ���� ��ġ�� toolbar ���ϰ�� ����
		debugOutput("EE");
		return;
	}

	if (drawmode == Figure::LINE) { // ����
		//figType = Figure::LINE;
		debugOutput("l");
		addFigure(new CLine(m_startX, m_startY, e.x, e.y));
	}
	else if (drawmode == Figure::ELLIPSE) {  // Ÿ��
		debugOutput("E");
		addFigure(new CEllipse(m_startX, m_startY, e.x, e.y));
	}
	else if (drawmode == Figure::RECT) {  // �簢��
		debugOutput("R");
		addFigure(new Rect(m_startX, m_startY, e.x, e.y));
	}
	currentFig = 0;
	invalidate();
}

// ���  ���빰���� �ٽ� �׷��ִ� �Լ�.  ������ �ʿ��� ���̴�.
void myView::redrawAll()
{
	if (toolbar) {
		toolbar->draw();
		toolbar->buttonDraw();	//��ư���׸�
		//���� �׸� ���� �ٽ� �������� ����
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
