#include "MenuFrame.h"
#include "MenuDisplay.h"
#include "MenuWindow.h"

MenuFrame::MenuFrame(const wxString & title)
	: wxFrame(NULL, wxID_ANY, title)
{
	//this->SetInitialSize(wxSize(UKURAN_X, UKURAN_Y));
	boxSizer = new wxBoxSizer(wxVERTICAL);
	
	this->StartGamePanel = new MenuWindow(this);
	this->StartGamePanel->Show(false);
	this->boxSizer->Add(StartGamePanel, 1, wxEXPAND, 0);

	this->MainMenuPanel = new MenuDisplay(this);
	this->MainMenuPanel->Show(false);
	this->boxSizer->Add(MainMenuPanel, 1, wxEXPAND, 0);
	SetSizer(boxSizer);

	showMainMenu();
}

void MenuFrame::fitWindowSize()
{
	this->boxSizer->Fit(this);
	this->boxSizer->SetSizeHints(this);
	this->SetSize(wxSize(UKURAN_X, UKURAN_Y));
	this->Layout();
}



void MenuFrame::showMainMenu()
{
	this->MainMenuPanel->Show(true);
	this->StartGamePanel->Show(false);
	
	fitWindowSize();
}

void MenuFrame::showStartGame()
{
	this->MainMenuPanel->Show(false);
	this->StartGamePanel->Show(true);

	fitWindowSize();
}
