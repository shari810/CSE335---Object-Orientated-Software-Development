/**
 * @file PolyDrawable.h
 * @author nicholas shari
 *
 * A drawable based on polygon images.
 */

#ifndef CANADIANEXPERIENCE_POLYDRAWABLE_H
#define CANADIANEXPERIENCE_POLYDRAWABLE_H

#include "Drawable.h"

/**
 * A drawable based on polygon images.
 *
 * This class has a list of points and draws a polygon
 * drawable based on those points.
 */
class PolyDrawable : public Drawable{

private:


    /// The polygon color
    wxColour mColor = *wxBLACK;

    /// The array of point objects
    std::vector<wxPoint> mPoints;

    /// The transformed graphics path used
    /// to draw this polygon
    wxGraphicsPath mPath;

public:

    /// Default constructor (disabled)
    PolyDrawable() = delete;

    /// Copy constructor (disabled)
    PolyDrawable(const PolyDrawable &) = delete;

    /// Assignment operator
    void operator=(const PolyDrawable &) = delete;

    PolyDrawable(const std::wstring& name);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    bool HitTest(wxPoint pos) override;

    void AddPoint(wxPoint point);


    /**
     * Getter for mColor
     * @return color of polygon
     */
    wxColour GetColor() const {return mColor;}

    /**
     * Set the polygon color
     * @param color  new color of the polygon
     */
    void SetColor(wxColour color) {mColor = color;}






};

#endif //CANADIANEXPERIENCE_POLYDRAWABLE_H
