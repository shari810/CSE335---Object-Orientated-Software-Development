/**
 * @file Fish.h
 * @author nicholas shari
 *
 *
 */

#ifndef AQUARIUM_FISH_H
#define AQUARIUM_FISH_H

#include "Item.h"
#include <random>



/**
 * Base class for a fish
 * This applies to all of the fish, but not the decor
 * items in the aquarium.
 */
class Fish : public Item {
private:

    /// Fish speed in the X direction
    /// in pixels per second
    double mSpeedX;

    /// Fish speed in the Y direction
    /// in pixels per second
    double mSpeedY;

    /// Random number generator
    std::mt19937 mRandom;

public:
    /// Default constructor (disabled)
    Fish() = delete;

    /// Copy constructor (disabled)
    Fish(const Fish &) = delete;

/// Assignment operator
    void operator=(const Fish &) = delete;

    void Update(double elapsed);

    /**
* Get the random number generator
* @return Pointer to the random number generator
*/
    std::mt19937 &GetRandom() {return mRandom;}

protected:
    Fish(Aquarium* aquarium, const std::wstring& filename);

};

#endif //AQUARIUM_FISH_H
