#include "stdafx.h"
#include "View.h"
#include "stdio.h"
#include "iostream"
#include "string"
#include "Misc.h"
#include "Rect.h"
#include "Ellipse.h"
#include "CLine.h"
#include "MyButton.h"
#include "TButton.h"
#include "Toolbar.h"
#include "Component.h"
#include "Menu.h"

using namespace std;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);  // Prototype to external fun

//
//  �Լ�: MyRegisterClass()
//
//  �뵵: â Ŭ������ ����մϴ�.
//
ATOM View::MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJ2018));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL; //  MAKEINTRESOURCEW(IDC_PROJ2018);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

View::View(HINSTANCE hInstance):m_InstanceHandle(hInstance) {
	m_InstanceHandle = hInstance;
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_PROJ2018, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);
}

View::~View()
{

}

int View::getWindowWidth() {
	RECT r;
	GetWindowRect(m_WindowHandle, &r);
	return r.right - r.left;
}

BOOL View::initInstance( int nCmdShow )
{
	//m_InstanceHandle = hInstance; // �ν��Ͻ� �ڵ��� ���� ������ �����մϴ�.
	m_WindowHandle = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		0, 0, 1000,  600, nullptr, nullptr, m_InstanceHandle, nullptr);

	if (!m_WindowHandle)
	{
		return FALSE;
	}

	ShowWindow(m_WindowHandle, nCmdShow);
	UpdateWindow(m_WindowHandle);
	m_DCHandle = ::GetDC(m_WindowHandle);
	onInitialize();
	//mainView = new View(hWnd);

	return TRUE;
}

void View::OnLButtonDown(long wParam, MyEvent e)
{
	m_startx = e.x; m_starty = e.y;
	
	//���ٴ� �״�� ����
	if (toolbar->findToolbar(e.x, e.y)) {
		is_drawing = false;
		currentBtn = (TButton*)toolbar->find(e.x, e.y);
		if (currentBtn != nullptr) {
			currentBtn->downClick();
		}
	}
	else if (menubar->findMenubar(e.x, e.y)) {
		is_drawing = false;
	}
	else {
		is_drawing = true;
	}

	Menu* onCheck = (Menu*)menubar->find(e.x, e.y);	//�޴��� ����������
	if (onCheck) {
		if (selectMenu != 0) {	//�޴��� ������ִ� �����̸�
			if (selectMenu == onCheck) { //���� ��ư�ϰ��
				onCheck->setPush();
				selectMenu = 0;
				invalidate();
				return;
			}
			//�����ִµ� ���� ��ư�� ���� = �ٸ� ��ư�̴�.
			menubar->cleanCheck();	//�� Ǯ���ֱ�
			invalidate();
		}
		onCheck->setPush();
		onCheck->draw();
		selectMenu = onCheck;
		return;
	}
	
	if (selectMenu != 0) {
		MenuItem* check = (MenuItem*)selectMenu->find(e.x, e.y);
		//�ٸ� �޴��� ���� ���
		if(check != nullptr)
			check->clicked();
		menuClick = true;
	}
	menubar->cleanCheck();
	selectMenu = 0;
	//invalidate();
}

void View::drawIcon(int x, int y, HICON i) {
	DrawIcon(m_DCHandle, x, y, i);
}


void View::OnLButtonUp(long wParam, MyEvent e)
{
	if(currentBtn)
		currentBtn->upClick();
	if (menuClick == true) {
		menuClick = false;
		return;
	}
	//��ư üũ
	TButton* c = (TButton*)toolbar->find(e.x, e.y);
	if (c == currentBtn && c != 0 && currentBtn != 0) {
		c->clicked();
		currentBtn = 0;
		changeInfo = true;
		return;
	}

	//View�� ���� �������� �ȱ׷������� �Ѵ�.
	if (is_drawing == false || toolbar->findToolbar(e.x, e.y)) {	//���̳� ���� ��ġ�� toolbar ���ϰ�� ����
		changeInfo = true;
		return;
	}

	//�޴��ٵ� ����
	if (is_drawing == false || menubar->findMenubar(e.x, e.y)) {	//���̳� ���� ��ġ�� toolbar ���ϰ�� ����
		changeInfo = true;
		return;
	}

	//invalidate();
}

void View::OnRButtonDown(MyEvent e)
{
	// ���α׷� ���� ����� �����ϱ� ���� ���� ��ư Ŭ���� �Ʒ� ���� ȣ���ϰ� ��������ϴ�.
	//eraseRect(e.x, e.y, 100, 100);
	//::PostMessage(m_WindowHandle, WM_CLOSE, NULL, NULL);
}

void View::OnRButtonUp(MyEvent e)
{
	// 
}

void View::OnChar(long ch)
{
	// Ű���� �Է��� �Ǹ� �� �Լ��� �ڵ� ȣ��˴ϴ�.  cin�̳� getchar, scanf ����
	// ǥ�� �Է��Լ��� �۵����� ������ onchar �� �� �̿��ؾ� �մϴ�.


}

// ������ ���� �����ϱ�
void View::setPenColor(COLORREF color)
{
	thePen = CreatePen(PS_SOLID, 1, color);
	SelectObject(m_DCHandle, thePen);
}

