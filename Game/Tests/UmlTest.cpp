/**
 * @file UmlTest.cpp
 * @author Jon
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Uml.h>
#include <Game.h>


TEST(UmlTest, HitTest) {
// Create a uml to test
    Game game;
    Uml uml(&game);

// Give it a location
// Always make the numbers different, in case they are mixed up
    uml.SetLocation(100, 200);

// Center of the uml should be a true
    ASSERT_TRUE(uml.HitTest(100, 200));

// Left of the uml
    ASSERT_FALSE(uml.HitTest(10, 200));

// Right of the uml
    ASSERT_FALSE(uml.HitTest(200, 200));

// Above the uml
    ASSERT_FALSE(uml.HitTest(100, 0));

// Below the uml
    ASSERT_FALSE(uml.HitTest(100, 300));

//// On a pen transparent pixel
//    ASSERT_FALSE(uml.HitTest(100 - 125/2 + 17, 200 - 117/2 + 16));
}