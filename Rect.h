#pragma once
#include "Figure.h"
class Rect :
	public Figure
{
public:
	Rect(int group, int type,int x1, int y1, int x2, int y2,int pen,int fill);
	~Rect();
	void draw();
};

