/**
 * @file ActorTest.cpp
 * @author nicholas shari
 *
 */


#include <pch.h>
#include "gtest/gtest.h"
#include "Actor.h"


/**
 * To test a string getter, you must test against a wstring.
 * Here is the test for the constructor with the name getter test to show how this is done:
 */

TEST(ActorTest, Constructor)
{
    Actor actor(L"Harold");
    ASSERT_EQ(std::wstring(L"Harold"), actor.GetName());
}

TEST(ActorTest, Enabled)
{
    Actor actor(L"Harold");

    //default is true
    ASSERT_EQ(true, actor.IsEnabled());

    actor.SetEnabled(false);

    ASSERT_EQ(false, actor.IsEnabled());

}

TEST(ActorTest, Clickable)
{
    Actor actor(L"Harold");

    //default is true
    ASSERT_EQ(true, actor.IsClickable());

    actor.SetClickable(false);

    ASSERT_EQ(false, actor.IsClickable());
}

TEST(ActorTest, Position)
{
    Actor actor(L"Harold");

    //default value 0,0
    ASSERT_EQ(wxPoint(0,0), actor.GetPosition());

    actor.SetPosition(wxPoint(50,100));

    ASSERT_EQ(wxPoint(50,100), actor.GetPosition());
}