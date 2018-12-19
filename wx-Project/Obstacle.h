#pragma once
#include "deklarasi.h"

class Obstacle
{
public:
	Obstacle();
	~Obstacle();
	void Draw(wxPaintDC &pdc);
	void Move();
	int ChooseObstacle = rand() % 3;
	int getPOSISI_X();
	int getPOSISI_Y();
	int getDinoWidth();
	int getDinoHeight();
private:
	wxBitmap *Obstacle_bitmap = nullptr;
	//void LoadObstacle();
	int POSISI_X = OBSTACLE_X;
	int POSISI_Y = OBSTACLE_Y;
};