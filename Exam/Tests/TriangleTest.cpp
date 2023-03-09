/**
 * @file TriangleTest.cpp
 * @author nicholas shari
 */



#include <pch.h>
#include "gtest/gtest.h"
#include <TriangleMesh.h>
#include <Vertex.h>
#include <Triangle.h>
#include "TestBitmap.h"



using namespace std;

class TriangleMock : public Triangle{

    virtual void Draw(wxDC* graphics) override;

};



TEST(TriangleTest,Constructor){


    auto triangle = std::make_shared<Triangle>();

    ASSERT_TRUE(triangle->GetColor() == *wxBLACK);

}


TEST(TriangleTest,Remove){

    auto mesh = make_shared<TriangleMesh>();
    auto v1 = mesh->AddVertex(10, 12);
    auto v2 = mesh->AddVertex(20, 24);
    auto v3 = mesh->AddVertex(15, 89);
    auto color = wxColour(12, 34, 56);


    auto t1 = mesh->AddTriangle(v1, v2, v3, color);

    ASSERT_EQ(mesh->GetNumTriangles(), 1);

    auto color2 = wxColour(22, 44, 66);

    auto t2 = mesh->AddTriangle(v1, v2, v3, color2);

    ASSERT_EQ(mesh->GetNumTriangles(), 2);


    t2 = mesh->GetTriangle(1);
    t2->Remove();
    ///Test to remove the last position
    ASSERT_EQ(mesh->GetNumTriangles(), 1);
    ASSERT_TRUE(mesh->GetTriangle(0) == t1);



    auto color3 = wxColour(33, 55, 77);

    auto t3 = mesh->AddTriangle(v1, v2, v3, color2);

    auto color4 = wxColour(44, 66, 88);

    auto t4 = mesh->AddTriangle(v1, v2, v3, color2);

    ASSERT_EQ(mesh->GetNumTriangles(), 3);

    ///Test to remove the middle position
    t3->Remove();
    ASSERT_EQ(mesh->GetNumTriangles(), 2);
    ASSERT_TRUE(mesh->GetTriangle(1) == t4);

    ///Test to remove the first position
    t1->Remove();
    ASSERT_EQ(mesh->GetNumTriangles(), 1);
    ASSERT_TRUE(mesh->GetTriangle(0) == t4);

    ///Test to see if a single triangle can be removed
    t4->Remove();
    ASSERT_EQ(mesh->GetNumTriangles(), 0);
}