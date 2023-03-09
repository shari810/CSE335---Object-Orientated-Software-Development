/**
 * @file TimelineTest.cpp
 * @author nicholas shari
 */

#include <pch.h>
#include "gtest/gtest.h"
#include "Timeline.h"

TEST(TimelineTest, GetterSetter)
{
    Timeline timeline1;

    ///initial values
    ASSERT_EQ(timeline1.GetNumFrames(), 300);
    ASSERT_EQ(timeline1.GetFrameRate(), 30);
    ASSERT_NEAR(timeline1.GetCurrentTime(),0,0.0001);

    ///setters
    timeline1.SetNumFrames(400);
    timeline1.SetFrameRate(40);
    timeline1.SetCurrentTime(5.2525);

    ASSERT_EQ(timeline1.GetNumFrames(), 400);
    ASSERT_EQ(timeline1.GetFrameRate(), 40);
    ASSERT_NEAR(timeline1.GetCurrentTime(),5.2525,0.0001);
}

TEST(TimelineTest, GetDuration)
{
    Timeline timeline;

    // Default value
    ASSERT_NEAR(10, timeline.GetDuration(), 0.0001);

    // Changed duration
    timeline.SetFrameRate(375);
    ASSERT_NEAR(300.0 / 375.0, timeline.GetDuration(), 0.0001);

    timeline.SetNumFrames(789);
    ASSERT_NEAR(789.0 / 375.0, timeline.GetDuration(), 0.0001);
}

TEST(TimelineTest, GetCurrentFrame)
{
    Timeline timeline;

    // Default value
    ASSERT_EQ(0, timeline.GetCurrentFrame());

    // Changed time
    timeline.SetCurrentTime(9.27);
    ASSERT_EQ(278, timeline.GetCurrentFrame());
}