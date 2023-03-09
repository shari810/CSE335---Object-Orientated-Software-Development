/**
 * @file HeadTop.cpp
 * @author nicholas shari
 */

#include "HeadTop.h"

/**
 * Constructor
 * @param name The drawable name
 * @param filename The filename for the image
 */
HeadTop::HeadTop(const std::wstring &name, const std::wstring &filename) :
        ImageDrawable(name, filename)
{
    mImage = std::make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
}

/**
 * Draw the head top image
 * @param graphics Graphics context to draw on
 */
void HeadTop::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{

    this->ImageDrawable::Draw(graphics);

    ///left eye
    wxPoint p1 = TransformPoint(mLeftEyePoint);
    ///right eye
    wxPoint p2 = TransformPoint(mRightEyePoint);
    wxPen eyebrowPen(*wxBLACK, 2);
    graphics->SetPen(eyebrowPen);
    graphics->StrokeLine(p1.x, p1.y, p1.x + 25, p1.y);
    graphics->StrokeLine(p2.x, p2.y, p2.x + 25, p2.y);

    float wid = 15.0f;
    float hit = 20.0f;

    graphics->PushState();
    graphics->Translate(p1.x+10, p1.y+20);
    graphics->Rotate(-mPlacedR);
    graphics->DrawEllipse(-wid/2, -hit/2, wid, hit);
    graphics->PopState();

    graphics->PushState();
    graphics->Translate(p2.x+10, p2.y+20);
    graphics->Rotate(-mPlacedR);
    graphics->DrawEllipse(-wid/2, -hit/2, wid, hit);
    graphics->PopState();
}

/** Transform a point from a location on the bitmap to
*  a location on the screen.
* @param  p Point to transform
* @returns Transformed point
*/
wxPoint HeadTop::TransformPoint(wxPoint p)
{
    // Make p relative to the image center
    p = p - GetCenter();

    // Rotate as needed and offset
    return RotatePoint(p, mPlacedR) + mPlacedPosition;
}