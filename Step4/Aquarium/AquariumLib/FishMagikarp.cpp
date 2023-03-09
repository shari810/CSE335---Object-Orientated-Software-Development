/**
 * @file FishMagikarp.cpp
 * @author nicholas shari
 */

#include "pch.h"
#include "FishMagikarp.h"

#include "Aquarium.h"

#include <string>

using namespace std;

/// Fish filename
const wstring FishMagikarpImageName = L"images/magikarp.png";



/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
FishMagikarp::FishMagikarp(Aquarium *aquarium) : Fish(aquarium, FishMagikarpImageName)
{
}

/**
 * Save this item to an XML node
 * @param node The parent node we are going to be a child of
 * @return wxXmlNode that we saved the item into
 */
wxXmlNode* FishMagikarp::XmlSave(wxXmlNode* node)
{
    auto itemNode = Item::XmlSave(node);

    itemNode->AddAttribute(L"type", L"magikarp");

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
void FishMagikarp::XmlLoad(wxXmlNode *node)
{

}