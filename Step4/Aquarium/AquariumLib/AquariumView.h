/**
 * @file AquariumView.h
 * @author nicholas shari
 *
 * View the aquarium
 */

#ifndef AQUARIUM_AQUARIUMVIEW_H
#define AQUARIUM_AQUARIUMVIEW_H

#include "Aquarium.h"

/**
 * View class for our aquarium
 */
class AquariumView : public wxWindow {

private:

    void OnPaint(wxPaintEvent& event);

    /// An object that describes our aquarium
    Aquarium  mAquarium;

    /// Any item we are currently dragging
    std::shared_ptr<Item> mGrabbedItem;

    /// The timer that allows for animation
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    long mTime = 0;

    void OnMouseMove(wxMouseEvent& event);

    void OnLeftUp(wxMouseEvent& event);

    void OnLeftDown(wxMouseEvent& event);

public:

    void Initialize(wxFrame* parent);

    void OnAddFishBetaFish(wxCommandEvent& event);

    void OnAddFishMagikarp(wxCommandEvent& event);

    void OnAddBubblesFish(wxCommandEvent& event);

    void OnAddDecorCastle(wxCommandEvent& event);

    void OnFileSaveAs(wxCommandEvent& event);

    void OnFileOpen(wxCommandEvent& event);

    void Timer(wxTimerEvent& event);
};

#endif //AQUARIUM_AQUARIUMVIEW_H
