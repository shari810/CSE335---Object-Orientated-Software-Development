/**
 * @file FishBubbles.h
 * @author nicholas shari
 *
 *
 */

#ifndef AQUARIUM_FISHBUBBLES_H
#define AQUARIUM_FISHBUBBLES_H

#include "Item.h"
#include "Fish.h"

/**
 * Bubbles fish class
 */
class FishBubbles : public Fish {
        private:


        public:

        /// Default constructor (disabled)
        FishBubbles() = delete;

        /// Copy constructor (disabled)
        FishBubbles(const FishBubbles &) = delete;

/// Assignment operator
        void operator=(const FishBubbles &) = delete;

        FishBubbles(Aquarium* aquarium);

        wxXmlNode* XmlSave(wxXmlNode* node) override;

        void XmlLoad(wxXmlNode* node) override;
};

#endif //AQUARIUM_FISHBUBBLES_H
