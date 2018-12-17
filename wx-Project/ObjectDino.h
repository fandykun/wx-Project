#pragma once
#include "deklarasi.h"

class ObjectDino
{
public:
	ObjectDino();
	~ObjectDino();
	void Draw(wxPaintDC &pdc);
	void Move();
	int pergerakan = 1;
private:
	wxBitmap *Dino_bitmap = nullptr;
	void LoadDino();
	int Delay_Lompat = 0;
	int POSISI_X = DINO_X;
	int POSISI_Y = DINO_Y;
};
