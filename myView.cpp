#include "stdafx.h"
#include "myView.h"
#include "View.h"
#include "Figure.h"
#include "CLine.h"
#include "Ellipse.h"
#include "Rect.h"
#include "Component.h"
#include <fstream>	//file i/o
#include <Windows.h>

myView::myView(HINSTANCE hInstance) : View(hInstance)
{
	//constructor
}

void myView::onInitialize() {
	View::onInitialize();
	TButton *rectButton = new TButton("R");
	HICON rectIcon;	//사각형 아이콘
	rectIcon = (HICON)LoadImage(this->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON1),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	rectButton->setIcon(rectIcon);
	rectButton->addActionListener(new tButtonActionListener(this));

	TButton *ellipseButton = new TButton("E");
	HICON ellipseIcon;	//사각형 아이콘
	ellipseIcon = (HICON)LoadImage(this->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON2),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	ellipseButton->setIcon(ellipseIcon);
	ellipseButton->addActionListener(new tButtonActionListener(this));

	TButton *lineButton = new TButton("L");
	HICON lineIcon;	//사각형 아이콘
	lineIcon = (HICON)LoadImage(this->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON3),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	lineButton->setIcon(lineIcon);
	lineButton->addActionListener(new tButtonActionListener(this));

	toolbar->addComponent(rectButton);
	toolbar->addComponent(ellipseButton);
	toolbar->addComponent(lineButton);

	TButton *rLine = new TButton("RL");
	HICON rLIcon;	//붉은선 아이콘
	rLIcon = (HICON)LoadImage(this->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON4),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	rLine->setIcon(rLIcon);
	rLine->addActionListener(new tButtonActionListener(this));

	TButton *gLine = new TButton("GL");
	HICON gLIcon;	//Green선 아이콘
	gLIcon = (HICON)LoadImage(this->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON5),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	gLine->setIcon(gLIcon);
	gLine->addActionListener(new tButtonActionListener(this));

	TButton *bLine = new TButton("BL");
	HICON bLIcon;	//Blue선 아이콘
	bLIcon = (HICON)LoadImage(this->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON6),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	bLine->setIcon(bLIcon);
	bLine->addActionListener(new tButtonActionListener(this));

	toolbar->addComponent(rLine);
	toolbar->addComponent(gLine);
	toolbar->addComponent(bLine);

	TButton *rPaint = new TButton("RP");
	HICON rPIcon;	//붉은선 아이콘
	rPIcon = (HICON)LoadImage(this->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON7),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	rPaint->setIcon(rPIcon);
	rPaint->addActionListener(new tButtonActionListener(this));

	TButton *gPaint = new TButton("GP");
	HICON gPIcon;	//붉은선 아이콘
	gPIcon = (HICON)LoadImage(this->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON8),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	gPaint->setIcon(gPIcon);
	gPaint->addActionListener(new tButtonActionListener(this));

	TButton *bPaint = new TButton("BP");
	HICON bPIcon;	//붉은선 아이콘
	bPIcon = (HICON)LoadImage(this->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON9),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	bPaint->setIcon(bPIcon);
	bPaint->addActionListener(new tButtonActionListener(this));

	toolbar->addComponent(rPaint);
	toolbar->addComponent(gPaint);
	toolbar->addComponent(bPaint);

	Menu* menu;
	MenuItem* item;
	//응용

	menu = new Menu("파일", this);	//파일 메뉴 생성
	//File_menu = menu;
	item = new MenuItem("저장");
	//item->addActionListener(new menuItemActionListener(this));
	item->addActionListener(this);
	menu->addComponent(item);

	item = new MenuItem("열기");
	item->addActionListener(this);
	//item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	menubar->addComponent(menu);

	menu = new Menu("도형", this);	//파일 메뉴 생성
	//Fig_menu = menu;
	item = new MenuItem("사각형");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	item = new MenuItem("타원");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	item = new MenuItem("선분");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	menubar->addComponent(menu);
	
	menu = new Menu("선색", this);
	item = new MenuItem("붉은선");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	item = new MenuItem("녹색선");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	item = new MenuItem("파란선");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	menubar->addComponent(menu);

	menu = new Menu("채움색", this);
	item = new MenuItem("붉은색");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	item = new MenuItem("녹색");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	item = new MenuItem("파란색");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	menubar->addComponent(menu);

	menu = new Menu("기능", this);
	item = new MenuItem("이동");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	item = new MenuItem("복사");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	item = new MenuItem("그룹");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	menubar->addComponent(menu);
	
	//색상값 설정
	figurePen = RGB(0, 0, 0);
	figureFill = RGB(255, 255, 255);	//초기화
	
}

