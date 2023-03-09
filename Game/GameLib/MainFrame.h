/**
 * @file MainFrame.h
 * @author Jonathan Ayoub
 *
 * The top-level (main) frame of the application
 */


#ifndef PROJECT1_MAINFRAME_H
#define PROJECT1_MAINFRAME_H

#include "GameView.h"

/**
 * The top-level (main) frame of the application
 */
class MainFrame :public wxFrame {
private:
    /// View class for our game
    GameView *mGameView;

    void OnExit(wxCommandEvent& event);
    void OnHelp(wxCommandEvent& event);

    void OnClose(wxCloseEvent& event);

public:
    void Initialize();
};

#endif //PROJECT1_MAINFRAME_H
