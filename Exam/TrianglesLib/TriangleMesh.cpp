/**
 * @file TriangleMesh.cpp
 *
 * @author
 */

#include "pch.h"
#include "TriangleMesh.h"
#include "Vertex.h"
#include "Triangle.h"
#include "FilledTriangle.h"


/**
 * Get the number of triangles in the mesh.
 * @return Number of triangles
 */
int TriangleMesh::GetNumTriangles()
{
    // Placeholder, not the valid return value

    return mTriangles.size();
    //return 0;
}


/**
 * Get one of the mesh triangles.
 * @param n Triangle index, 0 to number of triangles-1.
 * @return Triangle object.
 */
std::shared_ptr<Triangle> TriangleMesh::GetTriangle(int n)
{
    // Placeholder, not the valid return value

    if (n < mTriangles.size())
    {
        return mTriangles[n];
    }
    return nullptr;
}



/**
 * Draw all of the triangles in the triangle mesh.
 * @param dc The device context to draw on
 */
void TriangleMesh::Draw(wxDC *dc)
{
    for (auto triangle : mTriangles)
    {
        triangle->Draw(dc);
    }


}

/**
 * Create a vertex.
 * @param x Vertex X location
 * @param y Vertex Y location
 * @return Added vertex object
 */
std::shared_ptr<Vertex> TriangleMesh::AddVertex(int x, int y)
{
    // Placeholder, not the valid return value

    auto vert = std::make_shared<Vertex>(x,y);

    vert->SetMesh(this);

    mVertices.push_back(vert);

    return vert;
}


/**
 * Create a triangle.
 * @param v1 First vertex
 * @param v2 Second vertex
 * @param v3 Third vertex
 * @param color Color to draw the triangle
 * @return Triangle object.
 */
std::shared_ptr<Triangle> TriangleMesh::AddTriangle(std::shared_ptr<Vertex> v1,
    std::shared_ptr<Vertex> v2,
    std::shared_ptr<Vertex> v3,
    wxColour color)
{
    // Placeholder, not the valid return value

    auto triangle = std::make_shared<Triangle>();
    triangle->AddVertex(v1);
    triangle->AddVertex(v2);
    triangle->AddVertex(v3);
    triangle->SetColor(color);
    triangle->SetMesh(this);
    mTriangles.push_back(triangle);
    triangle->SetMeshPos(GetNumTriangles()-1);

    return triangle;

    //return nullptr;
}

/**
 * Create a filled triangle.
 * @param v1 First vertex
 * @param v2 Second vertex
 * @param v3 Third vertex
 * @param color Color to draw the triangle
 * @return Triangle object.
 */
std::shared_ptr<Triangle> TriangleMesh::AddFilledTriangle(std::shared_ptr<Vertex> v1,
    std::shared_ptr<Vertex> v2,
    std::shared_ptr<Vertex> v3,
    wxColour color)
{
    // Placeholder, not the valid return value

    auto triangle = std::make_shared<FilledTriangle>();
    triangle->AddVertex(v1);
    triangle->AddVertex(v2);
    triangle->AddVertex(v3);
    triangle->SetColor(color);
    triangle->SetMesh(this);

    mTriangles.push_back(triangle);
    triangle->SetMeshPos(GetNumTriangles()-1);

    return triangle;

    //return nullptr;
}

void TriangleMesh::Remove(int pos)
{

    mTriangles.erase(mTriangles.begin()+pos);

    for (auto triangle : mTriangles)
    {
        if (triangle->GetMeshPos() > pos)
        {
            triangle->SetMeshPos(triangle->GetMeshPos()-1);
        }
    }

    //mTriangles.erase( std::remove( mTriangles.begin(), mTriangles.end() ,triangle ), mTriangles.end() );


}