void myView::OnLButtonDown(long wParam, MyEvent e)
{
	tempFig = 0;
	if (drawmode != GROUP && frontmode == GROUP) {	//그룹 모드에서 다른 것을 바꾸었을때
		groupNum++;
		frontmode = 0;
	}

	if (drawmode == COPY || drawmode == MOVE || drawmode == GROUP) {
		m_startx = e.x;
		m_starty = e.y;
		for (vector<Figure*>::reverse_iterator i = m_rectList.rbegin(); i != m_rectList.rend(); i++) {
			tempFig = (*i)->inside(e.x, e.y);
			if (tempFig) {
				break;
			}
		}
		if (!tempFig) {
			for (int i = groupNum; i >= 0; i--) {
				int k = 0;
				for (auto j : m_groupList[i]) {
					tempFig = j->inside(e.x, e.y);
					if (tempFig) {
						tempGroup = m_groupList;
						tempGroupNum = i;
						return;
					}
					k++;
				}
			}
		}
	}

	if (!tempFig) {
		View::OnLButtonDown(wParam, e);
	}
}

void myView::OnLButtonUp(long wParam, MyEvent e) {
	if (tempGroup) {
		if (drawmode == MOVE && !toolbar->findToolbar(e.x, e.y) && !menubar->findMenubar(e.x, e.y)) {
			for (auto i : tempGroup[tempGroupNum]) {
				i->setStartX(i->getStartX() + (e.x - m_startx));
				i->setStartY(i->getStartY() + (e.y - m_starty));
				i->setEndX(i->getEndX() + (e.x - m_startx));
				i->setEndY(i->getEndY() + (e.y - m_starty));
			}
			invalidate();
			tempGroup = 0;
			tempFig = 0;
			return;
		}
		else if (drawmode == COPY && !toolbar->findToolbar(e.x, e.y) && !menubar->findMenubar(e.x, e.y)) {
			groupNum++;
			for (auto i : tempGroup[tempGroupNum]) {
				if (i->getType() == Figure::LINE) {
					addGroup(new CLine(groupNum, i->getType(),
						i->getStartX() + (e.x - m_startx), i->getStartY() + (e.y - m_starty),
						i->getEndX() + (e.x - m_startx), i->getEndY() + (e.y - m_starty),
						i->getPen()));
				}
				else if (i->getType() == Figure::ELLIPSE) {
					addGroup(new CEllipse(groupNum, i->getType(),
						i->getStartX() + (e.x - m_startx), i->getStartY() + (e.y - m_starty),
						i->getEndX() + (e.x - m_startx), i->getEndY() + (e.y - m_starty),
						i->getPen(), i->getFill()));
				}
				else if (i->getType() == Figure::RECT) {
					addGroup(new Rect(groupNum, i->getType(),
						i->getStartX() + (e.x - m_startx), i->getStartY() + (e.y - m_starty),
						i->getEndX() + (e.x - m_startx), i->getEndY() + (e.y - m_starty),
						i->getPen(), i->getFill()));
				}
			}
			tempFig = 0;
			tempGroup = 0;
			invalidate();
			return;
		}
	}
	
	if (tempFig) {
		if (drawmode == MOVE && !toolbar->findToolbar(e.x,e.y) && !menubar->findMenubar(e.x,e.y)) {
			tempFig->setStartX(tempFig->getStartX() + (e.x - m_startx));
			tempFig->setStartY(tempFig->getStartY() + (e.y - m_starty));
			tempFig->setEndX(tempFig->getEndX() + (e.x - m_startx));
			tempFig->setEndY(tempFig->getEndY() + (e.y - m_starty));
			tempFig = 0;
			invalidate();
			return;
		}
		else if (drawmode == COPY && !toolbar->findToolbar(e.x, e.y) && !menubar->findMenubar(e.x, e.y)) {
			if (tempFig->getType() == Figure::LINE) {
				addFigure(new CLine(-1, tempFig->getType(),
					tempFig->getStartX() + (e.x - m_startx), tempFig->getStartY() + (e.y - m_starty),
					tempFig->getEndX() + (e.x - m_startx), tempFig->getEndY() + (e.y - m_starty),
					tempFig->getPen()));
			}
			else if (tempFig->getType() == Figure::ELLIPSE) {
				addFigure(new CEllipse(-1, tempFig->getType(),
					tempFig->getStartX() + (e.x - m_startx), tempFig->getStartY() + (e.y - m_starty),
					tempFig->getEndX() + (e.x - m_startx), tempFig->getEndY() + (e.y - m_starty),
					tempFig->getPen(), tempFig->getFill()));
			}
			else if (tempFig->getType() == Figure::RECT) {
				addFigure(new Rect(-1, tempFig->getType(),
					tempFig->getStartX() + (e.x - m_startx), tempFig->getStartY() + (e.y - m_starty),
					tempFig->getEndX() + (e.x - m_startx), tempFig->getEndY() + (e.y - m_starty),
					tempFig->getPen(), tempFig->getFill()));
			}
			tempFig = 0;
			invalidate();
			return;
		}
		else if (drawmode == GROUP) {
			m_groupList[groupNum].push_back(tempFig);
			tempFig->setGroup(groupNum);
			int j = 0;
			for (vector<Figure*>::iterator i = m_rectList.begin(); i != m_rectList.end(); i++) {
				//중복 요소 제거
				if (tempFig == m_rectList[j]) {
					m_rectList.erase(m_rectList.begin() + j);
					break;
				}
				j++;
			}
			frontmode = GROUP;
		}
	}
	tempFig = 0;

	View::OnLButtonUp(wParam,e);

	if (changeInfo == true) {	//VIew의 onLButton에서 변경된 정보가 있으면 강제종료
		changeInfo = false;
		return;
	}

	createFigure(e);	//도형생성
	currentBtn = 0;
	currentItem = 0;
	invalidate();
}

