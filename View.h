#pragma once
#include "iostream"
#include "string"
#include "Proj2018.h"
#include "list"
#include "Misc.h"
#include "Toolbar.h"

#define MAX_LOADSTRING 100

class Toolbar;
class Figure;
class MyButton;
class View
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
	virtual void redrawAll();
	//void eraseAll();
	void invalidate();
	virtual void onInitialize();

protected:
	int m_startX, m_startY;  // 1�ܰ迡�� �ʿ��� ����
	//std::list<Figure *> m_rectList ;	//�θ� ���� �ʿ䰡 ����.
	//std::list<MyButton *> m_btnList;
	bool is_drawing;  //  
	//MyButton * lastBtn = 0;
	//int currentFig = 0;	//��ü�� ������ X
	Toolbar *toolbar = 0;
	//int drawmode = 0;	//��ü�� ������ x
public:
	void eraseRect(int x, int y, int sizeX, int sizeY);
	RECT getClientRect();
	SIZE textSize(std::string text);

	//virtual void addFigure(Figure *) = 0;	//����
	//void addButton(MyButton *b);	//�Ⱦ�
	//MyButton * btnRect, *btnEllipse, *btnLine;
	//MyButton * findButton(int x, int y);
	void OnMouseMove(MyEvent e);
	//void buttonActions(MyButton *b);	//�Ⱦ�
	int getWindowWidth();	//ȭ���� ������ �׸��� ���
};

