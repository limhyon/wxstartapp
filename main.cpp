#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

/** Main application class.
 *  This class is derived from the main wxWidgets application class.
 */
class MyApp : public wxApp {
  public:
    // Initialization function. Called at startup.
    virtual bool OnInit();
}; // MyApp

class MyFrame: public wxFrame {
  public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
  private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    DECLARE_EVENT_TABLE();
};

enum {
  ID_Hello = 1
};

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
  EVT_MENU(ID_Hello, MyFrame::OnHello)
  EVT_MENU(wxID_EXIT, MyFrame::OnExit)
  EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
END_EVENT_TABLE()

DECLARE_APP(MyApp);
IMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
  if(!wxApp::OnInit()) {
    return false;
  } // if

  MyFrame* MainFrame = new MyFrame(wxT("Hello World"), wxPoint(50, 50), wxSize(450,340));
  MainFrame->Show();

  return true;
} // MyApp::OnInit

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame(NULL, wxID_ANY, title, pos, size) {
  wxMenu *menuFile = new wxMenu;
  menuFile->Append(ID_Hello, wxT("&Hello...\tCtrl-H"), wxT("Help string shown in status bar for this menu item"));
  menuFile->AppendSeparator();
  menuFile->Append(wxID_EXIT);
  wxMenu *menuHelp = new wxMenu;
  menuHelp->Append(wxID_ABOUT);
  wxMenuBar *menuBar = new wxMenuBar;
  menuBar->Append( menuFile, wxT("&File") );
  menuBar->Append( menuHelp, wxT("&Help") );
  SetMenuBar( menuBar );
  CreateStatusBar();
  SetStatusText(wxT("Welcome to wxWidgets!"));
}

void MyFrame::OnExit(wxCommandEvent& event) {
  Close( true );
}

void MyFrame::OnAbout(wxCommandEvent& event) {
  wxMessageBox(wxT("This is a wxWidgets' Hello world sample"),
               wxT("About Hello World"), 
               wxOK | wxICON_INFORMATION );
}

void MyFrame::OnHello(wxCommandEvent& event) {
  wxLogMessage(wxT("Hello world from wxWidgets!"));
}

