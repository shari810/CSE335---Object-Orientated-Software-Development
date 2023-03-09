/**
 * @file Fish.cpp
 * @author nicholas shari
 */

#include "Fish.h"
#include "Aquarium.h"

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 150;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedX = 20;

/// Maximum speed in the Y direction in
/// in pixels per second
const double MaxSpeedY = 150;

/// Minimum speed in the Y direction in
/// pixels per second
const double MinSpeedY = 20;


/**
 * Constructor
 * @param aquarium The aquarium we are in
 * @param filename Filename for the image we use
 */
Fish::Fish(Aquarium *aquarium, const std::wstring &filename) :
        Item(aquarium, filename)
{
    std::uniform_real_distribution<> distribution(MinSpeedX, MaxSpeedX);
    mSpeedX = distribution(aquarium->GetRandom());
    mSpeedY = distribution(aquarium->GetRandom());
}

/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * @param elapsed Time elapsed since the class call
 */
void Fish::Update(double elapsed)
{
    SetLocation(GetX() + mSpeedX * elapsed,
            GetY() + mSpeedY * elapsed);

    std::uniform_real_distribution<> distribution(MinSpeedX, MaxSpeedX);


    if (mSpeedX > 0 && GetX() >= GetAquarium()->GetWidth())
    {
        mSpeedX = -mSpeedX;
        SetMirror(true);
    }

    if (mSpeedX < 0 && GetX() <= (0 + 10 + (this->GetWidth()/2) ) )
    {
        mSpeedX = -mSpeedX;
        SetMirror(false);
    }

    if (mSpeedY > 0 && GetY() >= GetAquarium()->GetHeight())
    {
        mSpeedY = -mSpeedY;
    }

    if (mSpeedY < 0 && GetY() <= (0 + 10 + (this->GetWidth()/2) ) )
    {
        mSpeedY = -mSpeedY;
    }



    if (mSpeedX < 0)
    {
        mSpeedX = (-1)*distribution(this->GetRandom());
    }
    else
    {
        mSpeedX = distribution(this->GetRandom());
    }
    if (mSpeedY < 0)
    {
        mSpeedY = (-1)*distribution(this->GetRandom());
    }
    else
    {
        mSpeedY = distribution(this->GetRandom());
    }

}