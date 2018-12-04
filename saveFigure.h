#pragma once
class saveFigure
{
protected:
	int type;	//Å¸ÀÔ
	int start_x;	//½ÃÀÛ xÁÂÇ¥
	int start_y;	//½ÃÀÛ yÁÂÇ¥
	int end_x;		//³¡ xÁÂÇ¥
	int end_y;		//³¡ yÁÂÇ¥
	int penColor;	//Ææ »ö
	int fillColor;	//Ã¤¿ò»ö

public:
	saveFigure(int type,int stx,int sty,int endx,int endy,int pen,int fill = 0);
	int getType();
	int getStartX();
	int getStartY();
	int getEndX();
	int getEndY();
	int getPen();
	int getFill();
	~saveFigure();
};

