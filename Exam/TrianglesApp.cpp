/**
 * @file TrianglesApp.cpp
 * @author Charles B. Owen
 */
#include "pch.h"

#include "TrianglesApp.h"
#include <MainFrame.h>

/**
 * Initialize the application.
 * @return
 */
bool TrianglesApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    // Add image type handlers
    wxInitAllImageHandlers();

    auto frame = new MainFrame();
    frame->Initialize();
    frame->Show(true);

    return true;
}
