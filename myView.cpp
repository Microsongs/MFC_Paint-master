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
	HICON rectIcon;	//�簢�� ������
	rectIcon = (HICON)LoadImage(this->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON1),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	rectButton->setIcon(rectIcon);
	rectButton->addActionListener(new tButtonActionListener(this));

	TButton *ellipseButton = new TButton("E");
	HICON ellipseIcon;	//�簢�� ������
	ellipseIcon = (HICON)LoadImage(this->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON2),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	ellipseButton->setIcon(ellipseIcon);
	ellipseButton->addActionListener(new tButtonActionListener(this));

	TButton *lineButton = new TButton("L");
	HICON lineIcon;	//�簢�� ������
	lineIcon = (HICON)LoadImage(this->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON3),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	lineButton->setIcon(lineIcon);
	lineButton->addActionListener(new tButtonActionListener(this));

	toolbar->addComponent(rectButton);
	toolbar->addComponent(ellipseButton);
	toolbar->addComponent(lineButton);

	TButton *rLine = new TButton("RL");
	HICON rLIcon;	//������ ������
	rLIcon = (HICON)LoadImage(this->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON4),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	rLine->setIcon(rLIcon);
	rLine->addActionListener(new tButtonActionListener(this));

	TButton *gLine = new TButton("GL");
	HICON gLIcon;	//Green�� ������
	gLIcon = (HICON)LoadImage(this->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON5),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	gLine->setIcon(gLIcon);
	gLine->addActionListener(new tButtonActionListener(this));

	TButton *bLine = new TButton("BL");
	HICON bLIcon;	//Blue�� ������
	bLIcon = (HICON)LoadImage(this->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON6),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	bLine->setIcon(bLIcon);
	bLine->addActionListener(new tButtonActionListener(this));

	toolbar->addComponent(rLine);
	toolbar->addComponent(gLine);
	toolbar->addComponent(bLine);

	TButton *rPaint = new TButton("RP");
	HICON rPIcon;	//������ ������
	rPIcon = (HICON)LoadImage(this->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON7),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	rPaint->setIcon(rPIcon);
	rPaint->addActionListener(new tButtonActionListener(this));

	TButton *gPaint = new TButton("GP");
	HICON gPIcon;	//������ ������
	gPIcon = (HICON)LoadImage(this->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON8),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	gPaint->setIcon(gPIcon);
	gPaint->addActionListener(new tButtonActionListener(this));

	TButton *bPaint = new TButton("BP");
	HICON bPIcon;	//������ ������
	bPIcon = (HICON)LoadImage(this->m_InstanceHandle, MAKEINTRESOURCE(IDI_ICON9),
		IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
	bPaint->setIcon(bPIcon);
	bPaint->addActionListener(new tButtonActionListener(this));

	toolbar->addComponent(rPaint);
	toolbar->addComponent(gPaint);
	toolbar->addComponent(bPaint);

	Menu* menu;
	MenuItem* item;
	//����

	menu = new Menu("����", this);	//���� �޴� ����
	//File_menu = menu;
	item = new MenuItem("����");
	//item->addActionListener(new menuItemActionListener(this));
	item->addActionListener(this);
	menu->addComponent(item);

	item = new MenuItem("����");
	item->addActionListener(this);
	//item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	menubar->addComponent(menu);

	menu = new Menu("����", this);	//���� �޴� ����
	//Fig_menu = menu;
	item = new MenuItem("�簢��");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	item = new MenuItem("Ÿ��");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	item = new MenuItem("����");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	menubar->addComponent(menu);
	
	menu = new Menu("����", this);
	item = new MenuItem("������");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	item = new MenuItem("�����");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	item = new MenuItem("�Ķ���");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	menubar->addComponent(menu);

	menu = new Menu("ä���", this);
	item = new MenuItem("������");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	item = new MenuItem("���");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	item = new MenuItem("�Ķ���");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	menubar->addComponent(menu);

	menu = new Menu("���", this);
	item = new MenuItem("�̵�");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	item = new MenuItem("����");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	item = new MenuItem("�׷�");
	item->addActionListener(new menuItemActionListener(this));
	menu->addComponent(item);

	menubar->addComponent(menu);
	
	//���� ����
	figurePen = RGB(0, 0, 0);
	figureFill = RGB(255, 255, 255);	//�ʱ�ȭ
	
}

void myView::OnLButtonDown(long wParam, MyEvent e)
{
	tempFig = 0;
	if (drawmode != GROUP && frontmode == GROUP) {	//�׷� ��忡�� �ٸ� ���� �ٲپ�����
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
				//�ߺ� ��� ����
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

	if (changeInfo == true) {	//VIew�� onLButton���� ����� ������ ������ ��������
		changeInfo = false;
		return;
	}

	createFigure(e);	//��������
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
	if (drawmode == Figure::LINE) { // ����
		addFigure(new CLine(-1, drawmode, m_startx, m_starty, e.x, e.y, figurePen));
	}
	else if (drawmode == Figure::ELLIPSE) {  // Ÿ��
		addFigure(new CEllipse(-1, drawmode, m_startx, m_starty, e.x, e.y, figurePen, figureFill));
	}
	else if (drawmode == Figure::RECT) {  // �簢��
		addFigure(new Rect(-1, drawmode, m_startx, m_starty, e.x, e.y, figurePen, figureFill));
	}
}


void myView::actionPerformed(Component* e)
{
	if (e->getTitle() == "����") {
		debugOutput("����\n");
		ifstream open_File("Figure.txt");
		if (!open_File) {
			//�޼��� �ڽ� ���� ���� ���� debugOutput ���
			debugOutput("����� ������ �����ϴ�.\n");
		}
		else {
			m_rectList.clear();	//����Ʈ�� Ŭ����
			m_groupList->clear();	//����Ʈ Ŭ����
			int fig[8];
			char data[100];
			while (!open_File.eof()) {	//������ ��� �о�´�.
				for (int i = 0; i < 8; i++) {	//0�׷� 1Ÿ�� 2 x1 3 y1 4 x2 5 y2 6 pen 7 fill
					open_File.getline(data, 100);
					fig[i] = atoi(data);
				}
				Figure *p = nullptr;
				if (fig[0] == -1) {	//�׷��� �ƴҰ��
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
				else {	//�׷��ϰ��
					if (groupNum <= fig[0])	//�̸� ����
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
			invalidate();	//�ٽ� ���ϼ��ֵ���
		}

	}
	else if (e->getTitle() == "����") {
		//debugOutput("����\n");
		ofstream save_File("Figure.txt");	//txt���� ����
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



// ���  ���빰���� �ٽ� �׷��ִ� �Լ�.  ������ �ʿ��� ���̴�.
void myView::draw()
{
	if (toolbar) {
		//toolbar->draw();
		//toolbar->buttonDraw();
		//���� �׸� ���� �ٽ� �������� ����
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
