#pragma once

#include "deklarasi.h"
#include "ObjectDino.h"
#include "Obstacle.h"
#include "Cloud.h"
#include "MenuDisplay.h"

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
	bool isCollide();
	void saveHighScore();
	int loadHighScore();
private:
	MenuDisplay *parentFrame;
	wxTimer *TimerGame;
	ObjectDino *Dino;
	vector<Obstacle*> Halangan;
	vector<Cloud*> Awan;
	int Score;
	DECLARE_EVENT_TABLE()
};

