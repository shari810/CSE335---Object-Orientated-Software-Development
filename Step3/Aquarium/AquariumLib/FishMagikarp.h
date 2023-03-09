/**
 * @file FishMagikarp.h
 * @author nicholas shari
 *
 *
 */

#ifndef AQUARIUM_FISHMAGIKARP_H
#define AQUARIUM_FISHMAGIKARP_H

#include "Item.h"


/**
 * Magikarp fish class
 */
class FishMagikarp : public Item {

private:
/// The underlying fish image
    std::unique_ptr<wxImage> mFishImage;

/// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mFishBitmap;

public:

/// Default constructor (disabled)
    FishMagikarp() = delete;

/// Copy constructor (disabled)
    FishMagikarp(const FishMagikarp &) = delete;

/// Assignment operator
    void operator=(const FishMagikarp &) = delete;

    FishMagikarp(Aquarium* aquarium);

    void Draw(wxDC* dc) override;

    bool HitTest(int x, int y) override;

    /**
    *  Does nothing
    */
    void EatCheck() override {};
};

#endif //AQUARIUM_FISHMAGIKARP_H
