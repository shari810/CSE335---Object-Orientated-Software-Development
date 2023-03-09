/**
 * @file Scoreboard.cpp
 * @author nicholas shari
 */

#include "pch.h"
#include "Scoreboard.h"

#include <string>

using namespace std;

/**  Constructor
 * @param game The game this scoreboard is a member of
 */
Scoreboard::Scoreboard(Game *game) : mGame(game)
{
    mCorrect = 0;
    mMissed = 0;
    mUnfair = 0;
}


/**
 * Draw the scoreboard at the top of the screen.
 * @param graphics
 */
void Scoreboard::Draw(wxGraphicsContext *graphics)
{

    //draw the text
    wxFont font(wxSize(25, 40),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);
    graphics->SetFont(font, wxColour(*wxCYAN));
    wstring correct(L"Correct");
    graphics->DrawText(correct,-450,100);


    wstring missed(L"Missed");
    graphics->DrawText(missed,-70,100);

    wstring unfair(L"Unfair");
    graphics->DrawText(unfair,300,100);


    //draw the count
    wxFont fontNum(wxSize(70, 90),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_BOLD);
    graphics->SetFont(fontNum, wxColour(*wxCYAN));

    graphics->DrawText(wxString::Format(wxT("%i"),mCorrect), -400, 20);
    graphics->DrawText(wxString::Format(wxT("%i"),mMissed), -30, 20);
    graphics->DrawText(wxString::Format(wxT("%i"),mUnfair), 330, 20);

}

/**  Handle updates for animation
* @param elapsed The time since the last update
*/
void Scoreboard::Update(double elapsed)
{

}

/**
 * Increment the Correct count by one when called
 * Will be used upon hit detection
 */
void Scoreboard::IncrementCorrect()
{
    mCorrect++;
}

/**
 * Increment the Unfair count by one when called
 * Will be used upon hit detection
 */
void Scoreboard::IncrementUnfair()
{
    mUnfair++;
}

/**
 * Increment the Correct count by one when called
 * Will be used upon hit detection
 */
void Scoreboard::IncrementMissed()
{
    mMissed++;
}