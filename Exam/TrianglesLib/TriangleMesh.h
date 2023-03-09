/**
 * System class that defines a triangle mesh.
 *
 * @file TriangleMesh.h
 */

#pragma once

#include <memory>
#include <vector>

#include "Triangle.h"

class Vertex;
class Triangle;

/**
 * Abstraction of a triangle mesh.
 */
class TriangleMesh
{
public:
    TriangleMesh() {}
    ~TriangleMesh() {}

    /** Copy constructor disabled */
    TriangleMesh(const TriangleMesh&) = delete;
    /** Assignment operator disabled */
    void operator=(const TriangleMesh&) = delete;

    void Draw(wxDC *dc);

    std::shared_ptr<Vertex> AddVertex(int x, int y);

    std::shared_ptr<Triangle> AddTriangle(std::shared_ptr<Vertex> v1,
        std::shared_ptr<Vertex> v2, std::shared_ptr<Vertex> v3, wxColour color);

    std::shared_ptr<Triangle> AddFilledTriangle(std::shared_ptr<Vertex> v1,
        std::shared_ptr<Vertex> v2, std::shared_ptr<Vertex> v3, wxColour color);

    int GetNumTriangles();
    std::shared_ptr<Triangle> GetTriangle(int n);

private:
    /// The triangle vertices
    std::vector<std::shared_ptr<Vertex>> mVertices;

    /// The triangles
    std::vector<std::shared_ptr<Triangle>> mTriangles;

public:

    /** Iterator that iterates over the actors in a picture */
    class Iter
    {
    public:
        /** \brief Constructor
        * @param picture Picture we are iterating
        * @param pos Starting position */
        Iter(TriangleMesh * picture, int pos) : mMesh(picture), mPos(pos) {}

        /** \brief Test for end of the iterator
        * @param other Other object to test against
        * @return True if we this position equals not equal to the other position */
        bool operator!=(const Iter& other) const
        {
            return mPos != other.mPos;
        }

        /** \brief Get value at current position
        * @return Value at mPos in the collection */
        std::shared_ptr<Triangle> operator *() const { return mMesh->mTriangles[mPos]; }

        /** \brief Increment the iterator
        * @return Reference to this iterator */
        const Iter& operator++()
        {
            mPos++;
            return *this;
        }

    private:
        TriangleMesh * mMesh; ///< Mesh we are iterating over
        int mPos;           ///< Position in the collection
    };

    /** \brief Get an iterator for the beginning of the collection
    * @return Iter object at position 0 */
    Iter begin() { return Iter(this, 0); }

    /** \brief Get an iterator for the end of the collection
    * @return Iter object at position past the end */
    Iter end() { return Iter(this, mTriangles.size()); }

    //void Remove(std::shared_ptr<Triangle> triangle);

    void Remove(int pos);
};

