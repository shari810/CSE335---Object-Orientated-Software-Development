/**
 * @file Triangle.cpp
 *
 * @author
 */

#include "pch.h"
#include "Triangle.h"
#include "TriangleMesh.h"

/**
Triangle::Triangle(std::shared_ptr<Vertex> v1, std::shared_ptr<Vertex> v2, std::shared_ptr<Vertex> v3)
{
    mVertices.push_back(v1);
    mVertices.push_back(v2);
    mVertices.push_back(v3);
}*/

void Triangle::Draw(wxDC* graphics)
{

    wxPen pen(mColor, 1, wxPENSTYLE_SOLID);
    graphics->SetPen(pen);

    auto v1 = mVertices[0];
    auto v2 = mVertices[1];
    auto v3 = mVertices[2];

    graphics->DrawLine(v1->GetX(), v1->GetY(), v2->GetX(), v2->GetY());
    graphics->DrawLine(v2->GetX(), v2->GetY(), v3->GetX(), v3->GetY());
    graphics->DrawLine(v3->GetX(), v3->GetY(), v1->GetX(), v1->GetY());

}

void Triangle::Remove()
{
    mMesh->Remove(mMeshPos);
}
