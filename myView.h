#pragma once

#include "View.h"
#include "Component.h"
#include "Menu.h"
#include "Misc.h"
#include "actionListener.h"
#include <vector>

class myView : public View, public actionListener
{
private:
	Component* File_Save;
	Component* File_Open;

	Component* Fig_Rect;
	Component* Fig_Ellipse;
	Component* Fig_Line;
protected:
	int frontmode = 0;		//전의 모드
	Figure* tempFig = nullptr;

protected:
	std::vector<Figure *> m_rectList;	//부모가 가질 필요가 없다.
	//std::vector<Figure*> *m_groupList;
	std::vector<Figure*> m_groupList[200];
	std::vector<Figure*>* tempGroup;
	int groupNum = 0;	//그룹개수
	int tempGroupNum;	//임시그룹 위치
	

	//int currentFig = 0;	//도형부분

	int drawmode = 0;		//그리는 모드
	int currentItem = 0;	//아이템부분

	//색상 변경관련
	int figurePen;	//선
	int figureFill;	//색상

	//void OnMouseMove(MyEvent e);
public:
	myView(HINSTANCE hInstance);
	void onInitialize();		//override
	~myView();
	void OnLButtonUp(long wParam, MyEvent e);	//override
	void OnLButtonDown(long wParam, MyEvent e);	//override
	void draw();			//override
	void addFigure(Figure *r);	//override
	
	void setDrawMode(int drawmode);
	void setFigure(int figure);
	void setPenColor(int pen);
	void setFillColor(int fill);
	void createFigure(MyEvent e);

	void addGroup(Figure *);

	const static int MOVE = 101;		//shift
	const static int COPY = 102;		//ctrl
	const static int GROUP = 103;		//alt
//액션리스너
	void actionPerformed(Component*);
};

