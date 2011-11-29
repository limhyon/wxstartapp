#include <wx/app.h>
#include <wx/frame.h>

/** Main application class.
 *  This class is derived from the main wxWidgets application class.
 */
class MyApp : public wxApp {
    public:
        // Initialization function. Called at startup.
        virtual bool OnInit();
        virtual ~MyApp();
}; // MyApp

DECLARE_APP(MyApp);

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    if(!wxApp::OnInit()) {
        return false;
    } // if

    wxFrame* MainFrame = new wxFrame(NULL, wxID_ANY, wxT("MyApp"));
    MainFrame->Show();

    return true;
} // MyApp::OnInit

MyApp::~MyApp() {
    
} // MyApp::~MyApp
