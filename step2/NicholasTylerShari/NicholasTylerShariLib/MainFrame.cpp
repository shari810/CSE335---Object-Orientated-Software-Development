/**
 * @file MainFrame.cpp
 * @author nicholas shari
 */

#include "pch.h"
#include "MainFrame.h"
#include "NicholasTylerShariView.h"
#include "GreenView.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"NicholasTylerShari", wxDefaultPosition,  wxSize( 1000,800 ));

    // Create a sizer that will lay out child windows vertically
    // one above each other
    auto sizer = new wxBoxSizer( wxHORIZONTAL );

    // Create the view class object as a child of MainFrame
    auto nicholasView = new NicholasTylerShariView();
    nicholasView->Initialize(this);

    // Create the view class object as a child of MainFrame
    auto greenView = new GreenView();
    greenView->GreenInitialize(this);


    sizer->Add(greenView,1, wxEXPAND | wxALL );
    // Add it to the sizer
    sizer->Add(nicholasView,3, wxEXPAND | wxALL );


    // Set the sizer for this frame
    SetSizer( sizer );

    // Layout (place) the child windows.
    Layout();
}