/**
 * @file AquariumView.cpp
 * @author nicholas shari
 */

#include "pch.h"
#include "AquariumView.h"
#include "ids.h"
#include "FishBeta.h"
#include "FishMagikarp.h"
#include "FishBubbles.h"
#include "DecorCastle.h"


#include <wx/dcbuffer.h>

using namespace std;

/// Initial fish X location
const int InitialX = 200;

/// Initial fish Y location
const int InitialY = 200;

/// Frame duration in milliseconds
const int FrameDuration = 30;

/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
void AquariumView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &AquariumView::OnPaint, this);
    Bind(wxEVT_TIMER, &AquariumView::Timer, this);


    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishBetaFish, this, IDM_ADDFISHBETA);
// FishMagikarp
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishMagikarp, this, IDM_ADDMAGIKARP);
    //BubblesFish
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddBubblesFish, this, IDM_ADDFISHBUBBLES);
    //DecorCastle
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddDecorCastle, this, IDM_ADDDECORCASTLE);
    // save as
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnFileSaveAs, this, wxID_SAVEAS);
    // save as
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnFileOpen, this, wxID_OPEN);



    Bind(wxEVT_LEFT_DOWN, &AquariumView::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &AquariumView::OnLeftUp, this);
    Bind(wxEVT_MOTION, &AquariumView::OnMouseMove, this);

    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);
    mStopWatch.Start();
}

/**  Old aquarium view for basic drawing references. (Removed)
void AquariumView::OnPaint(wxPaintEvent& event)
{

    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    wxPen pen(wxColour(0, 128, 0), 3);
    dc.SetPen(pen);
    dc.DrawLine(100, 100, 300, 200);

    wxBrush brush(wxColour(0, 0, 255));
    dc.SetBrush(brush);
    dc.SetPen(wxNullPen);  //no outline
    dc.SetBrush(wxNullBrush); //dont fill rectangle
    dc.DrawRectangle(100, 125, 400, 50);

    // Creates a 20-pixel tall font
    wxFont font(wxSize(0, 20),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);
    dc.SetFont(font);

    dc.SetTextForeground(wxColour(0, 64, 0));
    dc.DrawText(L"CSE 335 rocks!",  // Text to draw
            10,     // x coordinate for the left size of the text
            10);    // y coordinate for the top of the text
}
**/

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void AquariumView::OnPaint(wxPaintEvent& event)
{
    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time();
    auto elapsed = (double)(newTime - mTime) * 0.001;
    mTime = newTime;
    mAquarium.Update(elapsed);

    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    mAquarium.OnDraw(&dc);


}

/**
 * Menu hander for Add Fish>Beta Fish
 * @param event Mouse event
 */
void AquariumView::OnAddFishBetaFish(wxCommandEvent& event)
{
    auto fish = make_shared<FishBeta>(&mAquarium);
    fish->SetLocation(InitialX, InitialY);
    mAquarium.Add(fish);
    Refresh();
}

/**
 * Handle the left mouse button down event
 * @param event
 */
void AquariumView::OnLeftDown(wxMouseEvent &event)
{
    mGrabbedItem = mAquarium.HitTest(event.GetX(), event.GetY());

    if (mGrabbedItem != nullptr)
    {
        // We have selected an item
        // Move it to the end of the list of items
        // you'll need code here to do that...
        mAquarium.MovetoEnd(mGrabbedItem);
    }
}

/**
* Handle the left mouse button down event
* @param event
*/
void AquariumView::OnLeftUp(wxMouseEvent &event)
{
    OnMouseMove(event);
}

/**
* Handle the left mouse button down event
* @param event
*/
void AquariumView::OnMouseMove(wxMouseEvent &event)
{
    // See if an item is currently being moved by the mouse
    if (mGrabbedItem != nullptr)
    {
        // If an item is being moved, we only continue to
        // move it while the left button is down.
        if (event.LeftIsDown())
        {
            mGrabbedItem->SetLocation(event.GetX(), event.GetY());

        }
        else
        {
            // When the left button is released, we release the
            // item.
            mGrabbedItem = nullptr;
        }

        // Force the screen to redraw
        Refresh();
    }
}

/**
 * Menu hander for Add Fish>Margikarp
 * @param event Mouse event
 */
void AquariumView::OnAddFishMagikarp(wxCommandEvent& event)
{
    auto fish = make_shared<FishMagikarp>(&mAquarium);
    fish->SetLocation(InitialX, InitialY);
    mAquarium.Add(fish);
    Refresh();
}

/**
 * Menu hander for Add Fish>Bubbles
 * @param event Mouse event
 */
void AquariumView::OnAddBubblesFish(wxCommandEvent& event)
{
    auto fish = make_shared<FishBubbles>(&mAquarium);
    fish->SetLocation(InitialX, InitialY);
    mAquarium.Add(fish);
    Refresh();
}

/**
 * Menu hander for Add DecorCastle
 * @param event Mouse event
 */
void AquariumView::OnAddDecorCastle(wxCommandEvent& event)
{
    auto fish = make_shared<DecorCastle>(&mAquarium);
    fish->SetLocation(InitialX, InitialY);
    mAquarium.Add(fish);
    Refresh();
}

/**
 * Menu hander for Add DecorCastle
 * @param event Mouse event
 */
void AquariumView::OnFileSaveAs(wxCommandEvent& event)
{
    wxFileDialog saveFileDialog(this, _("Save Aquarium file"), "", "",
            "Aquarium Files (*.aqua)|*.aqua", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    auto filename = saveFileDialog.GetPath();

    mAquarium.Save(filename);
}

/**
 * File>Open menu handler
 * @param event Menu event
 */
void AquariumView::OnFileOpen(wxCommandEvent& event)
{
    wxFileDialog loadFileDialog(this, _("Load Aquarium file"), "", "",
            "Aquarium Files (*.aqua)|*.aqua", wxFD_OPEN);
    if (loadFileDialog.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    auto filename = loadFileDialog.GetPath();

    mAquarium.Load(filename);
    Refresh();
}

/**
 * Refresh the timer
 * @param event timer event
 */
void AquariumView::Timer(wxTimerEvent& event)
{
    Refresh();
}