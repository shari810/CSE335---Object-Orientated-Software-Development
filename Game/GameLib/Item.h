/**
 * @file Item.h
 * @author Zhendong Chen
 *
 * Base class for any item in the game.
 */

#ifndef PROJECT1_ITEM_H
#define PROJECT1_ITEM_H

#include <wx/graphics.h>

class Game;

/**
 * Base class for any item in the game.
 */
class Item {
protected:
    Item(Game* game);

private:
    /// The game the item is contained in
    Game* mGame;

    double mX = 0; ///< X location for the center of the item
    double mY = 0; ///< Y location for the center of the item

     /// The image for this item
    std::shared_ptr<wxImage> mItemImage;

      /// The bitmap for this item
    wxGraphicsBitmap mItemBitmap;

//    Will also need the item bitmap.


public:
    virtual ~Item();

    /**
     * The X location of the item
     * @return X location in pixels
     */
    double GetX() const { return mX; }

    /**
     * The Y location of the item
     * @return Y location in pixels
     */
    double GetY() const { return mY; }

    /**
     * Set the item location
     * @param x X location in pixels
     * @param y Y location in pixels
     */
    virtual void SetLocation(double x, double y)
    {
        mX = x;
        mY = y;
    }

    /// Default constructor (disabled)
    Item() = delete;

    /// Copy constructor (disabled)
    Item(const Item&) = delete;

    /// Assignment operator
    void operator=(const Item&) = delete;

    /**
     * Draw function
     * @param graphics the graphic reference
     */
    virtual void Draw(wxGraphicsContext* graphics) = 0;

    /**
     * Handle updates for animation
     * @param elapsed The time since the last update
     */
    virtual void Update(double elapsed) { }

    /**
     * Get the pointer to the Game object
     * @return Pointer to Game object
     */
    Game* GetGame() { return mGame; }

    /**
     * Item hit test
     * @param x x-pos
     * @param y y-pos
     * @return boolean if hit
     */
    virtual bool HitTest(int x, int y) = 0;
    /**
     * Set the wxstring item name
     * @param name name of item
     */
    virtual void SetName(wxString name) = 0;
    /**
     * Set message to be displayed for bad UML
     * @param badMessage bad UML message
     */
    virtual void SetBadMessage(wxString badMessage) = 0;
    /**
     * Set boolean for a bad UML class
     * @param bad
     */
    virtual void SetBad(bool bad) = 0;
    /**
     * Set UML attributes
     * @param attributes attributes in UML class
     */
    virtual void SetAttributes(std::vector<wxString> attributes) = 0;
    /**
     * Set UML operations
     * @param operations operations in UML class
     */
    virtual void SetOperations(std::vector<wxString> operations) = 0;
    /**
     * Draw the text when UML destroyed
     */
    virtual void DisplayDestroyedMessage() = 0;
    /**
     * Set destroyed boolean flag for item
     * @param destroyed
     */
    virtual void SetDestroyed(bool destroyed) = 0;
    /**
     * Getter for mDestroyed
     * @return mDestroyed boolean
     */
    virtual bool GetDestroyed() = 0;

    /**
    * Sets the items attribute to counted if it has been registered off screen.
    * @param counted
    */
    virtual void SetCounted(bool counted) = 0;
    /**
     * Returns the UMLs counted
     * @return mCounted representing if the UML was registered as off screen.
     */
    virtual bool GetCounted() const {return false;}

//    virtual void PenDestroyer(std::shared_ptr<Item> item) = 0;
    /**
     * Get item pixel width
     * @return mWidth of item
     */
    virtual double GetWid() {return 0; }
    /**
     * getter for item pixel height
     * @return mHeight of item
     */
    virtual double GetHeight() {return 0; }
    /**
     * get mBad boolean for item(UML)
     * @return mBad
     */
    virtual bool GetBad() const {return false;}
    /**
     * Double the mSpeed of an item
     */
    virtual void DoubleSpeed() = 0;
    /**
     * Half the mSpeed of an item
     */
    virtual void HalfSpeed() = 0;
};

#endif //PROJECT1_ITEM_H
