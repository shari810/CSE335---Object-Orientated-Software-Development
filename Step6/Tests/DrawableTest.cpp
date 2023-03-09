/**
 * @file DrawableTest.cpp
 * @author nicholas shari
 */


#include <pch.h>
#include "gtest/gtest.h"
#include "Drawable.h"



class DrawableMock : public Drawable
{
public:
    DrawableMock(const std::wstring &name) : Drawable(name) {}

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) override {}
    virtual bool HitTest(wxPoint pos) override { return false; }
};

TEST(DrawableTest, Constructor)
{
    DrawableMock drawable(L"TestString");

    ASSERT_EQ(std::wstring(L"TestString"), drawable.GetName());

}

TEST(DrawableTest, Position)
{
    DrawableMock drawable(L"TestString");

    //default value 0,0
    ASSERT_EQ(wxPoint(0,0), drawable.GetPosition());

    drawable.SetPosition(wxPoint(50,100));
    ASSERT_EQ(wxPoint(50,100), drawable.GetPosition());

}

TEST(DrawableTest, Rotation)
{
    DrawableMock drawable(L"TestString");

    //default value 0
    ASSERT_EQ(0, drawable.GetRotation());

    drawable.SetRotation(1.123);
    ASSERT_NEAR(1.123, drawable.GetRotation(),0.0001);
}

TEST(DrawableTest, Association)
{
    DrawableMock body(L"Body");
    auto arm = std::make_shared<DrawableMock>(L"Arm");
    auto leg = std::make_shared<DrawableMock>(L"Leg");

    ASSERT_EQ(nullptr, arm->GetParent());
    ASSERT_EQ(nullptr, leg->GetParent());

    body.AddChild(arm);
    body.AddChild(leg);

    ASSERT_EQ(&body, arm->GetParent());
    ASSERT_EQ(&body, leg->GetParent());
}