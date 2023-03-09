/**
 * @file ObjLoader.h
 *
 * @author Charles Owen
 *
 * OBJ file loader.
 */

#pragma once

#include <memory>
#include <string>
#include <vector>
#include <random>

class TriangleMesh;
class Vertex;

/**
 * OBJ file loader.
 */
class ObjLoader
{
public:
    ObjLoader(std::mt19937* random);

    std::shared_ptr<TriangleMesh> Load(std::wstring filename);

    /// Set the color to fill with, set to filled mode
    /// @param color Color to use
    void SetFillColor(wxColour color) { mColor = color; mFilled = true; }

    /// Set the color to fill with, set to line mode
    /// @param color Color to use
    void SetLineColor(wxColour color) { mColor = color; mFilled = false; }


    /// Set the filled mode
    /// @param filled True if triangle is filled
    void SetFilled(bool filled) { mFilled = filled; }

    /// Set the random color mode
    /// @param random true if random colors are used
    void SetRandomColors(bool random) { mRandomColors = random; }

private:
    void AddVertex(std::shared_ptr<TriangleMesh> mesh, const std::string& line);
    void AddTriangle(std::shared_ptr<TriangleMesh> mesh, const std::string& line);

    /// The mesh vertices
    std::vector<std::shared_ptr<Vertex>> mVertices;

    /// Amount to scale the data
    double mScale = 1;

    /// Filled?
    bool mFilled = false;

    /// Color to draw
    wxColour  mColor;

    /// Random colors?
    bool mRandomColors = false;

    /// Random number generator
    std::mt19937* mRandom;
};

