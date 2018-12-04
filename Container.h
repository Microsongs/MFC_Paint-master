#pragma once

#include "Component.h"
#include "Misc.h"
#include <list>

using namespace std;

class View;

class Container : public Component
{
protected:
	list<Component*> m_list;	//데이터 리스트
	View* m_view;
	int count;
public:
	Container();
	Container(int x, int y, int sizex, int sizey, std::string title);
	Container(View* v);
	~Container();
	virtual void addComponent(Component *);	//T버튼 추가
	void draw();	//draw함수
	Component* find(int x, int y);	//버튼찾기
	virtual void onMouseMove(MyEvent e);	//view와 toolbar 전부 override하는것
	virtual void clicked();
};

