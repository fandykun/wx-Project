#include "MenuDisplay.h"
BEGIN_EVENT_TABLE(MenuDisplay, wxPanel)
	EVT_BUTTON(ID_STARTGAME, MenuDisplay::StartGame)
	EVT_BUTTON(ID_HIGHSCORE, MenuDisplay::HighScore)
	EVT_BUTTON(ID_EXIT, MenuDisplay::Exit)
END_EVENT_TABLE()

MenuDisplay::MenuDisplay(MenuFrame * parent)
	: wxPanel(parent, wxID_ANY), parentFrame(parent)
{
	this->SetBackgroundColour(wxColour(*wxWHITE));
	wxButton* StartGameButton = new wxButton(this, ID_STARTGAME, wxT("Start Game"), wxPoint(BUTTON_X, BUTTON_Y), wxDefaultSize);
	wxButton* HighScoreButton = new wxButton(this, ID_HIGHSCORE, wxT("High Scores"), wxPoint(BUTTON_X, BUTTON_Y + 20), wxDefaultSize);
	wxButton* ExitButton = new wxButton(this, ID_EXIT, wxT("Exit"), wxPoint(BUTTON_X, BUTTON_Y + 40), wxDefaultSize);
}

MenuDisplay::~MenuDisplay()
{
}

void MenuDisplay::StartGame(wxCommandEvent & event)
{
	parentFrame->showStartGame();
}

void MenuDisplay::HighScore(wxCommandEvent & event)
{
}

void MenuDisplay::Exit(wxCommandEvent & event)
{
}
