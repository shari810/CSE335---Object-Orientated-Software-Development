/**
 * @file Player.cpp
 * @author Zhendong Chen
 */

#include "pch.h"
#include "Player.h"
#include "Game.h"

using namespace std;


/**
 * Constructor
 *
 * @param game The game that the player is in
 * @param player Thr image path of the player image
 */
Player::Player(Game *game, wxString player) : Item(game)
{
    mImageFileName = player;
    mPlayerImage = std::make_shared<wxImage>(player);
    mPlayerWid = mPlayerImage->GetWidth();
    mPlayerHit = mPlayerImage->GetHeight();
}

/**
 * Draw the player
 *
 * @param graphics graphics context
 */
void Player::Draw(wxGraphicsContext *graphics)
{
    if(mPlayerBitmap.IsNull())
    {
        mPlayerBitmap = graphics->CreateBitmapFromImage(*mPlayerImage);
    }

    graphics->PushState();  // Save the graphics state
    graphics->Translate(GetX(), GetY());
    if(GetGame()->GetPx() != -1 && GetGame()->GetPy() != -1)
    {
        graphics->Rotate(atan2(GetGame()->GetPy()-this->GetY(), GetGame()->GetPx()-this->GetX())+atan2(sqrt(3)-0, 1-0));
    }
    graphics->DrawBitmap(mPlayerBitmap, -mPlayerWid/2, -mPlayerHit/2, mPlayerWid, mPlayerHit);
    graphics->PopState();

}

/**
 * Changes the player image to Spongebob
 */
void Player::SwapImageBob()
{
    mImageFileName = (L"images/bob.png");
    mPlayerImage = std::make_shared<wxImage>(L"images/bob.png");
    mPlayerWid = mPlayerImage->GetWidth();
    mPlayerHit = mPlayerImage->GetHeight();
}
/**
 * Changes the player image to Sparty
 */
void Player::SwapImageSparty()
{
    mImageFileName = (L"images/sparty.png");
    mPlayerImage = std::make_shared<wxImage>(L"images/sparty.png");
    mPlayerWid = mPlayerImage->GetWidth();
    mPlayerHit = mPlayerImage->GetHeight();
}

/**
 * Changes the player image to Vinnie
 */
void Player::SwapImageVinnie()
{
    mImageFileName = (L"images/vinnie.png");
    mPlayerImage = std::make_shared<wxImage>(L"images/vinnie.png");
    mPlayerWid = mPlayerImage->GetWidth();
    mPlayerHit = mPlayerImage->GetHeight();


}