#pragma once

#include "View.h"

class myView : public View
{
protected:
	std::list<Figure *> m_rectList;	//부모가 가질 필요가 없다.
	int currentFig = 0;	//도형부분
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

