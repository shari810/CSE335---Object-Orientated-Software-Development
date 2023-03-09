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
    ///mImage = std::make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
}

/**
 * Draw the head top image
 * @param graphics Graphics context to draw on

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
*/

/**
 * Draw the head top
 * @param graphics
 */
void HeadTop::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    ImageDrawable::Draw(graphics);

    // Distance horizontally from each eye center to the center
    int d2 = mInterocularDistance / 2;

    // Compute a left and right eye center X location
    int rightX = mEyesCenter.x - d2;
    int leftX = mEyesCenter.x + d2;

    // Eye center Y value
    int eyeY = mEyesCenter.y;

    DrawEyebrow(graphics, wxPoint(rightX - 10, eyeY - 16), wxPoint(rightX + 4, eyeY - 18));
    DrawEyebrow(graphics, wxPoint(leftX - 4, eyeY - 20), wxPoint(leftX + 9, eyeY - 18));

    DrawEye(graphics, wxPoint(leftX, eyeY));
    DrawEye(graphics, wxPoint(rightX, eyeY));
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

/**
 * Draw an eyebrow, automatically transforming the points
 *
 * Draw a line from (x1, y1) to (x2, y2) after transformation
 * to the local coordinate system.
 * @param graphics Graphics context to draw on
 * @param p1 First point
 * @param p2 Second point
 */
void HeadTop::DrawEyebrow(std::shared_ptr<wxGraphicsContext> graphics,
        wxPoint p1, wxPoint p2)
{
    auto eb1 = TransformPoint(p1);
    auto eb2 = TransformPoint(p2);

    wxPen eyebrowPen(*wxBLACK, 2);
    graphics->SetPen(eyebrowPen);
    graphics->StrokeLine(eb1.x, eb1.y, eb2.x, eb2.y);
}

/**
 * Draw an eye using an Ellipse
 * @param graphics The graphics context to draw on
 * @param p1 Where to draw before transformation */
void HeadTop::DrawEye(std::shared_ptr<wxGraphicsContext> graphics, wxPoint p1)
{
    graphics->SetBrush(*wxBLACK_BRUSH);
    graphics->SetPen(*wxTRANSPARENT_PEN);

    auto e1 = TransformPoint(p1);

    float wid = 15.0f;
    float hit = 20.0f;

    graphics->PushState();
    graphics->Translate(e1.x, e1.y);
    graphics->Rotate(-mPlacedR);
    graphics->DrawEllipse(-wid/2, -hit/2, wid, hit);
    graphics->PopState();
}