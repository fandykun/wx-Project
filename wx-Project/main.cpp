#include <wx/wx.h>
#include "MenuFrame.h"

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

IMPLEMENT_APP(MyApp)
DECLARE_APP(MyApp)

bool MyApp::OnInit()
{
	MenuFrame *frame = new MenuFrame("Running Dinosaur Game");
	frame->Show();
	return true;
}
