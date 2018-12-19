#include "Obstacle.h"

Obstacle::Obstacle()
{
	wxImageHandler *PNGLoader = new wxPNGHandler;
	wxImage::AddHandler(PNGLoader);
}


Obstacle::~Obstacle()
{
}

void Obstacle::Draw(wxPaintDC & pdc)
{
	if (Obstacle_bitmap != nullptr)
		pdc.DrawBitmap(*Obstacle_bitmap, wxPoint(POSISI_X, POSISI_Y), true);
}

void Obstacle::Move()
{
	wxStandardPaths &stdPath = wxStandardPaths::Get();
	wxString filelocation = stdPath.GetExecutablePath();

	if(POSISI_X > -130) POSISI_X -= 20;
	else {
		POSISI_X = OBSTACLE_X;
		ChooseObstacle = rand() % 3;
		//ChooseObstacle = KAKTUS_BESAR;
	}

	switch (ChooseObstacle) {
		case KAKTUS_BESAR: {
			filelocation = wxFileName(filelocation).GetPath() + wxT("\\cactusBig0000.png");
			POSISI_Y = OBSTACLE_Y;
		}break;
		case KAKTUS_KECIL: {
			filelocation = wxFileName(filelocation).GetPath() + wxT("\\cactusSmall0000.png");
			POSISI_Y = OBSTACLE_Y + 40;
		}break;
		case KAKTUS_BANYAK: {
			filelocation = wxFileName(filelocation).GetPath() + wxT("\\cactusSmallMany0000.png");
			POSISI_Y = OBSTACLE_Y + 40;
		}break;
	}

	wxImage Obstacle_Image(filelocation, wxBITMAP_TYPE_PNG);
	Obstacle_bitmap = new wxBitmap(Obstacle_Image);
	wxMessageOutputDebug().Printf("Ukuran gambar: %d | %d", Obstacle_bitmap->GetHeight(), Obstacle_bitmap->GetWidth());
}

int Obstacle::getPOSISI_X()
{
	return POSISI_X;
}

int Obstacle::getPOSISI_Y()
{
	return POSISI_Y;
}

int Obstacle::getDinoWidth()
{
	return Obstacle_bitmap->GetWidth();
}

int Obstacle::getDinoHeight()
{
	return Obstacle_bitmap->GetHeight();
}
