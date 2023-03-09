/**
 * @file GameView.h
 * @author Jonathan Ayoub
 *
 * The class where the window is being designed.
 */

#ifndef PROJECT1_GAMEVIEW_H
#define PROJECT1_GAMEVIEW_H

#include <wx/wx.h>

#include "Game.h"

/**
 * View class for our game
 */
class GameView : public wxWindow {

public:
    void Initialize(wxFrame* parent);

    void AddMenus(wxFrame* mainFrame, wxMenuBar* menuBar, wxMenu* variantMenu, wxMenu* fileMenu);

    void OnTimer(wxTimerEvent& event);

    /**
    * Stop the timer so the window can close
    */
    void Stop() {mTimer.Stop();}
private:
    void OnPaint(wxPaintEvent& event);

    void OnVariantStandard(wxCommandEvent& event);

    void OnUpdateVariantStandard(wxUpdateUIEvent& event);

    void OnVariantCustom(wxCommandEvent& event);

    void OnUpdateVariantCustom(wxUpdateUIEvent& event);

    void OnMouseMove(wxMouseEvent& event);

    void OnLeftDown(wxMouseEvent& event);

    /// Check for game variant
    bool mCheck = true;

    /// An object that describes our game
    Game mGame;

    /// The timer that allows for animation
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    long mTime = 0;

    /// The item image
    std::shared_ptr<wxImage> mBackground;

    /// The background bitmap
    wxGraphicsBitmap mBackgroundBitmap;

    /// Default Scale
    double mScale = 0;
    /// Default X Offset
    double mXOffset = 0;
    /// Default Y Offset
    double mYOffset = 0;



};

#endif //PROJECT1_GAMEVIEW_H
