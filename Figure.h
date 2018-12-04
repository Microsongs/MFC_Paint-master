#pragma once
class View;
class Figure
{
protected:
	int m_pen;	//���� ��
	int m_fill;	//ä�� ��
public:
	static const int RECT = 1, ELLIPSE = 2, LINE = 3;
	static const int redLINE = 4, greenLINE = 5, blueLINE = 6;
	static const int redPAINT = 7, greenPAINT = 8, bluePAINT = 9;
	Figure(int x, int y, int x2, int y2, int pen,int fill);
	Figure(int x, int y, int x2, int y2, int pen);
	~Figure();
	void setView(View *);
	//void setPenColor(int color);	//���� �� ����
	//void setFillColor(int color);	//ä�� �� ����
	virtual void draw() = 0;
	int m_x1, m_y1, m_x2, m_y2;
	View *m_view = 0;
};


