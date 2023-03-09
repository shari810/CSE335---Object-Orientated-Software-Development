/**
 * @file FishBubbles.h
 * @author nicholas shari
 *
 *
 */

#ifndef AQUARIUM_FISHBUBBLES_H
#define AQUARIUM_FISHBUBBLES_H

#include "Item.h"

/**
 * Bubbles fish class
 */
class FishBubbles : public Item {
        private:
        /// The underlying fish image
        std::unique_ptr<wxImage> mFishImage;

        /// The bitmap we can display for this fish
        std::unique_ptr<wxBitmap> mFishBitmap;

        public:

        /// Default constructor (disabled)
        FishBubbles() = delete;

        /// Copy constructor (disabled)
        FishBubbles(const FishBubbles &) = delete;

/// Assignment operator
        void operator=(const FishBubbles &) = delete;

        FishBubbles(Aquarium* aquarium);

        void Draw(wxDC* dc) override;

        bool HitTest(int x, int y) override;

    /**
    *  Does nothing
    */
        void EatCheck() override {};

};

#endif //AQUARIUM_FISHBUBBLES_H
