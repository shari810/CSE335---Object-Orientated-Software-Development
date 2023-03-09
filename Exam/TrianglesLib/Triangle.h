/**
 * @file Triangle.h
 *
 * @author Charles Owen
 *
 * Abstraction of a triangle.
 */

#pragma once

#include <memory>

#include "Vertex.h"

class TriangleMesh;

/**
 * Abstraction of a triangle.
 */
class Triangle
{

private:

    wxColour mColor = *wxBLACK;

    std::vector<std::shared_ptr<Vertex>> mVertices;

    TriangleMesh *mMesh = nullptr;

    int mMeshPos = 0;

public:


    //Triangle(std::shared_ptr<Vertex> v1, std::shared_ptr<Vertex> v2, std::shared_ptr<Vertex> v3);

    virtual void Draw(wxDC* graphics);


    std::shared_ptr<Vertex> GetV1() const {return mVertices[0];}

    std::shared_ptr<Vertex> GetV2() const {return mVertices[1];}

    std::shared_ptr<Vertex> GetV3() const {return mVertices[2];}

    void AddVertex(std::shared_ptr<Vertex> vertex) { mVertices.push_back(vertex); }

    wxColour GetColor() const {return mColor;}

    void SetColor(wxColour color) {mColor = color;}

    void SetMesh(TriangleMesh* mesh) { mMesh = mesh; }

    void SetMeshPos(int pos) { mMeshPos = pos;}

    int GetMeshPos() const {return mMeshPos;}

    void Remove();
};

