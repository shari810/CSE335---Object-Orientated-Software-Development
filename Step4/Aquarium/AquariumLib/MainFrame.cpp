/**
 * @file MainFrame.cpp
 * @author nicholas shari
 */

#include "pch.h"
#include "MainFrame.h"
#include "AquariumView.h"
#include "ids.h"
#

/**
* Initialize the MainFrame window.
*/
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"Aquarium", wxDefaultPosition,  wxSize( 1000,800 ));

    // Create a sizer that will lay out child windows vertically
    // one above each other
    auto sizer = new wxBoxSizer( wxVERTICAL );

    // Create the view class object as a child of MainFrame
    auto aquariumView = new AquariumView();
    aquariumView->Initialize(this);

    // Add it to the sizer
    sizer->Add(aquariumView,1, wxEXPAND | wxALL );

    // Set the sizer for this frame
    SetSizer( sizer );

    // Layout (place) the child windows.
    Layout();

    auto menuBar = new wxMenuBar( );

    CreateStatusBar();

    auto fileMenu = new wxMenu();
    auto helpMenu = new wxMenu();
    auto fishMenu = new wxMenu();

    menuBar->Append(fileMenu, L"&File" );
    menuBar->Append(fishMenu, L"&Add Fish");
    menuBar->Append(helpMenu, L"&Help");

    fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
    helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");

    fishMenu->Append(IDM_ADDFISHBETA, L"&Beta Fish", L"Add a Beta Fish");
    fishMenu->Append(IDM_ADDMAGIKARP, L"&Magikarp", L"Add a Magikarp");
    fishMenu->Append(IDM_ADDFISHBUBBLES, L"&Bubbles Fish", L"Add a Bubbles Fish");
    fishMenu->Append(IDM_ADDDECORCASTLE, L"&Decor Castle", L"Add a Decor Castle");

    fileMenu->Append(wxID_OPEN, "Open &File...\tCtrl-F", L"Open aquarium file...");

    fileMenu->Append(wxID_SAVEAS, "Save &As...\tCtrl-S", L"Save aquarium as...");


    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnHelp, this, wxID_ABOUT);
    SetMenuBar( menuBar );
}

/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

/**
 * Friendly message displayed in Help
 * @param event
 */
void MainFrame::OnHelp(wxCommandEvent& event)
{
    wxMessageBox(L"Welcome to the Aquarium!",
            L"About Aquarium",
            wxOK,
            this);
}
