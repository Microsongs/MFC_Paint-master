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
	
	//���� ����
	figurePen = RGB(0, 0, 0);
	figureFill = RGB(255, 255, 255);	//�ʱ�ȭ
	
}

void myView::OnLButtonDown(MyEvent e)
{
	View::OnLButtonDown(e);
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
	txtList.push_back(new saveFigure(drawmode, m_startx, m_starty, e.x, e.y, figurePen, figureFill));

	if (drawmode == Figure::LINE) { // ����
		addFigure(new CLine(m_startx, m_starty, e.x, e.y, figurePen));
		txtList.push_back(new saveFigure(drawmode, m_startx, m_starty, e.x, e.y, figurePen));
	}
	else if (drawmode == Figure::ELLIPSE) {  // Ÿ��
		addFigure(new CEllipse(m_startx, m_starty, e.x, e.y, figurePen, figureFill));
		txtList.push_back(new saveFigure(drawmode, m_startx, m_starty, e.x, e.y, figurePen, figureFill));
	}
	else if (drawmode == Figure::RECT) {  // �簢��
		addFigure(new Rect(m_startx, m_starty, e.x, e.y, figurePen, figureFill));
		txtList.push_back(new saveFigure(drawmode, m_startx, m_starty, e.x, e.y, figurePen, figureFill));
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
			m_rectList.clear();
			txtList.clear();
			int fig[7];
			int inputData;
			char data[100];
			while (!open_File.eof()) {	//������ ��� �о�´�.
				for (int i = 0; i < 7; i++) {	//���� ������ 7���̹Ƿ� 7���� �޾ƿ�
					open_File.getline(data, 100);
					fig[i] = atoi(data);
				}
				//fig[0] = drawmode fig[1] = start_x fig[2] = start_y
				//fig[3] = end_x fig[4] = end_y fig[5] = penColor fig[6] = fillColor
				Figure *p = nullptr;
				if (fig[0] == Figure::LINE) {
					p = new CLine(fig[1], fig[2], fig[3], fig[4], fig[5]);
					p->setView(this);
					m_rectList.push_back(p);
					txtList.push_back(new saveFigure(fig[0], fig[1], fig[2], fig[3], fig[4], fig[5], fig[6]));
				}
				else if (fig[0] == Figure::ELLIPSE) {
					p = new CEllipse(fig[1], fig[2], fig[3], fig[4], fig[5], fig[6]);
					p->setView(this);
					m_rectList.push_back(p);
					txtList.push_back(new saveFigure(fig[0], fig[1], fig[2], fig[3], fig[4], fig[5], fig[6]));
				}
				else if (fig[0] == Figure::RECT) {
					p = new Rect(fig[1], fig[2], fig[3], fig[4], fig[5], fig[6]);
					p->setView(this);
					m_rectList.push_back(p);
					txtList.push_back(new saveFigure(fig[0], fig[1], fig[2], fig[3], fig[4], fig[5], fig[6]));
				}
				//txtList.push_back(new saveFigure(fig[0], fig[1], fig[2], fig[3], fig[4], fig[5], fig[6]));
			}
			invalidate();	//�ٽ� ���ϼ��ֵ���
		}

	}
	else if (e->getTitle() == "����") {
		//debugOutput("����\n");
		ofstream save_File("Figure.txt");	//txt���� ����
		for (auto i : txtList) {
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

		save_File.close();
	}
}

void myView::OnLButtonUp(MyEvent e) {
	View::OnLButtonUp(e);

	if (changeInfo == true) {	//VIew�� onLButton���� ����� ������ ������ ��������
		changeInfo = false;
		return;
	}

	createFigure(e);	//��������
	
	currentBtn = 0;
	currentItem = 0;
	invalidate();
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
		View::draw();
	}
}


void myView::addFigure(Figure *r) {
	//m_list.push_back(r);
	m_rectList.push_back(r);
	r->setView(this);
}

myView::~myView()
{
}
