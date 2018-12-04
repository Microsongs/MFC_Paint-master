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
	std::list<Figure *> m_rectList;	//�θ� ���� �ʿ䰡 ����.

	std::list<saveFigure*> txtList;	//�ؽ�Ʈ ����
	//int currentFig = 0;	//�����κ�

	int drawmode = 0;
	int currentItem = 0;	//�����ۺκ�

	//���� �������
	int figurePen;	//��
	int figureFill;	//����

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
//�׼Ǹ�����
	void actionPerformed(Component*);
};

