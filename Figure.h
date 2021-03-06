#pragma once
class View;
class Figure
{
protected:
	int m_group;	//그룹 여부 저장
	int m_type;	//타입 저장
	int m_pen;	//선의 색
	int m_fill;	//채움 색
public:
	static const int RECT = 1, ELLIPSE = 2, LINE = 3;
	static const int redLINE = 4, greenLINE = 5, blueLINE = 6;
	static const int redPAINT = 7, greenPAINT = 8, bluePAINT = 9;
	Figure(int group,int type, int x, int y, int x2, int y2, int pen,int fill = 0);
	//Figure(int type, int x, int y, int x2, int y2, int pen);
	~Figure();
	void setView(View *);
	//void setPenColor(int color);	//선의 색 변경
	//void setFillColor(int color);	//채움 색 변경
	virtual void draw() = 0;
	int m_x1, m_y1, m_x2, m_y2;
	View *m_view = 0;
	Figure* inside(int x, int y);

	void setGroup(int g);
	void setStartX(int x1);
	void setStartY(int y1);
	void setEndX(int x2);
	void setEndY(int y2);

	//저장
	int getGroup();
	int getType();
	int getStartX();
	int getStartY();
	int getEndX();
	int getEndY();
	int getPen();
	int getFill();
};


