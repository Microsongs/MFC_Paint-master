#include "stdafx.h"
#include "saveFigure.h"


saveFigure::saveFigure(int type, int stx, int sty, int endx, int endy, int pen, int fill)
{
	this->type = type;
	this->start_x = stx;
	this->start_y = sty;
	this->end_x = endx;
	this->end_y = endy;
	this->penColor = pen;
	this->fillColor = fill;
}

int saveFigure::getType()
{
	return type;
}

int saveFigure::getStartX()
{
	return start_x;
}

int saveFigure::getStartY()
{
	return start_y;
}

int saveFigure::getEndX()
{
	return end_x;
}

int saveFigure::getEndY()
{
	return end_y;
}

int saveFigure::getPen()
{
	return penColor;
}

int saveFigure::getFill()
{
	return fillColor;
}

saveFigure::~saveFigure()
{
}
