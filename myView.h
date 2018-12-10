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
	int frontmode = 0;		//���� ���
	Figure* tempFig = nullptr;

protected:
	std::vector<Figure *> m_rectList;	//�θ� ���� �ʿ䰡 ����.
	//std::vector<Figure*> *m_groupList;
	std::vector<Figure*> m_groupList[200];
	std::vector<Figure*>* tempGroup;
	int groupNum = 0;	//�׷찳��
	int tempGroupNum;	//�ӽñ׷� ��ġ
	

	//int currentFig = 0;	//�����κ�

	int drawmode = 0;		//�׸��� ���
	int currentItem = 0;	//�����ۺκ�

	//���� �������
	int figurePen;	//��
	int figureFill;	//����

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
//�׼Ǹ�����
	void actionPerformed(Component*);
};

