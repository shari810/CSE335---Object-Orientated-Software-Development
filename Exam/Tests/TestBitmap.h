//
// Created by Matthew Rupp on 12/12/21.
//

#ifndef TRIANGLES_TESTBITMAP_H
#define TRIANGLES_TESTBITMAP_H

#include <pch.h>
#include <memory>



class TestBitmap
{
private:
    wxBitmap mBitmap;

    wxMemoryDC mGraphics;

public:
    TestBitmap();

    wxDC* GetGraphics() {return &mGraphics;}

    void Save(const wchar_t *filename);

    void DrawTriangle(std::shared_ptr<Vertex> v1, std::shared_ptr<Vertex> v2, std::shared_ptr<Vertex> v3, wxColour color);

    void FillTriangle(std::shared_ptr<Vertex> v1, std::shared_ptr<Vertex> v2, std::shared_ptr<Vertex> v3, wxColour color);

    bool operator==(TestBitmap& other);

};

#endif //TRIANGLES_TESTBITMAP_H
