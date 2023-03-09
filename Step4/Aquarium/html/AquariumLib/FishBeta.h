/**
 * @file FishBeta.h
 * @author nicholas shari
 *
 *
 */

#ifndef AQUARIUM_FISHBETA_H
#define AQUARIUM_FISHBETA_H

#include "Item.h"
#include "Fish.h"

/**
 *
 * Beta fish class
 */
class FishBeta : public Fish {
private:


public:

    /// Default constructor (disabled)
    FishBeta() = delete;

    /// Copy constructor (disabled)
    FishBeta(const FishBeta &) = delete;

    FishBeta(Aquarium* aquarium);


/// Assignment operator
    void operator=(const FishBeta &) = delete;


    wxXmlNode* XmlSave(wxXmlNode* node) override;

    void XmlLoad(wxXmlNode* node) override;

};

#endif //AQUARIUM_FISHBETA_H
