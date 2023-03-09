/**
 * @file FishKillerCarp.h
 * @author nicholas shari
 *
 *
 */

#ifndef AQUARIUM_FISHKILLERCARP_H
#define AQUARIUM_FISHKILLERCARP_H

#include "Item.h"

/**
 * Killer fish class
 */
class FishKillerCarp : public Item {
private:
/// The underlying fish image
    std::unique_ptr<wxImage> mFishImage;

/// The bitmap we can display for this fish
    std::unique_ptr<wxBitmap> mFishBitmap;

public:

/// Default constructor (disabled)
    FishKillerCarp() = delete;

/// Copy constructor (disabled)
    FishKillerCarp(const FishKillerCarp &) = delete;

/// Assignment operator
    void operator=(const FishKillerCarp &) = delete;

    FishKillerCarp(Aquarium* aquarium);

    void Draw(wxDC* dc) override;

    bool HitTest(int x, int y) override;


    void EatCheck() override ;
};

#endif //AQUARIUM_FISHKILLERCARP_H
