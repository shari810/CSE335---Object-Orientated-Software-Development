/**
 * @file Drawable.h
 * @author nicholas shari
 *
 * Abstract base class for drawable elements of our picture.
 */

#ifndef CANADIANEXPERIENCE_DRAWABLE_H
#define CANADIANEXPERIENCE_DRAWABLE_H


#include <string>
#include <memory>

class Actor;


/**
 * Abstract base class for drawable elements of our picture.
 *
 * A drawable is one part of an actor. Drawable parts can be moved
 * independently.
 */
class Drawable {
private:
    /// The position of this drawable relative to its parent
    wxPoint mPosition = wxPoint(0, 0);
    /// The drawable name
    std::wstring mName;
    /// The rotation of this drawable relative to its parent
    double mRotation = 0;

    /// The actor using this drawable
    Actor *mActor = nullptr;

    /// Parent node of the drawable
    Drawable *mParent = nullptr;
    /// Drawable children nodes
    std::vector<std::shared_ptr<Drawable>> mChildren;


public:

    /// Default constructor (disabled)
    Drawable() = delete;

    /// Copy constructor (disabled)
    Drawable(const Drawable &) = delete;

    /// Assignment operator
    void operator=(const Drawable &) = delete;

    virtual ~Drawable();

    void SetActor(Actor* actor);

    /**
     * Draw this drawable
     * @param graphics Graphics object to draw on
     */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) = 0;

    void Place(wxPoint offset, double rotate);

    void AddChild(std::shared_ptr<Drawable> child);

    /**
     * Test to see if we have been clicked on by the mouse
     * @param pos Position to test
     * @return true if clicked on
     */
    virtual bool HitTest(wxPoint pos) = 0;
    /**
     * Is this a movable drawable?
     * @return true if movable
     */
    virtual bool IsMovable() {return false;}

    void Move(wxPoint delta);

    /**
     * Set the drawable position
     * @param pos The new drawable position
     */
    void SetPosition(wxPoint pos) { mPosition = pos; }

    /**
     * Get the drawable position
     * @return The drawable position
     */
    wxPoint GetPosition() const { return mPosition; }

    /**
     * Set the rotation angle in radians
    * @param r The new rotation angle in radians
     */
    void SetRotation(double r) { mRotation = r; }

    /**
     * Get the rotation angle in radians
     * @return The rotation angle in radians
     */
    double GetRotation() const { return mRotation; }

    /**
     * Get the drawable name
     * @return The drawable name
     */
    std::wstring GetName() const { return mName; }

    /**
     * Get the parent
     * @return mParent
     */
    Drawable* GetParent() const {return mParent;}

    /**
     * Set the parent the child node is attached to
     * @param parent
     */
    void SetParent(Drawable *parent) {mParent = parent;}


protected:
    /// position the drawable is place at
    wxPoint mPlacedPosition = wxPoint(0,0);

    wxPoint RotatePoint(wxPoint point, double angle);

    /// rotational factor
    double mPlacedR = 0;

    Drawable(const std::wstring& name);


};

#endif //CANADIANEXPERIENCE_DRAWABLE_H
