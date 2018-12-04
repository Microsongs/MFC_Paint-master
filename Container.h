#pragma once

#include "Component.h"
#include "Misc.h"
#include <list>

using namespace std;

class View;

class Container : public Component
{
protected:
	list<Component*> m_list;	//������ ����Ʈ
	View* m_view;
	int count;
public:
	Container();
	Container(int x, int y, int sizex, int sizey, std::string title);
	Container(View* v);
	~Container();
	virtual void addComponent(Component *);	//T��ư �߰�
	void draw();	//draw�Լ�
	Component* find(int x, int y);	//��ưã��
	virtual void onMouseMove(MyEvent e);	//view�� toolbar ���� override�ϴ°�
	virtual void clicked();
};

