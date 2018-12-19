#include "Cloud.h"



Cloud::Cloud()
{
	wxImageHandler *PNGLoader = new wxPNGHandler;
	wxImage::AddHandler(PNGLoader);

}


Cloud::~Cloud()
{
}

void Cloud::Draw(wxPaintDC & pdc)
{
	if (Cloud_bitmap != nullptr)
		pdc.DrawBitmap(*Cloud_bitmap, wxPoint(POSISI_X, POSISI_Y), true);
}

void Cloud::Move()
{
	wxStandardPaths &stdPath = wxStandardPaths::Get();
	wxString filelocation = stdPath.GetExecutablePath();
	if (POSISI_X > -130) POSISI_X -= 5;
	else POSISI_X = CLOUD_X;

	filelocation = wxFileName(filelocation).GetPath() + wxT("\\cloud0000.png");
	wxImage Image(filelocation, wxBITMAP_TYPE_PNG);
	Cloud_bitmap = new wxBitmap(Image);
}

int Cloud::getPOSISI_X()
{
	return POSISI_X;
}

int Cloud::getPOSISI_Y()
{
	return POSISI_Y;
}

int Cloud::getCloudWidth()
{
	return Cloud_bitmap->GetWidth();
}

int Cloud::getCloudHeight()
{
	return Cloud_bitmap->GetHeight();
}