void myView::setDrawMode(int drawmode)
{
	this->drawmode = drawmode;
}

void myView::setFigure(int figure)
{
	drawmode = figure;
}

void myView::setPenColor(int pen)
{
	figurePen = pen;
}

void myView::setFillColor(int fill)
{
	figureFill = fill;
}

void myView::createFigure(MyEvent e)
{
	if (drawmode == Figure::LINE) { // 선분
		addFigure(new CLine(-1, drawmode, m_startx, m_starty, e.x, e.y, figurePen));
	}
	else if (drawmode == Figure::ELLIPSE) {  // 타원
		addFigure(new CEllipse(-1, drawmode, m_startx, m_starty, e.x, e.y, figurePen, figureFill));
	}
	else if (drawmode == Figure::RECT) {  // 사각형
		addFigure(new Rect(-1, drawmode, m_startx, m_starty, e.x, e.y, figurePen, figureFill));
	}
}


void myView::actionPerformed(Component* e)
{
	if (e->getTitle() == "열기") {
		debugOutput("열기\n");
		ifstream open_File("Figure.txt");
		if (!open_File) {
			//메세지 박스 띄우는 법을 몰라 debugOutput 출력
			debugOutput("저장된 파일이 없습니다.\n");
		}
		else {
			m_rectList.clear();	//리스트를 클리어
			m_groupList->clear();	//리스트 클리어
			int fig[8];
			char data[100];
			while (!open_File.eof()) {	//파일을 열어서 읽어온다.
				for (int i = 0; i < 8; i++) {	//0그룹 1타입 2 x1 3 y1 4 x2 5 y2 6 pen 7 fill
					open_File.getline(data, 100);
					fig[i] = atoi(data);
				}
				Figure *p = nullptr;
				if (fig[0] == -1) {	//그룹이 아닐경우
					if (fig[1] == Figure::LINE) {
						p = new CLine(fig[0], fig[1], fig[2], fig[3], fig[4], fig[5], fig[6]);
						p->setView(this);
						m_rectList.push_back(p);
					}
					else if (fig[1] == Figure::ELLIPSE) {
						p = new CEllipse(fig[0], fig[1], fig[2], fig[3], fig[4], fig[5], fig[6], fig[7]);
						p->setView(this);
						m_rectList.push_back(p);
					}
					else if (fig[1] == Figure::RECT) {
						p = new Rect(fig[0], fig[1], fig[2], fig[3], fig[4], fig[5], fig[6], fig[7]);
						p->setView(this);
						m_rectList.push_back(p);
					}
				}
				else {	//그룹일경우
					if (groupNum <= fig[0])	//미리 생성
						groupNum = fig[0] + 1;
					debugOutput(groupNum);
					if (fig[1] == Figure::LINE) {
						p = new CLine(fig[0], fig[1], fig[2], fig[3], fig[4], fig[5], fig[6]);
						p->setView(this);
						m_groupList[fig[0]].push_back(p);
					}
					else if (fig[1] == Figure::ELLIPSE) {
						p = new CEllipse(fig[0], fig[1], fig[2], fig[3], fig[4], fig[5], fig[6], fig[7]);
						p->setView(this);
						m_groupList[fig[0]].push_back(p);
					}
					else if (fig[1] == Figure::RECT) {
						p = new Rect(fig[0], fig[1], fig[2], fig[3], fig[4], fig[5], fig[6], fig[7]);
						p->setView(this);
						m_groupList[fig[0]].push_back(p);
					}
				}
			}
			invalidate();	//다시 보일수있도록
		}

	}
	else if (e->getTitle() == "저장") {
		//debugOutput("저장\n");
		ofstream save_File("Figure.txt");	//txt파일 생성
		for (auto i : m_rectList) {
			save_File << i->getGroup();
			save_File << "\n";
			save_File << i->getType();
			save_File << "\n";
			save_File << i->getStartX();
			save_File << "\n";
			save_File << i->getStartY();
			save_File << "\n";
			save_File << i->getEndX();
			save_File << "\n";
			save_File << i->getEndY();
			save_File << "\n";
			save_File << i->getPen();
			save_File << "\n";
			save_File << i->getFill();
			save_File << "\n";
		}
		for (int i = 0; i <= groupNum; i++) {
			for (auto j : m_groupList[i]) {
				save_File << j->getGroup();
				save_File << "\n";
				save_File << j->getType();
				save_File << "\n";
				save_File << j->getStartX();
				save_File << "\n";
				save_File << j->getStartY();
				save_File << "\n";
				save_File << j->getEndX();
				save_File << "\n";
				save_File << j->getEndY();
				save_File << "\n";
				save_File << j->getPen();
				save_File << "\n";
				save_File << j->getFill();
				save_File << "\n";
			}
		}

		save_File.close();
	}
}



// 모든  내용물들을 다시 그려주는 함수.  수정이 필요할 것이다.
void myView::draw()
{
	if (toolbar) {
		//toolbar->draw();
		//toolbar->buttonDraw();
		//툴바 그린 이후 다시 원색으로 변경
		//setFillColor(RGB(255, 255, 255));
		setTextBkColor(RGB(255, 255, 255));
		//for (auto r : m_list) {
		for(auto r : m_rectList){
		r->draw();
		}
		for (int i = 0; i <= groupNum;i++) {
			for (auto r : m_groupList[i]) {
				r->draw();
			}
		}
		View::draw();
	}
}

void myView::addGroup(Figure *r) {
	m_groupList[groupNum].push_back(r);
	r->setView(this);
}

void myView::addFigure(Figure *r) {
	//m_list.push_back(r);
	m_rectList.push_back(r);
	r->setView(this);
}

myView::~myView()
{
}
