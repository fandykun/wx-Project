#pragma once
#include "deklarasi.h"

class Cloud
{
public:
	Cloud();
	~Cloud();
	void Draw(wxPaintDC &pdc);
	void Move();
	int getPOSISI_X();
	int getPOSISI_Y();
	int getCloudWidth();
	int getCloudHeight();
private:
private:
	wxBitmap *Cloud_bitmap = nullptr;
	int POSISI_X = CLOUD_X;
	int POSISI_Y = CLOUD_Y;
};

