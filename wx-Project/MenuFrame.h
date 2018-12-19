#pragma once

#include "deklarasi.h"

class MenuWindow;
class MenuDisplay;

class MenuFrame 
	: public wxFrame
{
private:
	wxBoxSizer* boxSizer;
	MenuDisplay* MainMenuPanel;
	MenuWindow* StartGamePanel;
	bool flag = false;
	void fitWindowSize();
	
public:
	MenuFrame(const wxString &title);
	void showMainMenu();
	void showStartGame();
};

