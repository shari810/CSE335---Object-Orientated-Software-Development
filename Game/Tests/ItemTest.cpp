/**
 * @file ItemTest.cpp
 * @author Jon
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Item.h>
#include <Game.h>


using namespace std;

class ItemMock : public Item{
public:
//    ItemMock(Game* game)
//            :Item(game) { }

    /**  Constructor
    * \param game Game this item is a member of */
    ItemMock(Game *game) : Item(game)
            {
            }

    ///  Default constructor (disabled)
    ItemMock() = delete;

    ///  Copy constructor (disabled)
    ItemMock(const ItemMock &) = delete;

    ~ItemMock() {}

    void Draw(wxGraphicsContext* graphics) override {}
    bool HitTest(int x, int y) override { return false; }
};


//TEST(ItemTest, Construct)
//{
//    Game game;
//    ItemMock item(&game);
//}
//
//
//TEST(ItemTest, GettersSetters)
//{
//    Game game;
//    ItemMock item(&game);
//
//    // Test initial values
//    ASSERT_NEAR(0, item.GetX(), 0.0001);
//    ASSERT_NEAR(0, item.GetY(), 0.0001);
//
//    // Test SetLocation, GetX, and GetY
//    item.SetLocation(10.5, 17.2);
//    ASSERT_NEAR(10.5, item.GetX(), 0.0001);
//    ASSERT_NEAR(17.2, item.GetY(), 0.0001);
//
//    // Test a second with with different values
//    item.SetLocation(-72, -107);
//    ASSERT_NEAR(-72, item.GetX(), 0.0001);
//    ASSERT_NEAR(-107, item.GetY(), 0.0001);
//}