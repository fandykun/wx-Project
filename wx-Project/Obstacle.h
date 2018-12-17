#pragma once
#include "deklarasi.h"

class Obstacle
{
public:
	Obstacle();
	~Obstacle();
	void Draw(wxPaintDC &pdc);
	void Move();
	int ChooseObstacle = 0;
	void addObstacle();
private:
	wxBitmap *Obstacle_bitmap = nullptr;
	//void LoadObstacle();
	int POSISI_X = OBSTACLE_X;
	int AFTER_POSISI_X = OBSTACLE_X;
	int POSISI_Y = OBSTACLE_Y;
};