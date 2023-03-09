/**
 * @file PictureObserverTest.cpp
 * @author nicholas shari
 */

#include <pch.h>
#include "gtest/gtest.h"
#include "PictureObserver.h"
#include <Picture.h>

class PictureObserverMock : public PictureObserver
{
public:
    PictureObserverMock() : PictureObserver() {}
    bool mUpdated = false;
    virtual void UpdateObserver() override { mUpdated = true; }

};


TEST(PictureObserverTest, Construct) {
    PictureObserverMock observer;
}


TEST(PictureObserverTest, OneObserver) {
    // Allocate a Picture object
    auto picture = std::make_shared<Picture>();

    // Create a mock observer object
    PictureObserverMock observer;

    // And set it for the observer:
    observer.SetPicture(picture);

    picture->UpdateObservers();

    ASSERT_TRUE(observer.mUpdated);
}

TEST(PictureObserverTest, Getter){
    // Allocate a Picture object
    auto picture = std::make_shared<Picture>();

    // Create a mock observer object
    PictureObserverMock observer;

    // And set it for the observer:
    observer.SetPicture(picture);

    picture->UpdateObservers();

    ASSERT_EQ(picture, observer.GetPicture());
}

TEST(PictureObserverTest, TwoObservers) {
    // Allocate a Picture object
    auto picture1 = std::make_shared<Picture>();
    auto picture2 = std::make_shared<Picture>();

    // Create a mock observer object
    PictureObserverMock observer1;
    PictureObserverMock observer2;
    // And set it for the observer:
    observer1.SetPicture(picture1);
    observer2.SetPicture(picture2);

    picture1->UpdateObservers();
    picture2->UpdateObservers();

    ASSERT_TRUE(observer1.mUpdated);
    ASSERT_TRUE(observer2.mUpdated);

}


TEST(PictureObserverTest, Destroy) {
    // Allocate a Picture object
    auto picture = std::make_shared<Picture>();

    // Create a mock observer object
    PictureObserverMock observer;

    // And set it for the observer:
    observer.SetPicture(picture);

    {
        PictureObserverMock observer2;

        // And set it for the observer:
        observer2.SetPicture(picture);
    }
    picture->UpdateObservers();

    ASSERT_TRUE(observer.mUpdated);
}


/**
* When you see cannot instantiate abstract class after you add something to a class that is supposed to be abstract,
 * you have some derived class that you will have to implement the function in.
 * The second error message tells you what class that is and what function is causing the problem.
*/