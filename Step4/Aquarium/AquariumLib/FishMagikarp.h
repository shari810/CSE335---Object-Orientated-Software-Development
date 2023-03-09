/**
 * @file FishMagikarp.h
 * @author nicholas shari
 *
 *
 */

#ifndef AQUARIUM_FISHMAGIKARP_H
#define AQUARIUM_FISHMAGIKARP_H

#include "Item.h"
#include "Fish.h"

/**
 * Magikarp fish class
 */
class FishMagikarp : public Fish {

private:


public:

/// Default constructor (disabled)
    FishMagikarp() = delete;

/// Copy constructor (disabled)
    FishMagikarp(const FishMagikarp &) = delete;

/// Assignment operator
    void operator=(const FishMagikarp &) = delete;

    FishMagikarp(Aquarium* aquarium);

    wxXmlNode* XmlSave(wxXmlNode* node) override;

    void XmlLoad(wxXmlNode* node) override;

};

#endif //AQUARIUM_FISHMAGIKARP_H
