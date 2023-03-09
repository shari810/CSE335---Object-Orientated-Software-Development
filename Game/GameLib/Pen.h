/**
 * @file Pen.h
 * @author Zhendong Chen
 *
 * Class that describes a pen
 */

#ifndef PROJECT1_PEN_H
#define PROJECT1_PEN_H

#include "Item.h"
#include <wx/graphics.h>



/**
 * Class that describes a pen
 */
class Pen : public Item{
private:
    /// The underlying pen image
    std::shared_ptr<wxImage> mPenImage;

    /// The bitmap we can display for the pen
    wxGraphicsBitmap mPenBitmap;

    /// Pen speed in the X direction
    /// in pixels per second
    double mSpeedX = 1;

    /// Pen speed in the Y direction
    /// in pixels per second
    double mSpeedY = 1;

    /// The angle between the player and the mouse
    double mShootingAngle;

    /// The rotation angle before shooting the pen
    double mLastRotationAngle;


public:
    /// Default constructor (disabled)
    Pen() = delete;

    /// Copy constructor (disabled)
    Pen(const Pen &) = delete;

    /// Assignment operator
    void operator=(const Pen &) = delete;

    Pen(Game* game);

    void Draw(wxGraphicsContext *graphics) override;

    void Update(double elapsed) override;

    void SetSpeed(double xSpeed ,double ySpeed);
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

//    void PenDestroyer(std::shared_ptr<Item> item) override;


    bool HitTest(int x, int y) override;

    void SetLocation(double x, double y) override;
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


#endif //PROJECT1_PEN_H
