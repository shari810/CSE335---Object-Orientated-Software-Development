/**
 * @file NicholasTylerShariApp.cpp
 * @author nicholas shari
 */


#include "pch.h"
#include "NicholasTylerShariApp.h"
#include "MainFrame.h"

/**
 * Initialize the application.
 * @return
 */
bool NicholasTylerShariApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    auto frame = new MainFrame();
    frame->Initialize();
    frame->Show(true);

    return true;
}