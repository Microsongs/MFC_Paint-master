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

using namespace std;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);  // Prototype to external fun

//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
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
	//m_InstanceHandle = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.
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

void View::OnLButtonDown(MyEvent e)
{
	//debugOutput("Click\n");  // IDE의 '출력' 창에 나온다.
	m_startX = e.x; m_startY = e.y;

	//툴바는 그대로 있음
	if (toolbar->findToolbar(e.x, e.y)) {
		is_drawing = false;
		//currentFig = toolbar->selectBtn(e.x,e.y);
	}
	else
		is_drawing = true;

	/*
	MyButton *b = findButton(e.x, e.y);
	is_drawing = b == nullptr ? true : false;
	*/
}

void View::OnLButtonUp(MyEvent e)
{
	/*
	//MyButton *b = findButton(e.x, e.y);
	if (b) {
		b->action();
		return; 
	}
	*/
	// no button is clicked.
	debugOutput(toolbar->selectBtn(e.x, e.y));
	/*
	if (currentFig == toolbar->selectBtn(e.x, e.y) && currentFig != 0) {	//전의 버튼과 현재 버튼이 동일할 경우, 둘다 0일경우 제외
		//debugOutput(currentFig);
		drawmode = currentFig;

		return;
	}
	*/

	//View는 툴바 위에서만 안그려지도록 한다.
	if (is_drawing == false || toolbar->findToolbar(e.x, e.y)) {	//전이나 현재 위치가 toolbar 위일경우 종료
		debugOutput("EE");
		return;
	}
	
	/*
	if (drawmode == Figure::LINE) { // 선분
			//figType = Figure::LINE;
		debugOutput("l");
		addFigure(new CLine(m_startX, m_startY, e.x, e.y));
	}
	else if (drawmode == Figure::ELLIPSE) {  // 타원
		debugOutput("E");
		addFigure(new CEllipse(m_startX, m_startY, e.x, e.y));
	}
	else if (drawmode == Figure::RECT) {  // 사각형
		debugOutput("R");
		addFigure(new Rect(m_startX, m_startY, e.x, e.y));
	}
	*/
	
	//currentFig = 0;	//초기화
	invalidate();
}

void View::OnRButtonDown(MyEvent e)
{
	// 프로그램 종료 방법을 데모하기 위해 우측 버튼 클릭시 아래 줄을 호출하게 만들었습니다.
	//eraseRect(e.x, e.y, 100, 100);
	//::PostMessage(m_WindowHandle, WM_CLOSE, NULL, NULL);
}

void View::OnRButtonUp(MyEvent e)
{
	// 
}

void View::OnChar(long ch)
{
	// 키보드 입력이 되면 이 함수가 자동 호출됩니다.  cin이나 getchar, scanf 같은
	// 표준 입력함수는 작동하지 않으니 onchar 를 잘 이용해야 합니다.


}

// 라인의 색을 지정하기
void View::setPenColor(COLORREF color)
{
	thePen = CreatePen(PS_SOLID, 1, color);
	SelectObject(m_DCHandle, thePen);
}

// 선의 색과 두께를 동시에 지정하기
void View::setPen(COLORREF color, int width)
{
	thePen = CreatePen(PS_SOLID, width, color);
	SelectObject(m_DCHandle, thePen);
}

// 채움 색을 결정하는 함수.
void View::setFillColor(COLORREF color)
{
	theBrush = CreateSolidBrush(color);
	SelectObject(m_DCHandle, theBrush);
}

// 글자 색을 지정하는 함수.
void View::setTextColor(COLORREF color)
{
	SetTextColor(m_DCHandle, color);
}
// 글자 배경색을 지정하는 함수.
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

// 모든  내용물들을 다시 그려주는 함수.  수정이 필요할 것이다.
void View::redrawAll()
{
	/*
	for (auto b : m_btnList) {
		b->draw();
	 }
	 */
	//View에서는 툴바만 그림
	if (toolbar) {
		toolbar->draw();
	}
}

// 화면이 현재 제대로 안되어 있다고 알리는 함수입니다.
// 이 함수를 호출하면 화면이 지워지고 
// Main.cpp 쪽에 case WM_PAINT: 부분이 실행됩니다.
// 결국은 View 객체의 display가 실행되겠죠.
void View::invalidate()
{
	InvalidateRect(m_WindowHandle, NULL, true);
}

// 모든 윈도들을 onInitialize 함수에서 초기화하자.
void View::onInitialize()
{
	// *** 모든 컴포넌트들을 여기에서 초기화하자.
	toolbar = new Toolbar(this);	//VIew 객체를 보내 초기화
	//toolbar->addButton(new TButton("R"));
	//toolbar->addButton(new TButton("E"));
	//toolbar->addButton(new TButton("L"));
	debugOutput("OK");
	
	/*
	btnRect = new MyButton(10, 10, 200, 50, "사각형");
	btnEllipse = new MyButton(220, 10, 200, 50, "타원");
	btnLine = new MyButton(430, 10, 200, 50, "선분");
	addButton(btnRect);
	addButton(btnEllipse);
	addButton(btnLine);
	*/

	invalidate();
}

// 사각형 위치를 지운다.
void View::eraseRect(int x, int y, int   sizeX, int  sizeY) // 좌상귀 x y 그리고 x축 y축 크기
{
	// TODO: 여기에 구현 코드 추가.
	setPenColor(RGB(255, 255, 255));
	setFillColor(RGB(255, 255, 255));
	drawRectangle(x, y, sizeX, sizeY);
}

// 윈도의 위치를 돌려준다.
RECT View::getClientRect()   // RECT에는 left, right, top, bottom 멤버 변수가 있다.
{
	// TODO: 여기에 구현 코드 추가.
	RECT r;
	GetClientRect(m_WindowHandle, &r);
	return r;
}


// 현재 폰트에서 text를 출력했을 때, 화면상에 차지하는 크기를 돌려주는 함수
SIZE View::textSize(const std::string text)
{
	// TODO: 여기에 구현 코드 추가.
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
	// TODO: 여기에 구현 코드 추가.
	for (auto b : m_btnList) {
		if (b->inside(x, y)) return b;
	}
	return nullptr;
}
*/


void View::OnMouseMove(MyEvent e)
{
	toolbar->onMouseMove(e.x, e.y);
	// TODO: 여기에 구현 코드 추가.
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