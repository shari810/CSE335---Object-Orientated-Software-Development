/**
 * @file Uml.cpp
 * @author Tate Moorhouse
 */

#include "pch.h"
#include "Uml.h"


/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 30;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedX = -30;


/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedY = 50;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedY = 30;

/**
 * Constructor
 * @param game Game this uml is a member of
 */
Uml::Uml(Game *game) : Item(game)
{
    std::uniform_real_distribution<> distribution(MinSpeedX, MaxSpeedX);
    mSpeedX = distribution(game->GetRandom());
    std::uniform_real_distribution<> distribution1(MinSpeedY, MaxSpeedY);
    mSpeedY = distribution1(game->GetRandom());
}

/**
 * Draw function for uml
 * @param graphics the graphic reference
 */
void Uml::Draw(wxGraphicsContext *graphics)
{

    double boxLeft = this->GetX();
    double boxTop = this->GetY();
    double boxHeight = 0;
    double boxWidth = 0;

    //
    // Draw Name
    //
    wxFont fontName(wxSize(0, 25),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    graphics->SetFont(fontName, wxColour(0, 0, 0));
    double widName, hitName;
    graphics->GetTextExtent(mName, &widName, &hitName);
    if (mName == L""){
        boxHeight += 20;
    }
    else{
        // increase box height
        boxHeight += hitName;
    }

    // if the width of name > width of box update width of box
    if (widName > boxWidth){
        boxWidth = widName;
    }

    double widOther, hitOther;
    wxFont fontOther(wxSize(0, 20),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
    graphics->SetFont(fontOther, wxColour(0, 0, 0));
    // loop over each of the attributes to get size
    if (mAttributes.size() != 0){
        for(wxString attribute : mAttributes) {
            graphics->GetTextExtent(attribute, &widOther, &hitOther);
            boxHeight += hitOther;
            if (widOther > boxWidth) {
                boxWidth = (widOther + 5);
            }
        }
    }
    // loop over operations
    if (mOperations.size() != 0){
        for (wxString operation : mOperations){
            graphics->GetTextExtent(operation, &widOther, &hitOther);
            boxHeight += hitOther;
            if (widOther > boxWidth){
                boxWidth = (widOther + 5);
            }
        }
    }
    if (mAttributes.size()== 0 && mOperations.size() == 0){
        boxHeight += 20;
        boxWidth += 20;
    }

    boxHeight += 30;

    //
    // Draw a filled rectangle
    //
    wxPen linePen(wxColour(0,0,0), 2);   // 3 pixel wide line
    wxBrush rectBrush(wxColour(255, 255, 193));
    graphics->SetBrush(rectBrush);
    graphics->SetPen(linePen);
    graphics->DrawRectangle(boxLeft, boxTop, boxWidth + 4, boxHeight + 5);

    // Draw the Name
    graphics->SetFont(fontName, wxColour(0, 0, 0));
    graphics->DrawText(mName, boxLeft + ((boxWidth + 4) - widName) / 2, boxTop + 5);

    graphics->SetFont(fontOther, wxColour(0, 0, 0));
    double newHeight = hitName + boxTop + 5;
    if (mName == L""){
        newHeight += 20;
    }

    // draw line separating Name and other
    graphics->SetPen(linePen);
    graphics->StrokeLine(boxLeft, newHeight, boxLeft + boxWidth + 4, newHeight);

    // loop over each of the attributes to print
    if (mAttributes.size() != 0){
        for(wxString attribute : mAttributes) {
            graphics->GetTextExtent(attribute, &widOther, &hitOther);
            graphics->DrawText(attribute, boxLeft + 4, newHeight + 5);
            newHeight = hitOther + newHeight + 5;
        }
    }
    // loop over each of the attributes to print
    if (mOperations.size() != 0){
        graphics->StrokeLine(boxLeft, newHeight + 2, boxLeft + boxWidth + 4, newHeight + 2);
        for(wxString operation : mOperations) {
            graphics->GetTextExtent(operation, &widOther, &hitOther);
            graphics->DrawText(operation, boxLeft + 4, newHeight + 5);
            newHeight = hitOther + newHeight + 5;
        }
    }
    if (mDestroyed && this->GetBad())
    {
        wxFont fontMessage(wxSize(0, 45),
                        wxFONTFAMILY_SWISS,
                        wxFONTSTYLE_NORMAL,
                        wxFONTWEIGHT_NORMAL);

        graphics->SetFont(fontMessage, wxColour(0, 210, 0));

        double wid, hit;
        graphics->GetTextExtent(L"Centered Text", &wid, &hit);
//        graphics->DrawText(mBadMessage, boxWidth/2 - wid/2, boxHeight - hit/2);
        graphics->DrawText(mBadMessage, boxLeft, boxTop + (boxHeight / 2));
    }
    else if (mDestroyed){
        wxFont fontMessage(wxSize(0, 45),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);

        graphics->SetFont(fontMessage, wxColour(255, 0, 0));

        double wid, hit;
        graphics->GetTextExtent(L"Centered Text", &wid, &hit);
        graphics->DrawText(mBadMessage, boxLeft, boxTop + (boxHeight / 2));
    }
    mBoxWid = boxWidth + 4;
    mBoxHit = boxHeight + 5;

}


/**
 * Test to see if we hit this object with the pen.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool Uml::HitTest(int x, int y)
{
    if(x > this->GetX() && x < GetX()+mBoxWid && y > GetY() && y < GetY()+mBoxHit)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Handle pausing and displaying of message after
 * Uml is destroyed
 */
void Uml::DisplayDestroyedMessage()
{
    mDestroyed = true;

    this->mSpeedX = 0;
    this->mSpeedY = 0;
}

/**
 * Update the location of the UML
 * @param elapsed Time elapsed since the class call
 */
void Uml::Update(double elapsed)
{
    SetLocation(GetX() + mSpeedX * elapsed,
            GetY() + mSpeedY * elapsed);
//    SetLocation(GetX() + mSpeedX * 0.05,
//            GetY() + mSpeedY * 0.05);
}