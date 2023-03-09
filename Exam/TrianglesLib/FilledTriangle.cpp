/**
 * @file FilledTriangle.cpp
 *
 * @author Charles Owen
 */

#include "pch.h"
#include "FilledTriangle.h"


void FilledTriangle::Draw(wxDC* graphics)
{
    wxBrush brush(GetColor());
    graphics->SetBrush(brush);

    auto v1 = GetV1();
    auto v2 = GetV2();
    auto v3 = GetV3();

    wxPoint points[3];
    points[0] = wxPoint(v1->GetX(), v1->GetY());
    points[1] = wxPoint(v2->GetX(), v2->GetY());
    points[2] = wxPoint(v3->GetX(), v3->GetY());

    graphics->DrawPolygon(3, points);
}
