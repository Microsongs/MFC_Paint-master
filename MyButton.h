#pragma once
#include "string"
class View;
class MyButton
{
public:
	MyButton(int x, int y, int sizex, int siezy, std::string title);
	MyButton(std::string title);
	~MyButton();
protected:
	std::string m_title;
	int m_x, m_y, m_sizex, m_sizey;
	View *m_view = 0;
	COLORREF m_normal_bg_color = RGB(230,230,230);
	COLORREF m_temp_bg_color = RGB(200,200,200);
	COLORREF m_line_color = RGB(0, 0, 0);
public:
	void draw();
	void tempDraw();
	bool inside(int x, int y);
	//void action();
	void setView(View *);
};
