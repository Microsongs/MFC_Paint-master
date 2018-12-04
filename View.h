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
	HWND m_WindowHandle;    //  ���� ���� handle
	HDC m_DCHandle;	// DC handle
	HBRUSH brushWhite, brushBlack;
	HPEN penWhite, penBlack;
	// �ӽ� ����
	int count = 0;
	HPEN thePen;
	HBRUSH theBrush;
	HINSTANCE m_InstanceHandle;
	WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
	WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.
	bool menuClick = false;
public:
	// �ʱ�ȭ �Լ���
	ATOM MyRegisterClass(HINSTANCE hInstance);
	BOOL initInstance(/*HINSTANCE hInstance, */int nCmdShow);

	// �̺�Ʈ ó�� �Լ���
	virtual void OnLButtonDown(MyEvent e);
	virtual void OnLButtonUp(MyEvent e);
	virtual void OnRButtonDown(MyEvent e);
	virtual void OnRButtonUp(MyEvent e);
	virtual void OnChar(long ch);

	void setPenColor(COLORREF color);         // �� ���� ����. �β��� 1�� �ڵ�.
	void setPen(COLORREF color, int width);   // �� ����� �β����� ����.
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
	//int m_startX, m_startY;  // 1�ܰ迡�� �ʿ��� ����
	//std::list<Figure *> m_rectList ;	//�θ� ���� �ʿ䰡 ����.
	//std::list<MyButton *> m_btnList;
	std::list<MenuItem*> menuItem;
	bool is_drawing;  //  
	int currentMenu = 0;
	int menuOpen = 0;
	Component* selectBar = 0;
	Component* selectMenu = 0;
	//MyButton * lastBtn = 0;
	//int currentFig = 0;	//��ü�� ������ X

	Toolbar *toolbar = 0;
	MenuBar* menubar = 0;
	//int drawmode = 0;	//��ü�� ������ x
	bool changeInfo = false;	//LBUTTONDOWN�� ���� ����, �θ𿡼� ���Ḧ ���ϹǷ�
	TButton* currentBtn = 0;	//���� ���� ��ưüũ

public:
	void eraseRect(int x, int y, int sizeX, int sizeY);
	RECT getClientRect();
	SIZE textSize(std::string text);

	void OnMouseMove(MyEvent e);	//override

	//virtual void addFigure(Figure *) = 0;	//����
	//void addButton(MyButton *b);	//�Ⱦ�
	//MyButton * btnRect, *btnEllipse, *btnLine;
	//MyButton * findButton(int x, int y);
	
	//void buttonActions(MyButton *b);	//�Ⱦ�
	int getWindowWidth();	//ȭ���� ������ �׸��� ���
};

