/**
 * @file AquariumTest.cpp
 * @author nicholas shari
 */

#include "gtest/gtest.h"
#include <pch.h>
#include <Aquarium.h>
#include <FishBeta.h>

using namespace std;

TEST(AquariumTest, Construct){
    Aquarium aquarium;
}

TEST(AquariumTest, HitTest) {
    Aquarium aquarium;

    ASSERT_EQ(aquarium.HitTest(100, 200), nullptr) <<
                                                   L"Testing empty aquarium";

    shared_ptr<FishBeta> fish1 = make_shared<FishBeta>(&aquarium);
    fish1->SetLocation(100, 200);
    aquarium.Add(fish1);

    ASSERT_TRUE(aquarium.HitTest(100, 200) == fish1) <<
                                                     L"Testing fish at 100, 200";

    //test to see if clicking not on an image, where an image is loaded into the aquarium already somewhere else
    ASSERT_FALSE(aquarium.HitTest(100,1000) == fish1) << L"Testing fish does not exist at 100,1000";

    // ensures a nullptr is returned
    //test to see if clicking not on an image, where an image is loaded into the aquarium already somewhere else
    ASSERT_TRUE(aquarium.HitTest(100,1000) == nullptr) << L"Testing to verify nullptr is returned where image DNE";

}

TEST(AquraiumTest, StackedHitTest)
{
    // Create a fish to test
    Aquarium aquarium;
    shared_ptr<FishBeta> fish1 = make_shared<FishBeta>(&aquarium);
    shared_ptr<FishBeta> fish2 = make_shared<FishBeta>(&aquarium);

    //stack the fish directly on each other
    fish1->SetLocation(100, 200);
    aquarium.Add(fish1);
    fish2->SetLocation(100, 200);
    aquarium.Add(fish2);

    //Test to see if fish2 is draw last, should be last in the vector and returned by HitTest()
    ASSERT_TRUE(aquarium.HitTest(100, 200) ==  fish2);

    //Test to see is fish1 is not on top, and therefore not drawn last.
    ASSERT_FALSE(aquarium.HitTest(100, 200) ==  fish1);



}