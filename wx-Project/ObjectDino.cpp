#include "ObjectDino.h"

ObjectDino::ObjectDino()
{
	wxImageHandler *PNGLoader = new wxPNGHandler;
	wxImage::AddHandler(PNGLoader);
	//this->LoadDino();
}

ObjectDino::~ObjectDino()
{
}

void ObjectDino::LoadDino()
{
	wxStandardPaths &stdPath = wxStandardPaths::Get();
	wxString filelocation = stdPath.GetExecutablePath();
	filelocation = wxFileName(filelocation).GetPath() + wxT("\\dinorun0000.png");
	wxImage dino_image(filelocation, wxBITMAP_TYPE_PNG);
	Dino_bitmap = new wxBitmap(dino_image);
}

void ObjectDino::Draw(wxPaintDC & pdc)
{
	if (Dino_bitmap != nullptr)
		pdc.DrawBitmap(*Dino_bitmap, wxPoint(POSISI_X, POSISI_Y), true);
}

void ObjectDino::Move()
{
	wxStandardPaths &stdPath = wxStandardPaths::Get();
	wxString filelocation = stdPath.GetExecutablePath();
	switch (pergerakan) {
		case JALAN_1: {
			filelocation = wxFileName(filelocation).GetPath() + wxT("\\dinorun0000.png");
			wxImage dino_image(filelocation, wxBITMAP_TYPE_PNG);
			Dino_bitmap = new wxBitmap(dino_image);
			pergerakan = JALAN_2;
			POSISI_Y = DINO_Y;
			Delay_Lompat = 0;
		}break;
		case JALAN_2: {
			filelocation = wxFileName(filelocation).GetPath() + wxT("\\dinorun0001.png");
			wxImage dino_image(filelocation, wxBITMAP_TYPE_PNG);
			Dino_bitmap = new wxBitmap(dino_image);
			pergerakan = JALAN_1;
		}break;
		case LOMPAT: {
			filelocation = wxFileName(filelocation).GetPath() + wxT("\\dinojump0000.png");
			wxImage dino_image(filelocation, wxBITMAP_TYPE_PNG);
			Dino_bitmap = new wxBitmap(dino_image);
			if (Delay_Lompat >= 60) Delay_Lompat = 60;
			else {
				POSISI_Y = DINO_Y - Delay_Lompat;
				Delay_Lompat += 20;
			}
		}break;
		case NUNDUK: {
			static bool NundukSwitch = false;
			if (NundukSwitch == false) {
				filelocation = wxFileName(filelocation).GetPath() + wxT("\\dinoduck0000.png");
				wxImage dino_image(filelocation, wxBITMAP_TYPE_PNG);
				Dino_bitmap = new wxBitmap(dino_image);
				POSISI_Y = DINO_Y + 40;
				NundukSwitch = true;
			}
			else {
				filelocation = wxFileName(filelocation).GetPath() + wxT("\\dinoduck0001.png");
				wxImage dino_image(filelocation, wxBITMAP_TYPE_PNG);
				Dino_bitmap = new wxBitmap(dino_image);
				POSISI_Y = DINO_Y + 40;
				NundukSwitch = false;
			}
		}break;
	}
}
