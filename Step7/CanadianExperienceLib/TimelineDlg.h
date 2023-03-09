/**
 * @file TimelineDlg.h
 * @author nicholas shari
 *
 *
 */

#ifndef MAIN_CPP_TIMELINEDLG_H
#define MAIN_CPP_TIMELINEDLG_H

#include "Timeline.h"

/**
 * Timeline dialog box
 */
class TimelineDlg final : public wxDialog {
private:

    Timeline* mTimeline;
    /// Number of frames in the animation
    int mNumberOfFrames;
    /// FrameRate
    int mFrameRate;


public:

    TimelineDlg(wxWindow* parent, Timeline* timeline);

    void OnOK(wxCommandEvent& event);
};

#endif //MAIN_CPP_TIMELINEDLG_H
