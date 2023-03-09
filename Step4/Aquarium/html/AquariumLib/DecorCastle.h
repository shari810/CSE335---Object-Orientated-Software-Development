/**
 * @file DecorCastle.h
 * @author nick
 *
 *
 */


#ifndef AQUARIUM_DECORCASTLE_H
#define AQUARIUM_DECORCASTLE_H

#include "Item.h"

/**
 *
 * Decor castle class
 */
class DecorCastle : public Item{

private:

public:

    /// Default constructor (disabled)
    DecorCastle() = delete;

    /// Copy constructor (disabled)
    DecorCastle(const DecorCastle &) = delete;

    DecorCastle(Aquarium* aquarium);


/// Assignment operator
    void operator=(const DecorCastle &) = delete;


    wxXmlNode* XmlSave(wxXmlNode* node) override;

    void XmlLoad(wxXmlNode* node) override;

};

#endif //AQUARIUM_DECORCASTLE_H
