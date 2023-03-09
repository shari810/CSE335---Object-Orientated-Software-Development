/**
 * @file GreenView.cpp
 * @author nicholas shari
 *
 *
 */

#include "GreenView.h"

/**
 * Initialize the me view class.
 * @param parent The parent window for this class
 */
void GreenView::GreenInitialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundColour(wxColour(24, 69, 59));

}