/**
 * @file HeadTop.h
 * @author nicholas shari
 *
 *
 */

#ifndef CANADIANEXPERIENCE_HEADTOP_H
#define CANADIANEXPERIENCE_HEADTOP_H

#include "ImageDrawable.h"


/**
 * Top of the head for the character.
 */
class HeadTop : public ImageDrawable {
private:
    
    ///left eye position
    wxPoint mLeftEyePoint = wxPoint(0,0);
    ///right eye position
    wxPoint mRightEyePoint = wxPoint(0,0);


public:

    /// Default constructor (disabled)
    HeadTop() = delete;
    
    /// Copy constructor (disabled)
    HeadTop(const HeadTop &) = delete;

    HeadTop(const std::wstring& name, const std::wstring& filename);

    /// Assignment operator
    void operator=(const HeadTop &) = delete;

    /**
     * Is this a movable drawable?
     * @return true if movable
     */
    bool IsMovable() override {return true;}

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    wxPoint TransformPoint(wxPoint p);

    /**
     * center point for the right eye
     * @param point transitional point for the right eye
     */
    void SetRightEye(wxPoint point) {mRightEyePoint = point;}

    /**
     * center point for the left eye
     * @param point transitional point for the left eye
     */
    void SetLeftEye(wxPoint point) {mLeftEyePoint = point;}

};

#endif //CANADIANEXPERIENCE_HEADTOP_H
