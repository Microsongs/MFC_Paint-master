#pragma once
class saveFigure
{
protected:
	int type;	//Ÿ��
	int start_x;	//���� x��ǥ
	int start_y;	//���� y��ǥ
	int end_x;		//�� x��ǥ
	int end_y;		//�� y��ǥ
	int penColor;	//�� ��
	int fillColor;	//ä���

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

