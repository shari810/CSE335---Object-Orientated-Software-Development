/**
 * @file Aquarium.h
 * @author nicholas shari
 *
 * Display an aquarium
 */

#ifndef AQUARIUM_AQUARIUM_H
#define AQUARIUM_AQUARIUM_H

#include<memory>

class Item;

/**
 * Aquarium class to display the image of an aquarium.
 */
class Aquarium {
private:

    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use
    /// All of the items to populate our aquarium
    std::vector<std::shared_ptr<Item>> mItems;
public:

    void OnDraw(wxDC* dc);

    Aquarium();

    void Add(std::shared_ptr<Item> item);

    std::shared_ptr<Item> HitTest(int x, int y);

    void MovetoEnd(std::shared_ptr<Item> item);

    void CarpKill(double x, double y, double imageWidth, double imageHeight);
};

#endif //AQUARIUM_AQUARIUM_H
