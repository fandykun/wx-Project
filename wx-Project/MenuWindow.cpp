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
	Halangan.push_back(new Obstacle());
	Awan.push_back(new Cloud());
	Dino = new ObjectDino();	
}

void MenuWindow::saveHighScore()
{
	FILE *f1;
	int highscore;

	f1 = fopen("highscore.txt", "r");
	fscanf(f1, "%d", &highscore);
	fclose(f1);

	if (highscore < Score) {
		f1 = fopen("highscore.txt", "w");
		fprintf(f1, "%d", Score);
		fclose(f1);
	}
	
}

int MenuWindow::loadHighScore()
{
	FILE *f1;
	int highscore;

	f1 = fopen("highscore.txt", "r");
	fscanf(f1, "%d", &highscore);
	fclose(f1);
	return highscore;
}

MenuWindow::~MenuWindow()
{
	TimerGame->Stop();
	this->saveHighScore();

	delete TimerGame;
	delete Dino;
	//delete &Halangan;
	Awan.clear();
	Halangan.clear();
}

void MenuWindow::OnPaint(wxPaintEvent & event)
{
	wxPaintDC pdc(this);
	this->Dino->Draw(pdc);
	for (int i = 0; i < Halangan.size(); i++) Halangan[i]->Draw(pdc);
	for (int i = 0; i < Awan.size(); i++) Awan[i]->Draw(pdc);
	
	wxFont font(30, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);
	pdc.SetFont(font);
	pdc.SetTextForeground(wxColour(221, 34, 34));

	//Menggambar Score
	wxString PrintScore;
	PrintScore << Score;
	pdc.DrawText(PrintScore, wxPoint(10, 10));

	//Menggambar High Score 
	int highscore = loadHighScore();
	if (highscore < Score) highscore = Score;
	wxString PrintHighScore;
	PrintHighScore << highscore;
	pdc.DrawText(PrintHighScore, wxPoint(200, 10));
}

void MenuWindow::OnTimer(wxTimerEvent & event)
{
	static int counter = 0;
	wxMessageOutputDebug().Printf("wxTimer event: %d.", counter++);
	Score++; //Score yang ditampilkan

	//Push Obs
	static bool FlagHalangan = false;
	if (Halangan.front()->getPOSISI_X() < 400 && !FlagHalangan) {
		Halangan.push_back(new Obstacle());
		FlagHalangan = true;
	}
	if (Halangan.front()->getPOSISI_X() <= 0) {
		Halangan.erase(Halangan.begin());
		FlagHalangan = false;
	}

	//Push Cloud
	static bool FlagAwan = false;
	if (Awan.front()->getPOSISI_X() < 600 && !FlagAwan) {
		Awan.push_back(new Cloud());
		FlagAwan = true;
	}
	if (Awan.front()->getPOSISI_X() <= 0) {
		Awan.erase(Awan.begin());
		FlagAwan = false;
	}

	static bool PowerUp = false;
	static int PowerUpCounter = 0;

	if (Dino != nullptr) {
		Dino->Move();
		for (int i = 0; i < Halangan.size(); i++) Halangan[i]->Move();
		for (int i = 0; i < Awan.size(); i++) Awan[i]->Move();
		
		//PowerUp
		if (Score % 300 == 0) PowerUp = true;
		
		if (!PowerUp) {
			if (this->isCollide()) {
				wxMessageOutputDebug().Printf("Nabrak boss");
				TimerGame->Stop();
				this->saveHighScore();
			}
		} else {
			if (PowerUpCounter != 200) PowerUpCounter++;
			else {
				PowerUp = false;
				PowerUpCounter = 0;
			}
		}
		
		Refresh();
	}
}

bool MenuWindow::isCollide()
{
	if ( ((Halangan.front()->getPOSISI_X() + Halangan.front()->getDinoWidth()) >=  Dino->getPOSISI_X()) && (Halangan.front()->getPOSISI_X() < (Dino->getPOSISI_X() + Dino->getDinoWidth()) )
		&& (Dino->getPOSISI_Y() + Dino->getDinoHeight()) > Halangan.front()->getPOSISI_Y()) 
	{
		return true;
	}

	return false;
}


void MenuWindow::OnKeyUp(wxKeyEvent & event)
{
	if (Dino->pergerakan != LOMPAT) {
		Dino->pergerakan = JALAN_1;
	}
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
