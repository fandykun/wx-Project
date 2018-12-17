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

//void Obstacle::LoadObstacle()
//{
//	wxStandardPaths &stdPath = wxStandardPaths::Get();
//	wxString filelocation = stdPath.GetExecutablePath();
//	filelocation = wxFileName(filelocation).GetPath() + wxT("\\cactusBig0000.png");
//	wxImage Obstacle_Image(filelocation, wxBITMAP_TYPE_PNG);
//	Obstacle_bitmap = new wxBitmap(Obstacle_Image);
//}

void Obstacle::Move()
{
	wxStandardPaths &stdPath = wxStandardPaths::Get();
	wxString filelocation = stdPath.GetExecutablePath();

	if(POSISI_X > 0) POSISI_X -= 10;
	else {
		POSISI_X = OBSTACLE_X;
		ChooseObstacle = rand() % 3;
		//ChooseObstacle = KAKTUS_BESAR;
	}

	switch (ChooseObstacle) {
		case KAKTUS_BESAR: {
			filelocation = wxFileName(filelocation).GetPath() + wxT("\\cactusBig0000.png");
			wxImage Obstacle_Image(filelocation, wxBITMAP_TYPE_PNG);
			Obstacle_bitmap = new wxBitmap(Obstacle_Image);
			//ChooseObstacle = rand() % 3;
			POSISI_Y = OBSTACLE_Y;
		}break;
		case KAKTUS_KECIL: {
			filelocation = wxFileName(filelocation).GetPath() + wxT("\\cactusSmall0000.png");
			wxImage Obstacle_Image(filelocation, wxBITMAP_TYPE_PNG);
			Obstacle_bitmap = new wxBitmap(Obstacle_Image);
			//ChooseObstacle = rand() % 3;
			POSISI_Y = OBSTACLE_Y + 40;
		}break;
		case KAKTUS_BANYAK: {
			filelocation = wxFileName(filelocation).GetPath() + wxT("\\cactusSmallMany0000.png");
			wxImage Obstacle_Image(filelocation, wxBITMAP_TYPE_PNG);
			Obstacle_bitmap = new wxBitmap(Obstacle_Image);
			POSISI_Y = OBSTACLE_Y + 40;
			//ChooseObstacle = rand() % 3;
		}break;
	}
	wxMessageOutputDebug().Printf("Ukuran gambar: %d | %d", Obstacle_bitmap->GetHeight(), Obstacle_bitmap->GetWidth());
}

void Obstacle::addObstacle()
{

}
