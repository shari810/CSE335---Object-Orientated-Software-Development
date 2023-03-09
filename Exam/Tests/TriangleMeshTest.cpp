#include <pch.h>
#include "gtest/gtest.h"
#include <TriangleMesh.h>
#include <Vertex.h>
#include <Triangle.h>
#include "TestBitmap.h"

using namespace std;


TEST(TriangleMeshTest, CreateEmpty)
{
    auto mesh = make_shared<TriangleMesh>();
    ASSERT_EQ(0, mesh->GetNumTriangles());
}

TEST(TriangleMeshTest, OneTriangle)
{
    auto mesh = make_shared<TriangleMesh>();
    auto v1 = mesh->AddVertex(10, 12);
    auto v2 = mesh->AddVertex(20, 24);
    auto v3 = mesh->AddVertex(15, 89);
    auto color = wxColour(12, 34, 56);

    ASSERT_EQ(10, v1->GetX());
    ASSERT_EQ(12, v1->GetY());

    auto t1 = mesh->AddTriangle(v1, v2, v3, color);

    ASSERT_EQ(1, mesh->GetNumTriangles());
    ASSERT_TRUE(t1 == mesh->GetTriangle(0));

    t1 = mesh->GetTriangle(0);
    ASSERT_EQ(color.GetRGB(), t1->GetColor().GetRGB());
    ASSERT_TRUE(v1 == t1->GetV1());
    ASSERT_TRUE(v2 == t1->GetV2());
    ASSERT_TRUE(v3 == t1->GetV3());
}



