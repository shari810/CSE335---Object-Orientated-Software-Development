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
#include "FishKillerCarp.h"

#include <wx/dcbuffer.h>

using namespace std;

/// Initial fish X location
const int InitialX = 200;

/// Initial fish Y location
const int InitialY = 200;

/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
void AquariumView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &AquariumView::OnPaint, this);

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishBetaFish, this, IDM_ADDFISHBETA);
// FishMagikarp
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddFishMagikarp, this, IDM_ADDMAGIKARP);
    //BubblesFish
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddBubblesFish, this, IDM_ADDFISHBUBBLES);
    // Killer Carp
    parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &AquariumView::OnAddKillerCarp, this, IDM_ADDKILLERCARP);

    Bind(wxEVT_LEFT_DOWN, &AquariumView::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &AquariumView::OnLeftUp, this);
    Bind(wxEVT_MOTION, &AquariumView::OnMouseMove, this);
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
            mGrabbedItem->EatCheck();

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
 * Menu hander for Add Fish>Carp
 * @param event Mouse event
 */
void AquariumView::OnAddKillerCarp(wxCommandEvent& event)
{
    auto fish = make_shared<FishKillerCarp>(&mAquarium);
    fish->SetLocation(InitialX, InitialY);
    mAquarium.Add(fish);
    Refresh();
}