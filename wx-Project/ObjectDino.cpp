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
			pergerakan = JALAN_2;
			POSISI_Y = DINO_Y;
			Delay_Lompat = 0;
		}break;
		case JALAN_2: {
			filelocation = wxFileName(filelocation).GetPath() + wxT("\\dinorun0001.png");
			pergerakan = JALAN_1;
		}break;
		case LOMPAT: {
			filelocation = wxFileName(filelocation).GetPath() + wxT("\\dinojump0000.png");
			if (Delay_Lompat < 200) {
				POSISI_Y = DINO_Y - Delay_Lompat;
				Delay_Lompat += 20;
				if (Delay_Lompat > 200) Delay_Lompat = 200;
			}
			else if(Delay_Lompat >= 200) {
				if (POSISI_Y < DINO_Y) {
					POSISI_Y += 15;
				}
				else {
					pergerakan = JALAN_1;
					POSISI_Y = DINO_Y;
				}
			}
		}break;
		case NUNDUK: {
			static bool NundukSwitch = false;
			if (NundukSwitch == false) {
				filelocation = wxFileName(filelocation).GetPath() + wxT("\\dinoduck0000.png");
				
				POSISI_Y = DINO_Y + 40;
				NundukSwitch = true;
			}
			else {
				filelocation = wxFileName(filelocation).GetPath() + wxT("\\dinoduck0001.png");
				POSISI_Y = DINO_Y + 40;
				NundukSwitch = false;
			}
		}break;
	}

	wxImage dino_image(filelocation, wxBITMAP_TYPE_PNG);
	Dino_bitmap = new wxBitmap(dino_image);
}

int ObjectDino::getDinoWidth()
{
	return Dino_bitmap->GetWidth();
}

int ObjectDino::getDinoHeight()
{
	return Dino_bitmap->GetHeight();
}

int ObjectDino::getPOSISI_Y()
{
	return POSISI_Y;
}

int ObjectDino::getPOSISI_X()
{
	return POSISI_X;
}


