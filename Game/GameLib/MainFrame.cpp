/**
 * @file MainFrame.cpp
 * @author Jonathan Ayoub
 *
 *
 */

#include "pch.h"
#include "MainFrame.h"

#include <wx/xml/xml.h>

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"UML Wars", wxDefaultPosition, wxSize(1000, 800));
    auto sizer = new wxBoxSizer(wxVERTICAL);

    mGameView = new GameView();
    mGameView->Initialize(this);

    // Add it to the sizer
    sizer->Add(mGameView,1, wxEXPAND | wxALL );

    // Set the sizer for this frame
    SetSizer( sizer );

    // Layout (place) the child windows.
    Layout();

    CreateStatusBar();

    auto menuBar = new wxMenuBar( );

    auto fileMenu = new wxMenu();
    auto variantMenu = new wxMenu();
    auto helpMenu = new wxMenu();

    menuBar->Append(fileMenu, L"&File" );
    menuBar->Append(variantMenu, L"&Variant");
    menuBar->Append(helpMenu, L"&Help");

    fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
    helpMenu->Append(wxID_ABOUT, "&About\tF1", "Show about dialog");

    mGameView->AddMenus(this, menuBar, variantMenu , fileMenu);

    SetMenuBar( menuBar );

    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnHelp, this, wxID_ABOUT);
    Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);
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
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnHelp(wxCommandEvent& event)
{
    wxMessageBox(L"Welcome to UML Wars!",
            L"About UML Wars",
            wxOK,
            this);
}

/**
 * Handle a close event. Stop the animation and destroy this window.
 * @param event The Close event
 */
void MainFrame::OnClose(wxCloseEvent& event)
{
    mGameView->Stop();
    Destroy();
}