#pragma once

#include "View.h"

class myView : public View
{
protected:
	std::list<Figure *> m_rectList;	//�θ� ���� �ʿ䰡 ����.
	int currentFig = 0;	//�����κ�
	int drawmode = 0;
public:
	myView(HINSTANCE hInstance);
	void onInitialize();		//override
	~myView();
	void OnLButtonUp(MyEvent e);	//override
	void redrawAll();			//override
	void addFigure(Figure *r);	//override
	void OnLButtonDown(MyEvent e);	//override
};

