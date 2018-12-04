#pragma once
#include "iostream"
#include "string"
#include "Proj2018.h"
#include "list"
#include "Misc.h"
#include "Toolbar.h"
#include "Container.h"
#include "MenuBar.h"
#include "Menu.h"
#include "MenuItem.h"
#include "TButton.h"

#define MAX_LOADSTRING 100

class Toolbar;
class Figure;

class View : public Container
{
public:
	View(HINSTANCE);
	~View();
protected:
	HWND m_WindowHandle;    //  바탕 윈도 handle
	HDC m_DCHandle;	// DC handle
	HBRUSH brushWhite, brushBlack;
	HPEN penWhite, penBlack;
	// 임시 변수
	int count = 0;
	HPEN thePen;
	HBRUSH theBrush;
	HINSTANCE m_InstanceHandle;
	WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
	WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
	bool menuClick = false;
public:
	// 초기화 함수들
	ATOM MyRegisterClass(HINSTANCE hInstance);
	BOOL initInstance(/*HINSTANCE hInstance, */int nCmdShow);

	// 이벤트 처리 함수들
	virtual void OnLButtonDown(MyEvent e);
	virtual void OnLButtonUp(MyEvent e);
	virtual void OnRButtonDown(MyEvent e);
	virtual void OnRButtonUp(MyEvent e);
	virtual void OnChar(long ch);

	void setPenColor(COLORREF color);         // 펜 색깔 설정. 두께는 1로 자동.
	void setPen(COLORREF color, int width);   // 펜 색깔과 두께까지 설정.
	void setFillColor(COLORREF color);
	void setTextColor(COLORREF color);
	void setTextBkColor(COLORREF color);
	void drawRectangle(int x, int y, int sizeX, int sizeY);
	void drawEllipse(int x, int y, int sizeX, int sizeY);
	void drawLine(int x, int y, int sizeX, int sizeY);
	void drawText(std::string str, int x, int y);
	void drawIcon(int x, int y, HICON i);
	virtual void draw();
	//void eraseAll();
	void invalidate();
	virtual void onInitialize();

protected:
	//int m_startX, m_startY;  // 1단계에서 필요한 변수
	//std::list<Figure *> m_rectList ;	//부모가 가질 필요가 없다.
	//std::list<MyButton *> m_btnList;
	std::list<MenuItem*> menuItem;
	bool is_drawing;  //  
	int currentMenu = 0;
	int menuOpen = 0;
	Component* selectBar = 0;
	Component* selectMenu = 0;
	//MyButton * lastBtn = 0;
	//int currentFig = 0;	//본체서 쓸이유 X

	Toolbar *toolbar = 0;
	MenuBar* menubar = 0;
	//int drawmode = 0;	//본체서 쓸이유 x
	bool changeInfo = false;	//LBUTTONDOWN을 위한 변수, 부모에서 종료를 못하므로
	TButton* currentBtn = 0;	//현재 눌린 버튼체크

public:
	void eraseRect(int x, int y, int sizeX, int sizeY);
	RECT getClientRect();
	SIZE textSize(std::string text);

	void OnMouseMove(MyEvent e);	//override

	//virtual void addFigure(Figure *) = 0;	//가상
	//void addButton(MyButton *b);	//안씀
	//MyButton * btnRect, *btnEllipse, *btnLine;
	//MyButton * findButton(int x, int y);
	
	//void buttonActions(MyButton *b);	//안씀
	int getWindowWidth();	//화면을 끝까지 그리는 방법
};

