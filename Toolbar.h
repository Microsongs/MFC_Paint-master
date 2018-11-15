#pragma once

#include "View.h"
#include "TButton.h"
#include <list>
#include "Misc.h"

using namespace std;

class View;
class TButton;

class Toolbar
{
private:
	int m_xBar;	//x바의 길이
	int m_yBar;	//y바의 길이
	
	list<TButton*> m_btn;	//TButton객체
	TButton* RECT;		//Rect의주소
	TButton* ELLIPSE;	//ELLIPSE의주소
	TButton* LINE;		//LINE의주소

	TButton *lastBtn;
	int count;
public:
	View* m_view;	//VIew 객체
	Toolbar(View*);
	void draw();	//버튼과 바를 그림
	void addButton(TButton *);	//T버튼 추가
	View* getView();
	bool findToolbar(int x,int y);	//툴바 내
	TButton* findButton(int x, int y);	//버튼찾기
	void onMouseMove(int x,int y);	//버튼 이동
	int selectBtn(int x,int y);	//버튼 선택
	~Toolbar();
};

