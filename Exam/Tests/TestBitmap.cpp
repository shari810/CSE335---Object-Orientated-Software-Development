//
// Created by Matthew Rupp on 12/12/21.
//

#include <pch.h>
#include <Vertex.h>
#include "TestBitmap.h"

const int WIDTH = 100;
const int HEIGHT = 100;

TestBitmap::TestBitmap() : mBitmap(WIDTH, HEIGHT)
{
    mGraphics.SelectObject(mBitmap);

    wxBrush brush(*wxWHITE);
    mGraphics.SetBrush(brush);

    mGraphics.DrawRectangle(0, 0, WIDTH, HEIGHT);
}


void TestBitmap::Save(const wchar_t *filename)
{
    mBitmap.SaveFile(filename, wxBITMAP_TYPE_PNG);
}

void TestBitmap::DrawTriangle(std::shared_ptr<Vertex> v1, std::shared_ptr<Vertex> v2, std::shared_ptr<Vertex> v3,
                             wxColour color)
{
    wxPen pen(color, 1);

    mGraphics.SetPen(pen);

    mGraphics.DrawLine(v1->GetX(), v1->GetY(), v2->GetX(), v2->GetY());
    mGraphics.DrawLine(v2->GetX(), v2->GetY(), v3->GetX(), v3->GetY());
    mGraphics.DrawLine(v3->GetX(), v3->GetY(), v1->GetX(), v1->GetY());
}

void TestBitmap::FillTriangle(std::shared_ptr<Vertex> v1, std::shared_ptr<Vertex> v2, std::shared_ptr<Vertex> v3,
                             wxColour color)
{
    wxBrush brush(color);
    mGraphics.SetBrush(brush);

    wxPoint points[3];
    points[0] = wxPoint(v1->GetX(), v1->GetY());
    points[1] = wxPoint(v2->GetX(), v2->GetY());
    points[2] = wxPoint(v3->GetX(), v3->GetY());

    mGraphics.DrawPolygon(3, points);
}


bool TestBitmap::operator==(TestBitmap &other) {
    auto image1 = mBitmap.ConvertToImage();
    auto image2 = other.mBitmap.ConvertToImage();

    for (int r = 0; r < HEIGHT; r++)
    {
        for (int c = 0; c < WIDTH; c++)
        {
            if(image1.GetRed(c, r) != image2.GetRed(c, r) ||
                    image1.GetGreen(c, r) != image2.GetGreen(c, r) ||
                    image1.GetBlue(c, r) != image2.GetBlue(c, r) )
            {
                return false;
            }
        }
    }

    return true;
}

