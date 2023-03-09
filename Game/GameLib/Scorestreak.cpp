/**
 * @file Scorestreak.cpp
 * @author Jonathan Ayoub
 *
 */

#include "pch.h"
#include "Scorestreak.h"
#include "Item.h"
#include <string>
#include "Game.h"

using namespace std;

/**  Constructor
 * @param game The game this scorestreak is a member of
 */
Scorestreak::Scorestreak(Game *game) : mGame(game)
{
    mStreakCounter = 14;
}

/**
 * Draw the scorestreak at the top right of the screen.
 * @param graphics
 */
void Scorestreak::Draw(wxGraphicsContext *graphics)
{
    wxFont font(wxSize(25, 40),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_BOLD);
    graphics->SetFont(font, wxColour(*wxGREEN));
    wstring streak(L"Streak");
    graphics->DrawText(streak,490,25);

    wxFont fontNum(wxSize(70, 90),
                   wxFONTFAMILY_SWISS,
                   wxFONTSTYLE_NORMAL,
                   wxFONTWEIGHT_BOLD);
    graphics->SetFont(fontNum, wxColour(*wxGREEN));
    graphics->DrawText(wxString::Format(wxT("%i"),mStreakCounter), 530, 65);
}


/**  Handle updates for animation
* @param elapsed The time since the last update
*/
void Scorestreak::Update(double elapsed)
{

}

/**
 * Will increment the counter by one if correct UML is hit
 */
void Scorestreak::IncrementCounter(){
    mStreakCounter++;
    if (mStreakCounter == 5)
        mFirstStreakUsed = true;
}

/**
 * Will reset streak counter to 0 if bad UML is hit
 */
void Scorestreak::StreakBroke(){
    mStreakCounter = 0;
    mFirstStreakUsed = false;
}


void Scorestreak::RemoveBadStreak(std::vector<std::shared_ptr<Item>>* items) {
    if (mStreakCounter == 5 && mFirstStreakUsed){
        for (auto i = items->begin()+1; i!=items->end(); i++) {
            if ((*i)->GetBad()) {
                auto loc = find(begin(*items), end(*items), (*i));
                if (loc != end(*items)){
                    items->erase(loc);
                    break;
                }
            }
        }
        mFirstStreakUsed = false;
    }
}


bool Scorestreak::NukeStreak(){
    if (mStreakCounter == 15){
        return true;
    }
    return false;
}

void Scorestreak::SlowMotionStreakActivate(Game game) {
    if (mStreakCounter == 10)
    {
        for (int i = 1; i <= size(game.GetItems())-1; i++)
        {
            game.GetItems()[i]->HalfSpeed();
        }
    }
}

void Scorestreak::SlowMotionStreakDeactivate(Game game) {
    if (mStreakCounter == 10)
    {
        for (int i = 1; i <= size(game.GetItems())-1; i++)
        {
            game.GetItems()[i]->DoubleSpeed();
        }
    }

    mSlowMotionUsed = true;

}