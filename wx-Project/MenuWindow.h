#pragma once

#include "deklarasi.h"
#include "ObjectDino.h"
#include "Obstacle.h"

class MenuWindow
	: public wxWindow
{
public:
	MenuWindow(wxFrame *parent);
	~MenuWindow();
	void OnPaint(wxPaintEvent &event);
	void OnTimer(wxTimerEvent &event);
	void OnKeyUp(wxKeyEvent &event);
	void OnKeyDown(wxKeyEvent &event);
private:
	wxTimer *TimerGame;
	ObjectDino *Dino;
	Obstacle *Halangan;
	int Score;
	DECLARE_EVENT_TABLE()
};

