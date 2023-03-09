/**
 * @file Player.h
 * @author Zhendong Chen
 *
 * Class that describe the player
 */

#ifndef PROJECT1_PLAYER_H
#define PROJECT1_PLAYER_H

#include "Item.h"
#include <wx/graphics.h>

/**
 * Class that describe the player
 */
class Player : public Item{
private:
    /// The underlying player image
    std::shared_ptr<wxImage> mPlayerImage;

    /// The bitmap we can display for the player
    wxGraphicsBitmap mPlayerBitmap;

    /// The Width of the player
    int mPlayerWid;

    /// The Height of the player
    int mPlayerHit;

    /// File used to create image
    wxString mImageFileName;

public:
    /// Default constructor (disabled)
    Player() = delete;

    /// Copy constructor (disabled)
    Player(const Player &) = delete;

    /// Assignment operator
    void operator=(const Player &) = delete;

    Player(Game* game, wxString player);

    void Draw(wxGraphicsContext *graphics) override;

    /**
     * Getter to test if an image loaded
     * @return mImageFileName  filename of image
     */
    wxString GetImageFileName() const { return mImageFileName; }

    /**
     * The Width of the player
     * @return The Width of the player
     */
    int GetPlayerWid() const { return mPlayerWid; }

    /**
     * The Width of the player
     * @return The Width of the player
     */
    int GetPlayerHit() const { return mPlayerHit; }

    void SwapImageBob();

    void SwapImageSparty();

    void SwapImageVinnie();
    /**
     * Set the wxstring item name
     * @param name name of item
     */
    void SetName(wxString name) override {}
    /**
     * Set message to be displayed for bad UML
     * @param badMessage bad UML message
     */
    void SetBadMessage(wxString badMessage) override {}
    /**
     * Set boolean for a bad UML class
     * @param bad
     */
    void SetBad(bool bad) override {}
    /**
     * Set UML attributes
     * @param attributes attributes in UML class
     */
    void SetAttributes(std::vector<wxString> attributes) override {}
    /**
     * Set UML operations
     * @param operations operations in UML class
     */
    void SetOperations(std::vector<wxString> operations) override {}
    /**
     * Draw the text when UML destroyed
     */
    void DisplayDestroyedMessage() override {}
    /**
     * Set destroyed boolean flag for item
     * @param destroyed
     */
    void SetDestroyed(bool destroyed) override {}
    /**
     * Getter for mDestroyed
     * @return mDestroyed boolean
     */
    bool GetDestroyed() override {return false;}
    /**
     * Hit test (not used in player
     * @param x x-pos
     * @param y y-pos
     * @return boolean if item hit
     */
    bool HitTest(int x, int y) override {return false;}
    /**
    * Sets the items attribute to counted if it has been registered off screen.
    * @param counted
    */
    void SetCounted(bool counted) override {}
    /**
     * Double the mSpeed of an item
     */
    void DoubleSpeed() override {};
    /**
    * Half the mSpeed of an item
    */
    void HalfSpeed() override {};
};

#endif //PROJECT1_PLAYER_H
