/**
 * @file MainFrame.cpp
 * @author Charles B. Owen
 */
#include "pch.h"

#include "MainFrame.h"

#include "TrianglesView.h"
#include "ids.h"


/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"Project", wxDefaultPosition,  wxSize( 1000,800 ));

    auto menuBar = new wxMenuBar(0);
    SetMenuBar( menuBar );
    auto fileMenu = new wxMenu();
    auto triangleMenu = new wxMenu();
    auto meshMenu = new wxMenu();

    menuBar->Append(fileMenu, L"&File");
    menuBar->Append(triangleMenu, L"&Triangle");
    menuBar->Append(meshMenu, L"&Mesh");

    fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit this program");
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);


    triangleMenu->Append(IDM_SHOW_TRIANGLES_1, L"Example &1", L"Show triangles example 1");
    triangleMenu->Append(IDM_SHOW_TRIANGLES_2, L"Example &2", L"Show triangles example 2");
    triangleMenu->Append(IDM_SHOW_TRIANGLES_3, L"Example &3", L"Show triangles example 3");


    meshMenu->AppendCheckItem(IDM_TOGGLE_RANDCOLOR, L"&Random Color", L"Color mesh with random colors");
    meshMenu->AppendCheckItem(IDM_TOGGLE_FILLMESH, L"&Fill Mesh", L"Fill the mesh");
    meshMenu->AppendSeparator();
    meshMenu->Append(IDM_SHOW_MESH_EMPTY, L"&Empty Mesh", L"Show empty mesh");
    meshMenu->Append(IDM_SHOW_MESH_M, L"Mesh &M", L"Show mesh example M");
    meshMenu->Append(IDM_SHOW_MESH_MI, L"Mesh M&I", L"Show mesh example Michigan");
    meshMenu->Append(IDM_SHOW_MESH_MSU, L"Mesh MS&U", L"Show mesh example MSU");

    this->SetMenuBar( menuBar );

    auto sizer = new wxBoxSizer( wxVERTICAL );

    mTrianglesView = new TrianglesView();
    mTrianglesView->Initialize(this);

    sizer->Add(mTrianglesView,1, wxEXPAND | wxALL );

    SetSizer( sizer );
    Layout();
}


/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}