/**
 * @file Item.cpp
 * @author Zhendong Chen
 */

#include "pch.h"
#include "Item.h"
#include "Game.h"

/**
 * Destructor
 */
Item::~Item()
{

}

/**
 * Constructor
 * @param game The game this item is a member of
 *
 */
Item::Item(Game* game)
        :mGame(game)
{

}
