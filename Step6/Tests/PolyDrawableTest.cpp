/**
 * @file PolyDrawableTest.cpp
 * @author nicholas shari
 */


#include <pch.h>
#include "gtest/gtest.h"
#include "PolyDrawable.h"


TEST(PolyDrawableTest, Constructor)
{
    PolyDrawable polydrawable(L"TestString");

    ASSERT_EQ(std::wstring(L"TestString"), polydrawable.GetName());


}


TEST(PolyDrawable, Color)
{
    PolyDrawable polydrawable(L"TestString");

    //default color is Black
    ASSERT_EQ(*wxBLACK, polydrawable.GetColor());

    polydrawable.SetColor(*wxWHITE);

    ASSERT_EQ(*wxWHITE, polydrawable.GetColor());
}