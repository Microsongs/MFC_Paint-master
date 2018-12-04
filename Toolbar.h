#pragma once

#include "View.h"
#include "TButton.h"
#include <list>
#include "Misc.h"
//#include "Component.h"
#include "Container.h"
#include "actionListener.h"

using namespace std;

class View;
class TButton;

class Toolbar : public Container
{
private:
	//int m_xBar;	//x���� ����
	//int m_yBar;	//y���� ����
	
	//list<Component*> m_btn;	//TButton��ü
	Component* RECT;		//Rect���ּ�
	Component* ELLIPSE;	//ELLIPSE���ּ�
	Component* LINE;		//LINE���ּ�

	Component *lastBtn;	//T��ư

	//�����ʸ���Ʈ
	
public:
	//View* m_view;	//VIew ��ü
	Toolbar(View*);
	void draw();	//���ٸ��� �׸�
	View* getView();
	void addComponent(Component *);	//T��ư �߰�, Override
	bool findToolbar(int x,int y);	//���� ��
	void onMouseMove(MyEvent e);	//��ư �̵�
	int selectBtn(int x,int y);	//��ư ����
	//TButton* find(int x, int y);	//��ưã��
	Component* find(int x, int y);
	//void clicked();

	~Toolbar();
};

