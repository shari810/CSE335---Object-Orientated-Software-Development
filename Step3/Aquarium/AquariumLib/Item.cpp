/**
 * @file Item.cpp
 * @author nick
 */

#include "Item.h"
#include "Aquarium.h"

/**
 * Destructor
 */
Item::~Item()
{

}

/**
 * Constructor
 * @param aquarium The aquarium this item is a member of
 */
Item::Item(Aquarium *aquarium) : mAquarium(aquarium)
{
}