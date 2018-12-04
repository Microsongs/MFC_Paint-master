#pragma once

#include "View.h"
#include "TButton.h"
#include <list>
#include "Misc.h"
//#include "Component.h"
#include "Container.h"
#include "actionListener.h"

using namespace std;

class View;
class TButton;

class Toolbar : public Container
{
private:
	//int m_xBar;	//x바의 길이
	//int m_yBar;	//y바의 길이
	
	//list<Component*> m_btn;	//TButton객체
	Component* RECT;		//Rect의주소
	Component* ELLIPSE;	//ELLIPSE의주소
	Component* LINE;		//LINE의주소

	Component *lastBtn;	//T버튼

	//리스너리스트
	
public:
	//View* m_view;	//VIew 객체
	Toolbar(View*);
	void draw();	//툴바만을 그림
	View* getView();
	void addComponent(Component *);	//T버튼 추가, Override
	bool findToolbar(int x,int y);	//툴바 내
	void onMouseMove(MyEvent e);	//버튼 이동
	int selectBtn(int x,int y);	//버튼 선택
	//TButton* find(int x, int y);	//버튼찾기
	Component* find(int x, int y);
	//void clicked();

	~Toolbar();
};

