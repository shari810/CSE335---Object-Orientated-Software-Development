/**
 * @file TimelineDlg.cpp
 * @author nick
 */

#include "TimelineDlg.h"
#include <wx/xrc/xmlres.h>
#include <wx/valnum.h>

/**
 * Constructor
 * @param parent The parent window we will center in
 * @param timeline Pointer to the timeline we are editing
 */
TimelineDlg::TimelineDlg(wxWindow* parent, Timeline* timeline) : mTimeline(timeline)
{
    wxXmlResource::Get()->LoadDialog(this, parent, L"TimelineDlg");
    mNumberOfFrames = timeline->GetNumFrames();
    mFrameRate = timeline->GetFrameRate();


    auto numFramesCtrl = XRCCTRL(*this, "TimelineDlgNumFrames", wxTextCtrl);
    auto rateFramesCtrl = XRCCTRL(*this, "TimelineDlgFrameRate", wxTextCtrl);
    wxIntegerValidator<int> numFramesValidator(&mNumberOfFrames);
    wxIntegerValidator<int> rateFramesValidator(&mFrameRate);
    numFramesValidator.SetRange(1, 10000);
    rateFramesValidator.SetRange(1,60);
    numFramesCtrl->SetValidator(numFramesValidator);
    rateFramesCtrl->SetValidator(rateFramesValidator);
    Bind(wxEVT_BUTTON, &TimelineDlg::OnOK, this, wxID_OK);
}

/**
 * Handle an OK button press
 * @param event Button event
 */
void TimelineDlg::OnOK(wxCommandEvent& event)
{
    if ( Validate() && TransferDataFromWindow() )
    {
        // Success! Set values in the class
        mTimeline->SetNumFrames(mNumberOfFrames);
        mTimeline->SetFrameRate((mFrameRate));
        EndModal(wxID_OK);

    }
}