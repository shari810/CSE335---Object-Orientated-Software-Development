/**
 * @file DecorCastle.cpp
 * @author nick
 */

#include "DecorCastle.h"

#include "Aquarium.h"

#include <string>

using namespace std;

/// Fish filename
const wstring DecorCastleImageName = L"images/castle.png";

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
DecorCastle::DecorCastle(Aquarium *aquarium) : Item(aquarium, DecorCastleImageName)
{
}

/**
 * Save this item to an XML node
 * @param node The parent node we are going to be a child of
 * @return wxXmlNode that we saved the item into
 */
wxXmlNode* DecorCastle::XmlSave(wxXmlNode* node)
{
    auto itemNode = Item::XmlSave(node);

    itemNode->AddAttribute(L"type", L"castle");

    return itemNode;
}

/**
 * Load the attributes for an item node.
 *
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
 */
void DecorCastle::XmlLoad(wxXmlNode *node)
{

}