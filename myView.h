#pragma once

#include "View.h"
#include "Component.h"
#include "Menu.h"
#include "Misc.h"
#include "actionListener.h"
#include "saveFigure.h"

class myView : public View, public actionListener
{
private:
	Component* File_Save;
	Component* File_Open;

	Component* Fig_Rect;
	Component* Fig_Ellipse;
	Component* Fig_Line;

protected:
	std::list<Figure *> m_rectList;	//부모가 가질 필요가 없다.

	std::list<saveFigure*> txtList;	//텍스트 저장
	//int currentFig = 0;	//도형부분

	int drawmode = 0;
	int currentItem = 0;	//아이템부분

	//색상 변경관련
	int figurePen;	//선
	int figureFill;	//색상

	//void OnMouseMove(MyEvent e);
public:
	myView(HINSTANCE hInstance);
	void onInitialize();		//override
	~myView();
	void OnLButtonUp(MyEvent e);	//override
	void draw();			//override
	void addFigure(Figure *r);	//override
	void OnLButtonDown(MyEvent e);	//override
	void setDrawMode(int drawmode);
	void setFigure(int figure);
	void setPenColor(int pen);
	void setFillColor(int fill);
	void createFigure(MyEvent e);
//액션리스너
	void actionPerformed(Component*);
};

