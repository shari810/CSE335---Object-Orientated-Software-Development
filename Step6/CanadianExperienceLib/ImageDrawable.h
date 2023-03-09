/**
 * @file ImageDrawable.h
 * @author nicholas shari
 *
 *
 */

#ifndef CANADIANEXPERIENCE_IMAGEDRAWABLE_H
#define CANADIANEXPERIENCE_IMAGEDRAWABLE_H


#include "Drawable.h"
/**
 * Inherited class that is used to draw.
 */
class ImageDrawable : public Drawable {
private:

    /// Center of the image
    wxPoint mCenter = wxPoint(0,0);

    /// The graphics bitmap we will use
    wxGraphicsBitmap mBitmap;

protected:
    /// The image we are drawing
    std::unique_ptr<wxImage> mImage;

public:

    /// Default constructor (disabled)
    ImageDrawable() = delete;

    /// Copy constructor (disabled)
    ImageDrawable(const ImageDrawable &) = delete;

    /// Assignment operator
    void operator=(const ImageDrawable &) = delete;

    ImageDrawable(const std::wstring& name, const std::wstring& filename);

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics);

    bool HitTest(wxPoint pos) override;

    /**
     * Get the center
     * @return mCenter
     */
    wxPoint GetCenter() const {return mCenter;}

    /**
     * Set the center
     * @param point
     */
    void SetCenter(wxPoint point) {mCenter = point;}



};

#endif //CANADIANEXPERIENCE_IMAGEDRAWABLE_H
