/**
 * @file AquariumView.cpp
 * @author nicholas shari
 */

#include "pch.h"
#include "AquariumView.h"

#include <wx/dcbuffer.h>

/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
void AquariumView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &AquariumView::OnPaint, this);

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