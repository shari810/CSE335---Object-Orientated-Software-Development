/**
 * @file NicholasTylerShariView.cpp
 * @author nicholas shari
 * 1. Your art must contain at least 10 lines and 5 rectangles.
 * 2. At least one rectangle must be un-filled, meaning only the outline is drawn.
 * 3. You must use at least four colors.
 *
 * I drew a really bad spongebob. Like an LSD spongebob that is probably homeless.
 * I'll use the homelessness as the reason for a lack of pineapple home. And not my personal laziness.
 */

#include "NicholasTylerShariView.h"
#include <wx/dcbuffer.h>
#include <wx/colour.h>
#include <wx/gdicmn.h>

/**
 * Initialize the me view class.
 * @param parent The parent window for this class
 */
void NicholasTylerShariView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_PAINT, &NicholasTylerShariView::OnPaint, this);
}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void NicholasTylerShariView::OnPaint(wxPaintEvent& event)
{
    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    wxSize size = GetClientSize(); //find window dimensions

    //draw first
    dc.SetPen(*wxBLACK);
    dc.SetBrush(wxNullBrush); //dont fill rectangle
    dc.DrawRectangle(100,80, size.x/1.25, size.y/1.25);  //create portrait-like frame, that satisfies requirement #2.

    //create colored portrait background
    // 2nd Rectangle
    dc.SetPen(*wxBLACK);
    dc.SetBrush(*wxCYAN);
    dc.DrawRectangle(100*1.1,80*1.1, size.x/1.3, size.y/1.3);


    //create body
    // 3rd rectangle
    dc.SetPen(*wxBLACK);
    dc.SetBrush(*wxYELLOW);
    dc.DrawRectangle(size.x/3,size.y/3, size.x/3.5, size.y/2.5);

    //create shirt
    //4th rectangle
    dc.SetPen(*wxBLACK);
    dc.SetBrush(*wxWHITE);
    dc.DrawRectangle(size.x/3,size.y/1.75, size.x/3.5, size.y/10);


    //legs
    dc.SetPen(*wxBLACK);
    dc.SetBrush(*wxYELLOW);
    dc.DrawRectangle(size.x/2.375,size.y/1.3, size.x/50, size.y/15);
    dc.DrawRectangle(size.x/1.93,size.y/1.3, size.x/50, size.y/15);

    //pants cuffs??
    dc.SetPen(*wxBLACK);
    dc.SetBrush(wxColour(200, 150, 0)); //lightbrown
    dc.DrawRoundedRectangle(size.x/2.45,size.y/1.31, size.x/20, size.y/35, -5);
    dc.DrawRoundedRectangle(size.x/2,size.y/1.31, size.x/20, size.y/35, -5);

    //create pants
    //5th rectangle
    dc.SetPen(*wxBLACK);
    dc.SetBrush(wxColour(200, 150, 0)); //light brown
    dc.DrawRectangle(size.x/3,size.y/1.5, size.x/3.5, size.y/10);

    //create eyes
    dc.SetPen(*wxBLACK);
    dc.SetBrush(*wxWHITE);
    dc.DrawCircle(size.x/1.85,size.y/2.5, size.x/30);
    dc.DrawCircle(size.x/2.25,size.y/2.5, size.x/30);
    dc.SetBrush(*wxCYAN);
    dc.DrawCircle(size.x/1.85,size.y/2.5, size.x/50);
    dc.DrawCircle(size.x/2.25,size.y/2.5, size.x/50);
    dc.SetBrush(*wxBLACK);
    dc.DrawCircle(size.x/1.85,size.y/2.5, size.x/100);
    dc.DrawCircle(size.x/2.25,size.y/2.5, size.x/100);

    // nose
    dc.SetPen(*wxBLACK);
    dc.SetBrush(*wxYELLOW);
    //wxCoord x, wxCoord y, wxCoord width, wxCoord height, double start, double end
    dc.DrawEllipticArc(size.x/2.1,size.y/2.4,size.x/50,size.y/20,90,45);

    //mouth
    dc.SetPen(*wxBLACK);
    dc.SetBrush(( wxColour(240, 50, 225) ) );
    //wxCoord x, wxCoord y, wxCoord width, wxCoord height, double start, double end
    dc.DrawEllipse(size.x/2.5,size.y/2.1, size.x/5, size.y/15);

    //teeth
    //4th rectangle
    dc.SetPen(*wxBLACK);
    dc.SetBrush(*wxWHITE);
    dc.DrawRectangle(size.x/2.15,size.y/2.1, size.x/50, size.y/35);
    dc.DrawRectangle(size.x/2.05,size.y/2.1, size.x/50, size.y/35);

    //necktie
    dc.SetPen(*wxBLACK);
    dc.SetBrush(*wxRED);
    dc.DrawRoundedRectangle(size.x/2.15,size.y/1.75, size.x/35, size.y/25, -5);
    dc.DrawRoundedRectangle(size.x/2.125,size.y/1.65, size.x/50, size.y/15, 5);
    dc.DrawRectangle(size.x/2.1525,size.y/1.5, size.x/30, size.y/30);

    //pants black lines
    wxPen pen(*wxBLACK);
    dc.SetPen(pen);
    dc.DrawLine(size.x/2.75,size.y/1.45, size.x/2.5,size.y/1.45);
    dc.DrawLine(size.x/2.45,size.y/1.45, size.x/2.25,size.y/1.45);
    dc.DrawLine(size.x/1.95,size.y/1.45, size.x/1.825,size.y/1.45);
    dc.DrawLine(size.x/1.80,size.y/1.45, size.x/1.675,size.y/1.45);

    //socks
    dc.SetPen(*wxBLACK);
    dc.SetBrush(*wxWHITE);
    dc.DrawRectangle(size.x/2.375,size.y/1.25, size.x/50, size.y/25);
    dc.DrawRectangle(size.x/1.93,size.y/1.25, size.x/50, size.y/25);

    //sock lines blue > red
    dc.SetPen(*wxBLUE);
    dc.DrawLine(size.x/2.37,size.y/1.225, size.x/2.275,size.y/1.225);
    dc.DrawLine(size.x/1.925,size.y/1.225, size.x/1.865,size.y/1.225);
    dc.SetPen(*wxRED);
    dc.DrawLine(size.x/2.37,size.y/1.22, size.x/2.275,size.y/1.22);
    dc.DrawLine(size.x/1.925,size.y/1.22, size.x/1.865,size.y/1.22);

    //shoes
    dc.SetPen(*wxBLACK);
    dc.SetBrush(*wxBLACK);
    dc.DrawRoundedRectangle(size.x/2.45,size.y/1.2, size.x/20, size.y/35, -5);
    dc.DrawRoundedRectangle(size.x/2,size.y/1.2, size.x/20, size.y/35, -5);


    //arms
    dc.SetPen(*wxBLACK);
    dc.SetBrush(*wxYELLOW);
    dc.DrawRectangle(size.x/3.25,size.y/1.725, size.x/50, size.y/10);
    dc.DrawRectangle(size.x/1.6,size.y/1.725, size.x/50, size.y/10);

    //shoulders
    dc.SetPen(*wxBLACK);
    dc.SetBrush(*wxWHITE);
    dc.DrawRoundedRectangle(size.x/3.4,size.y/1.75, size.x/20, size.y/35, -5);
    dc.DrawRoundedRectangle(size.x/1.63,size.y/1.75, size.x/20, size.y/35, -5);

    //hands
    dc.SetPen(*wxBLACK);
    dc.SetBrush(*wxYELLOW);
    dc.DrawRectangle(size.x/3.25,size.y/1.5, size.x/40, size.y/40);
    dc.DrawRectangle(size.x/1.6,size.y/1.5, size.x/40, size.y/40);

    //finger lines
    dc.SetPen(*wxBLACK);
    //left hand
    dc.DrawLine(size.x/3.2,size.y/1.5, size.x/3.2,size.y/1.45);
    dc.DrawLine(size.x/3.15,size.y/1.5, size.x/3.15,size.y/1.45);
    dc.DrawLine(size.x/3.1,size.y/1.5, size.x/3.1,size.y/1.45);
    //right hand
    dc.DrawLine(size.x/1.59,size.y/1.5, size.x/1.59,size.y/1.45);
    dc.DrawLine(size.x/1.575,size.y/1.5, size.x/1.575,size.y/1.45);
    dc.DrawLine(size.x/1.56,size.y/1.5, size.x/1.56,size.y/1.45);






}