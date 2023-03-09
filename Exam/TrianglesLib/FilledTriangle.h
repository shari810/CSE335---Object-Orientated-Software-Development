/**
 * @file FilledTriangle.h
 *
 * @author Charles Owen
 *
 * Class for a triangle drawn as a filled triangle.
 */

#pragma once
#include "Triangle.h"

/**
 * Class for a triangle drawn as a filled triangle.
 */
class FilledTriangle : public Triangle
{

private:



public:

    void Draw(wxDC *graphics) override;

};

