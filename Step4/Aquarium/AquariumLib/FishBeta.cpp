/**
 * @file FishBeta.cpp
 * @author nicholas shari
 */

#include "pch.h"
#include "FishBeta.h"
#include "Aquarium.h"

#include <string>

using namespace std;

/// Fish filename
const wstring FishBetaImageName = L"images/beta.png";

/**
 * Constructor
 * @param aquarium Aquarium this fish is a member of
 */
FishBeta::FishBeta(Aquarium *aquarium) : Fish(aquarium, FishBetaImageName)
{
}

/**
 * Save this fish to an XML node
 * @param node The parent node we are going to be a child of
 * @return
 */
wxXmlNode* FishBeta::XmlSave(wxXmlNode* node)
{
    auto itemNode = Item::XmlSave(node);

    itemNode->AddAttribute(L"type", L"beta");


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
void FishBeta::XmlLoad(wxXmlNode *node)
{

}


