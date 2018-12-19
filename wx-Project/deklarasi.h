#pragma once
#include <wx/wx.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>

using namespace std;

//=========================
//--Posisi dan Pergerakan--
//=========================
#define UKURAN_X 900
#define UKURAN_Y 500
#define DINO_X 30
#define DINO_Y 300
#define OBSTACLE_X UKURAN_X+50
#define OBSTACLE_Y DINO_Y-10
#define BUTTON_X 100
#define BUTTON_Y 100
#define CLOUD_X UKURAN_X+50
#define CLOUD_Y 80
//--------------------------
#define JALAN_1 1
#define JALAN_2 2
#define LOMPAT 3
#define NUNDUK 40
//--------------------------
#define KAKTUS_BESAR 0
#define KAKTUS_KECIL 1
#define KAKTUS_BANYAK 2

//=========================
//-----Kode / ID ----------
//=========================
#define TIMER_ID 2000
#define SPASI 32
#define ID_STARTGAME 1001
#define ID_HIGHSCORE 1002
#define ID_EXIT 1003
#define ID_BACK 1004
