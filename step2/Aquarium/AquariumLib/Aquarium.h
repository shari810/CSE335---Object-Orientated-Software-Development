/**
 * @file Aquarium.h
 * @author nicholas shari
 *
 * Display an aquarium
 */

#ifndef AQUARIUM_AQUARIUM_H
#define AQUARIUM_AQUARIUM_H

#include<memory>

/**
 * Aquarium class to display the image of an aquarium.
 */
class Aquarium {
private:

    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use

public:

    void OnDraw(wxDC* dc);

    Aquarium();
};

#endif //AQUARIUM_AQUARIUM_H
