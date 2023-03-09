/**
 * @file Vertex.h
 *
 * @author
 *
 * 
 */

#pragma once

class TriangleMesh;

/**
 * A vertex (point on the screen.
 */
class Vertex
{
public:
    /**
     * Constructor
     * @param x X position
     * @param y Y position
     */
    Vertex(int x, int y) { mX = x; mY = y; }

    /**
     * Set the mesh owner
     * @param mesh Pointer to triangle mesh object
     */
    void SetMesh(TriangleMesh* mesh) { mMesh = mesh; }

    /**
     * Get the X value for the vertex
     * @return X value
     */
    int GetX() { return mX; }

    /**
     * Get the Y value for the vertex
     * @return Y value
    */
    int GetY() { return mY; }

private:
    /// Vertex X value
    int mX;

    /// Vertex Y value
    int mY;

    /// The owning mesh
    TriangleMesh* mMesh = nullptr;
};

