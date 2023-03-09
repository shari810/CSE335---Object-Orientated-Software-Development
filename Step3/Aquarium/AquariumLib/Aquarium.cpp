/**
 * @file Aquarium.cpp
 * @author nicholas shari
 */

#include "Aquarium.h"
#include "FishBeta.h"
#include <algorithm>

using namespace std;
/**
 * Draw the aquarium
 * @param dc The device context to draw on
 */
void Aquarium::OnDraw(wxDC *dc)
{
    dc->DrawBitmap(*mBackground, 0, 0);

    wxFont font(wxSize(0, 20),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);
    dc->SetFont(font);
    dc->SetTextForeground(wxColour(0, 64, 0));
    dc->DrawText(L"Under the Sea!", 10, 10);

    for (auto item : mItems)
    {
        item->Draw(dc);
    }
}

/**
 * Aquarium Constructor
 */
Aquarium::Aquarium()
{

    mBackground = make_unique<wxBitmap>(
            L"images/background1.png", wxBITMAP_TYPE_ANY);


}

/**
 * Add an item to the aquarium
 * @param item New item to add
 */
void Aquarium::Add(std::shared_ptr<Item> item)
{
    mItems.push_back(item);

}


/**
 * Test an x,y click location to see if it clicked
 * on some item in the aquarium.
 * @param x X location in pixels
 * @param y Y location in pixels
 * @returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<Item> Aquarium::HitTest(int x, int y)
{
    for (auto i = mItems.rbegin(); i != mItems.rend();  i++)
    {
        if ((*i)->HitTest(x, y))
        {
            return *i;
        }
    }

    return  nullptr;
}


/**
 *  Moves a selected item to the end of the list
 * @param item item to be moved
 */
void Aquarium::MovetoEnd(shared_ptr<Item> item)
{
    auto loc = find(begin(mItems), end(mItems), item);
    if (loc != end(mItems))
    {
        shared_ptr<Item> newItem = item;
        mItems.erase(loc);
        mItems.push_back(newItem);
    }
}

/**
 *  Called when a carp is moved, if the carp is near another fish, it will consume it
 * @param x X coord of carp being moved
 * @param y Y coord of carp being moved
 * @param imageWidth  width of carp image being moved
 * @param imageHeight height of carp image being moved
 */
void Aquarium::CarpKill(double x, double y, double imageWidth, double imageHeight)
{
    for (auto i = mItems.begin(); i != mItems.end()-1;  i++)
    {
        if ( (( abs((*i)->GetX()) - abs(x) ) < imageWidth) &&  ( abs((*i)->GetY()) - abs(y) ) < imageHeight )
        {
            auto loc = find(begin(mItems), end(mItems), *i);
            if (loc != end(mItems))
            {
                mItems.erase(loc);
                break;
            }
        }
    }
}