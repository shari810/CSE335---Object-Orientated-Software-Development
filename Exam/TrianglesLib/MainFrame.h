/**
 * @file MainFrame.h
 * @author Charles B. Owen
 *
 * The top-level (main) frame of the application
 */
#ifndef _MAINFRAME_H_
#define _MAINFRAME_H_

class TrianglesView;

/**
 * The top-level (main) frame of the application
 */
class MainFrame : public wxFrame
{
private:
    /// View class for our project
    TrianglesView *mTrianglesView;

    void OnExit(wxCommandEvent& event);

public:
    void Initialize();
};

#endif //_MAINFRAME_H_
