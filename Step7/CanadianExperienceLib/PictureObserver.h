/**
 * @file PictureObserver.h
 * @author nicholas shari
 *
 * Observer base class for a picture.
 *
 * This class implements the base class functionality for
 * an observer in the observer pattern.
 */

#ifndef CANADIANEXPERIENCE_PICTUREOBSERVER_H
#define CANADIANEXPERIENCE_PICTUREOBSERVER_H

#include <memory>

class Picture;

/**
 * Observer base class for a picture.
 *
 * This class implements the base class functionality for
 * an observer in the observer pattern.
 */
class PictureObserver {
private:

    /// Picture we are observing
    std::shared_ptr<Picture> mPicture;



///To make a class abstract, make the constructor protected:
protected:
    /// Constructor
    PictureObserver() {}


public:

    virtual ~PictureObserver();
    /// Copy Constructor (Disabled)
    PictureObserver(const PictureObserver &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const PictureObserver &) = delete;

    /// This function is called to update any observers
    virtual void UpdateObserver() = 0;

    /**
     * Getter for mPicture
     * @return mPicture
     */
    std::shared_ptr<Picture> GetPicture() const {return mPicture;}


    void SetPicture(std::shared_ptr<Picture> picture);




};

#endif //CANADIANEXPERIENCE_PICTUREOBSERVER_H
