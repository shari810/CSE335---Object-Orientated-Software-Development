/**
 * @file Pen.cpp
 * @author Zhendong Chen
 */

#include "pch.h"
#include "Pen.h"
#include "Game.h"

using namespace std;

/**
 * Constructor
 *
 * @param game The game that the pen is in
 */
Pen::Pen(Game *game) : Item(game)
{
    mPenImage = std::make_shared<wxImage>(L"images/redpen.png");
}

/**
 * Draw the pen
 *
 * @param graphics graphics context
 */
void Pen::Draw(wxGraphicsContext *graphics)
{
    if(mPenBitmap.IsNull())
    {
        mPenBitmap = graphics->CreateBitmapFromImage(*mPenImage);
    }

    int PenWid = mPenImage->GetWidth();
    int PenHit = mPenImage->GetHeight();

    int PlayerWid = GetGame()->GetPlayer()->GetPlayerWid();
    int PlayerHit = GetGame()->GetPlayer()->GetPlayerHit();

    if(GetGame()->IsClicked() == false)
    {
        graphics->PushState();  // Save the graphics state
        graphics->Translate(GetX(), GetY());
        mShootingAngle = atan2(GetGame()->GetPy()-GetY(), GetGame()->GetPx()-GetX());
        if(GetGame()->GetPx() == -1 && GetGame()->GetPy() == -1)
        {
            graphics->Rotate(atan2(sqrt(3)-0, 1-0));
            graphics->DrawBitmap(mPenBitmap, -PlayerWid/2-20, -PlayerHit/2+20, PenWid, PenHit);
        }
        else
        {
            mLastRotationAngle = atan2(GetGame()->GetPy()-GetY(), GetGame()->GetPx()-GetX())+atan2(sqrt(3)-0, -1-0);
            graphics->Rotate(mLastRotationAngle);
            graphics->DrawBitmap(mPenBitmap, -PlayerWid/2-20, -PlayerHit/2+20, PenWid, PenHit);
        }

        graphics->PopState();
    }
    if(GetGame()->IsClicked() == true)
    {
        SetSpeed(900*cos(mShootingAngle),900*sin(mShootingAngle));
        graphics->PushState();
        graphics->Translate(GetX(), GetY());
        graphics->Rotate(mLastRotationAngle);
        graphics->DrawBitmap(mPenBitmap, -PlayerWid/2-20, -PlayerHit/2+20, PenWid, PenHit);
        graphics->PopState();
    }

}


/**
 * Update the location of Pen
 * @param elapsed Time elapsed since the class call
 */
void Pen::Update(double elapsed)
{
    SetLocation(GetX() + mSpeedX * elapsed,
            GetY() + mSpeedY * elapsed);

}

/**
 * set location for pen
 * @param x the x coordinate of the pen
 * @param y the y coordinate of the pen
 */
void Pen::SetLocation(double x, double y) {
    Item::SetLocation(x,y);

//    GetGame()->UmlDestroyer(this);
//    while(GetGame()->UmlDestroyer(this)){
//    }
}

/**
 * A setter to set the speed of x and y
 *
 * @param xSpeed The speed of x
 * @param ySpeed The speed of y
 */
void Pen::SetSpeed(double xSpeed ,double ySpeed)
{
    mSpeedX = xSpeed;
    mSpeedY = ySpeed;
}

/**
 * Test to see if we hit this object with the pen.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool Pen::HitTest(int x, int y)
{
    double wid = mPenImage->GetWidth();
    double hit = mPenImage->GetHeight();

    // Make x and y relative to the top-left corner of the bitmap image
    // Subtracting the center makes x, y relative to the image center
    // Adding half the size makes x, y relative to the image top corner
    double testX = x - GetX() + wid / 2;
    double testY = y - GetY() + hit / 2;

    // Test to see if x, y are in the image
    if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
    {
        // We are outside the image
        return false;
    }

    // Test to see if x, y are in the drawn part of the image
    // If the location is transparent, we are not in the drawn
    // part of the image
    return !mPenImage->IsTransparent((int)testX, (int)testY);
}