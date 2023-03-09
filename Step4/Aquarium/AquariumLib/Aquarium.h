/**
 * @file Aquarium.h
 * @author nicholas shari
 *
 * Display an aquarium
 */

#ifndef AQUARIUM_AQUARIUM_H
#define AQUARIUM_AQUARIUM_H

#include<memory>
#include <random>

class Item;

/**
 * Aquarium class to display the image of an aquarium.
 */
class Aquarium {
private:

    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use
    /// All of the items to populate our aquarium
    std::vector<std::shared_ptr<Item>> mItems;

    /// Random number generator
    std::mt19937 mRandom;

    void XmlItem(wxXmlNode* node);

public:

    void OnDraw(wxDC* dc);

    Aquarium();

    void Add(std::shared_ptr<Item> item);

    std::shared_ptr<Item> HitTest(int x, int y);

    void MovetoEnd(std::shared_ptr<Item> item);

    void CarpKill(double x, double y, double imageWidth, double imageHeight);

    void Save(const wxString& filename);

    void Load(const wxString& filename);

    void Clear();

    void Update(double elapsed);

    /**
    * Get the random number generator
    * @return Pointer to the random number generator
    */
    std::mt19937 &GetRandom() {return mRandom;}

    /**
 * Get the width of the aquarium
 * @return Aquarium width in pixels
 */
    int GetWidth() const { return mBackground->GetWidth(); }

    /**
     * Get the height of the aquarium
     * @return Aquarium height in pixels
     */
    int GetHeight() const { return mBackground->GetHeight(); }
};

#endif //AQUARIUM_AQUARIUM_H
