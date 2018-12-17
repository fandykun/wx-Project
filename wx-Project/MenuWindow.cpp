#include "MenuWindow.h"

BEGIN_EVENT_TABLE(MenuWindow, wxWindow)
	EVT_KEY_UP(MenuWindow::OnKeyUp)
	EVT_KEY_DOWN(MenuWindow::OnKeyDown)
	EVT_PAINT(MenuWindow::OnPaint)
	EVT_TIMER(TIMER_ID, MenuWindow::OnTimer)
END_EVENT_TABLE()

MenuWindow::MenuWindow(wxFrame * parent)
	: wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxWHITE));

	TimerGame = new wxTimer(this, TIMER_ID);
	TimerGame->Start(60);
	Halangan = new Obstacle();
	Dino = new ObjectDino();	
}

MenuWindow::~MenuWindow()
{
	TimerGame->Stop();
	delete TimerGame;
	delete Dino;
	delete Halangan;
}

void MenuWindow::OnPaint(wxPaintEvent & event)
{
	wxPaintDC pdc(this);
	this->Dino->Draw(pdc);
	Halangan->Draw(pdc);
	
	//Menggambar Score
	wxString PrintScore;
	PrintScore << Score;
	wxFont font(30, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);
	pdc.SetFont(font);
	pdc.SetTextForeground(wxColour(221, 34, 34));
	pdc.DrawText(PrintScore, wxPoint(10, 10));
}

void MenuWindow::OnTimer(wxTimerEvent & event)
{
	static int counter = 0;
	wxMessageOutputDebug().Printf("wxTimer event: %d.", counter++);
	Score++; //Score yang ditampilkan
	
	if (Dino != nullptr) {
		Dino->Move();
		Halangan->Move();
		Refresh();
	}
}

void MenuWindow::OnKeyUp(wxKeyEvent & event)
{
	Dino->pergerakan = JALAN_1;
}

void MenuWindow::OnKeyDown(wxKeyEvent & event)
{
	int Tombol = event.GetKeyCode();
	wxMessageOutputDebug().Printf("Down: %d", Tombol);

	if (Tombol == WXK_DOWN) //Jika yang ditekan arah bawah
		Dino->pergerakan = NUNDUK;
	else if (Tombol == SPASI || Tombol == WXK_UP) {
		Dino->pergerakan = LOMPAT;
	}
	else Dino->pergerakan = JALAN_1;
}
