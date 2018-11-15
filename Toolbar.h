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
	int m_xBar;	//x���� ����
	int m_yBar;	//y���� ����
	
	list<TButton*> m_btn;	//TButton��ü
	TButton* RECT;		//Rect���ּ�
	TButton* ELLIPSE;	//ELLIPSE���ּ�
	TButton* LINE;		//LINE���ּ�

	TButton *lastBtn;
	int count;
public:
	View* m_view;	//VIew ��ü
	Toolbar(View*);
	void draw();	//��ư�� �ٸ� �׸�
	void addButton(TButton *);	//T��ư �߰�
	View* getView();
	bool findToolbar(int x,int y);	//���� ��
	TButton* findButton(int x, int y);	//��ưã��
	void onMouseMove(int x,int y);	//��ư �̵�
	int selectBtn(int x,int y);	//��ư ����
	~Toolbar();
};

