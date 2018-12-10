#pragma once
class View;
class Figure
{
protected:
	int m_group;	//�׷� ���� ����
	int m_type;	//Ÿ�� ����
	int m_pen;	//���� ��
	int m_fill;	//ä�� ��
public:
	static const int RECT = 1, ELLIPSE = 2, LINE = 3;
	static const int redLINE = 4, greenLINE = 5, blueLINE = 6;
	static const int redPAINT = 7, greenPAINT = 8, bluePAINT = 9;
	Figure(int group,int type, int x, int y, int x2, int y2, int pen,int fill = 0);
	//Figure(int type, int x, int y, int x2, int y2, int pen);
	~Figure();
	void setView(View *);
	//void setPenColor(int color);	//���� �� ����
	//void setFillColor(int color);	//ä�� �� ����
	virtual void draw() = 0;
	int m_x1, m_y1, m_x2, m_y2;
	View *m_view = 0;
	Figure* inside(int x, int y);

	void setGroup(int g);
	void setStartX(int x1);
	void setStartY(int y1);
	void setEndX(int x2);
	void setEndY(int y2);

	//����
	int getGroup();
	int getType();
	int getStartX();
	int getStartY();
	int getEndX();
	int getEndY();
	int getPen();
	int getFill();
};


