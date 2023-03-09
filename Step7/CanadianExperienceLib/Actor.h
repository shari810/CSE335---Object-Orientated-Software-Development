/**
 * @file Actor.h
 * @author nicholas shari
 *
 *  Class for actors in our drawings.
 */

#ifndef CANADIANEXPERIENCE_ACTOR_H
#define CANADIANEXPERIENCE_ACTOR_H

#include <string>
#include <memory>
#include "Drawable.h"


class Drawable;
class Picture;

/**
 * Class for actors in our drawings.
 *
 * An actor is some graphical object that consists of
 * one or more parts. Actors can be animated.
 */
class Actor {

private:
    /// The actor name
    std::wstring mName;

    /// Is this actor enabled (drawable)?
    bool mEnabled = true;

    /// The actor position
    wxPoint mPosition;

    /// Is this actor mouse clickable?
    bool mClickable = true;

    /// The root drawable
    std::shared_ptr<Drawable> mRoot;

    /// The drawables in drawing order
    std::vector<std::shared_ptr<Drawable>> mDrawablesInOrder;

    ///Picture containing the actor
    Picture *mPicture = nullptr;

public:

    virtual ~Actor();

    /// Default constructor (disabled)
    Actor() = delete;

    /// Copy constructor (disabled)
    Actor(const Actor &) = delete;

    /// Assignment operator
    void operator=(const Actor &) = delete;

    Actor(const std::wstring &name);

    void SetRoot(std::shared_ptr<Drawable> root);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    std::shared_ptr<Drawable> HitTest(wxPoint pos);

    void AddDrawable(std::shared_ptr<Drawable> drawable);

    /**
     * Get the actor name
     * @return Actor name
     */
    std::wstring GetName() const { return mName; }

    /**
     * The actor position
     * @return The actor position as a point
     */
    wxPoint GetPosition() const { return mPosition; }

    /**
     * The actor position
     * @param pos The new actor position
     */
    void SetPosition(wxPoint pos) { mPosition = pos; }


    /**
     * Actor is enabled
     * @return enabled status
     */
    bool IsEnabled() const { return mEnabled; }

    /**
     * Set Actor Enabled
     * @param enabled New enabled status
     */
    void SetEnabled(bool enabled) { mEnabled = enabled; }

    /**
     * Actor is clickable
     * @return true if actor is clickable
     */
    bool IsClickable() const { return mClickable; }

    /**
     * Actor clickable
     * @param clickable New clickable status
     */
    void SetClickable(bool clickable) { mClickable = clickable; }

    /**
     * Get the picture
     * @return mPicture
     */
    Picture* GetPicture() const {return mPicture;}

    /**
     * Set the picture the actor is in
     * @param picture
     */
    void SetPicture(Picture *picture) {mPicture = picture;}


    /**
     * Important: If an association has a name on both ends, it must be implemented in both directions.
     * The actor has a pointer to the drawable and the drawable has a pointer to the actor.
     * See how the AddDrawable function does 2 things?
     * Most functions that create an association will do two steps: creating it in the two different directions.
     * This is easy to forget and will break your code later on if you do.
     */
};

#endif //CANADIANEXPERIENCE_ACTOR_H


