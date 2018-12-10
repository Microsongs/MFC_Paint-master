#pragma once
#include "Figure.h"
class CLine :
	public Figure
{
public:
	CLine(int group, int type,int x1, int y1, int x2, int y2,int pen,int fill = 0);
	~CLine();
	void draw();
};

