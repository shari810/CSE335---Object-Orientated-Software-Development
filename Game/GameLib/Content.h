/**
 * @file Content.h
 * @author Tate Moorhouse
 *
 * Class to store the content of the xml file
 */

#ifndef PROJECT1_CONTENT_H
#define PROJECT1_CONTENT_H


#include <wx/xml/xml.h>

/**
 * Class that contains the UML data and attributes from the XML file.
 */
class Content {
private:
    /// The good names available
    std::vector<wxString> mGoodNames;
    /// The bad names available
    std::vector<std::vector<wxString>> mBadNames;
    /// The good attributes available
    std::vector<wxString> mGoodAttributes;
    /// The bad attributes available
    std::vector<std::vector<wxString>> mBadAttributes;
    /// The good operations available
    std::vector<wxString> mGoodOperations;
    /// The bad operations available
    std::vector<std::vector<wxString>> mBadOperations;

public:
    /**
     *  Adds a good name from the xml to the contents of the game
     *  @param theNode the Xml node to add
     */
    void AddGoodName(wxString theNode) {mGoodNames.push_back(theNode);}

    /**
     *  Adds a bad name from the xml to the contents of the game
     *  @param theNode the Xml node to add
     */
    void AddBadName(std::vector<wxString> theNode) {mBadNames.push_back(theNode);}

    /**
     *  Adds a good attribute from the xml to the contents of the game
     *  @param theNode the Xml node to add
     */
    void AddGoodAttribute(wxString theNode) {mGoodAttributes.push_back(theNode);}

    /**
     *  Adds a bad attribute from the xml to the contents of the game
     *  @param theNode the Xml node to add
     */
    void AddBadAttribute(std::vector<wxString> theNode) {mBadAttributes.push_back(theNode);}

    /**
     *  Adds a bad operation from the xml to the contents of the game
     *  @param theNode the Xml node to add
     */
    void AddBadOperations(std::vector<wxString> theNode) {mBadOperations.push_back(theNode);}

    /**
     *  Adds a good operation from the xml to the contents of the game
     *  @param theNode the Xml node to add
     */
    void AddGoodOperations(wxString theNode) {mGoodOperations.push_back(theNode);}

    /**
     * Gets the list of good names
     * @return the list of good names
     */
    std::vector<wxString> GetGoodNames() {return mGoodNames;}

    /**
     * Gets the list of bad names
     * @return the list of bad names
     */
    std::vector<std::vector<wxString>> GetBadNames() {return mBadNames;}

    /**
     * Gets the list of good attributes
     * @return the list of good attributes
     */
    std::vector<wxString> GetGoodAttributes() {return mGoodAttributes;}

    /**
     * Gets the list of bad attributes
     * @return the list of bad attributes
     */
    std::vector<std::vector<wxString>> GetBadAttributes() {return mBadAttributes;}

    /**
     * Gets the list of good operations
     * @return the list of good operations
     */
    std::vector<wxString> GetGoodOperations() {return mGoodOperations;}

    /**
     * Gets the list of bad operations
     * @return the list of bad operations
     */
    std::vector<std::vector<wxString>> GetBadOperations() {return mBadOperations;}
};


#endif //PROJECT1_CONTENT_H
