#pragma once
#include "deklarasi.h"
#include "MenuFrame.h"

class MenuDisplay : public wxPanel
{
public:
	MenuDisplay(MenuFrame *parent);
	~MenuDisplay();

	void StartGame(wxCommandEvent &event);
	void HighScore(wxCommandEvent &event);
	void Exit(wxCommandEvent &event);
private:
	MenuFrame *parentFrame;
	DECLARE_EVENT_TABLE()
};