// ���� ���� �β��� ���ÿ� �����ϱ�
void View::setPen(COLORREF color, int width)
{
	thePen = CreatePen(PS_SOLID, width, color);
	SelectObject(m_DCHandle, thePen);
}

// ä�� ���� �����ϴ� �Լ�.
void View::setFillColor(COLORREF color)
{
	theBrush = CreateSolidBrush(color);
	SelectObject(m_DCHandle, theBrush);
}

// ���� ���� �����ϴ� �Լ�.
void View::setTextColor(COLORREF color)
{
	SetTextColor(m_DCHandle, color);
}
// ���� ������ �����ϴ� �Լ�.
void View::setTextBkColor(COLORREF color)
{
	SetBkColor(m_DCHandle, color);
}

void View::drawRectangle(int x1, int y1, int x2, int y2)
{
	Rectangle(m_DCHandle, x1, y1, x2, y2);
}

void View::drawEllipse(int x1, int y1, int x2, int y2)
{
	Ellipse(m_DCHandle, x1, y1, x2, y2);
}

void View::drawLine(int x1, int y1, int x2, int y2)
{
	MoveToEx(m_DCHandle, x1, y1, NULL);
	LineTo(m_DCHandle, x2, y2);
}


void View::drawText(std::string str, int x, int y)
{
	TextOutA(m_DCHandle, x, y, str.c_str(), strlen(str.c_str()));
}

// ���  ���빰���� �ٽ� �׷��ִ� �Լ�.  ������ �ʿ��� ���̴�.
void View::draw()
{
	/*
	for (auto b : m_btnList) {
		b->draw();
	 }
	 */
	if (toolbar) {
		//if (Menu::drawstate == 0) {
			toolbar->draw();
		//}
	}
	if (menubar) {
		menubar->draw();
	}
}

// ȭ���� ���� ����� �ȵǾ� �ִٰ� �˸��� �Լ��Դϴ�.
// �� �Լ��� ȣ���ϸ� ȭ���� �������� 
// Main.cpp �ʿ� case WM_PAINT: �κ��� ����˴ϴ�.
// �ᱹ�� View ��ü�� display�� ����ǰ���.
void View::invalidate()
{
	InvalidateRect(m_WindowHandle, NULL, true);
}

// ��� �������� onInitialize �Լ����� �ʱ�ȭ����.
void View::onInitialize()
{
	// *** ��� ������Ʈ���� ���⿡�� �ʱ�ȭ����.
	toolbar = new Toolbar(this);	//VIew ��ü�� ���� �ʱ�ȭ
	menubar = new MenuBar(this);	//VIew ��ü�� ���� �ʱ�ȭ

	invalidate();
}

// �簢�� ��ġ�� �����.
void View::eraseRect(int x, int y, int   sizeX, int  sizeY) // �»�� x y �׸��� x�� y�� ũ��
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	setPenColor(RGB(255, 255, 255));
	setFillColor(RGB(255, 255, 255));
	drawRectangle(x, y, sizeX, sizeY);
}

// ������ ��ġ�� �����ش�.
RECT View::getClientRect()   // RECT���� left, right, top, bottom ��� ������ �ִ�.
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	RECT r;
	GetClientRect(m_WindowHandle, &r);
	return r;
}


// ���� ��Ʈ���� text�� ������� ��, ȭ��� �����ϴ� ũ�⸦ �����ִ� �Լ�
SIZE View::textSize(const std::string text)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	SIZE size;
	const char *s = text.c_str();
	GetTextExtentPoint32A(m_DCHandle, s, strlen(s), &size);
	return size;
}

/*
void View::addFigure(Figure *r) {
	m_rectList.push_back(r);
	r->setView(this);
}
*/
/*
void View::addButton(MyButton *b) {
	m_btnList.push_back(b);
	b->setView(this);
}
*/

/*
MyButton * View::findButton(int x, int y)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	for (auto b : m_btnList) {
		if (b->inside(x, y)) return b;
	}
	return nullptr;
}
*/

/*
bool View::onMouseDown(Event e){
	if(m_Menubar && m_MenuBar->onMOuseDOwn(e)){
		return true;
	}
	m_menubar->resetMenus();
	if(m_toolbar && m_toobar->onMouseDown(e)){
		m_menubar->resetMenus();
		invalidate();
		return true;
	}
	return false;
}

bool View::on
*/

void View::OnMouseMove(MyEvent e)
{
	if (selectMenu == 0)	//�޴��� �ȿ������¿�����
		toolbar->onMouseMove(e);
	menubar->onMouseMove(e);
	// TODO: ���⿡ ���� �ڵ� �߰�.
	/*
	MyButton *b = findButton(e.x, e.y);
	if (lastBtn == b) return;
	// hover in or out
	if (lastBtn != nullptr) {
		lastBtn->draw();
	} 
	if (b != nullptr) {
		b->tempDraw();
	}
	lastBtn = b;
	*/
}

/*
void View::buttonActions(MyButton *b) {
	
	if (b == nullptr)
		return;
	if (b == btnRect) {
		currentFig = Figure::RECT;
	} 
	else if (b == btnEllipse) {
		currentFig = Figure::ELLIPSE;
	} else {
		currentFig = Figure::LINE;
	}
	
}
*/