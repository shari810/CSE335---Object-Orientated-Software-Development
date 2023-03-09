#include <pch.h>
#include "gtest/gtest.h"

#include <City.h>
#include <TileRoad.h>
#include <TileLandscape.h>
#include <TileCoalmine.h>
#include <TileBuilding.h>

using namespace std;

class TestVisitor : public TileVisitor
{
public:
    virtual void VisitRoad(TileRoad* road) override { mNumRoads++,mNumRoadsVisits++; }
    virtual void VisitBuilding(TileBuilding* building) override { mNumBuildings++,mNumBuildingsVisits++; }
    virtual void VisitLandscape(TileLandscape* landscape) override { mNumLandscapes++, mNumLandscapesVisits++; }
    virtual void VisitCoalmine(TileCoalmine* coalmine) override { mNumCoalmines++, mNumCoalminesVisits++; }

    int mNumRoads = 0;
    int mNumBuildings = 0;
    int mNumLandscapes = 0;
    int mNumCoalmines = 0;
    int mNumRoadsVisits = 0;
    int mNumBuildingsVisits = 0;
    int mNumLandscapesVisits = 0;
    int mNumCoalminesVisits = 0;
};

TEST(CityTest, Adjacent)
{
    City city;
    int grid = City::GridSpacing;

    // Add a center tile to test
    auto center = make_shared<TileRoad>(&city);
    center->SetLocation(grid * 10, grid * 17);
    city.Add(center);

    // Upper left
    auto ul = make_shared<TileRoad>(&city);
    ul->SetLocation(grid * 8, grid * 16);
    city.Add(ul);
    city.SortTiles();

    ASSERT_EQ(ul, city.GetAdjacent(center, -1, -1)) << L"Upper left test";
    ASSERT_EQ(nullptr,city.GetAdjacent(center, 1, -1)) << L"Upper right null test";

    // Upper right
    auto ur = make_shared<TileRoad>(&city);
    ur->SetLocation(grid * 12, grid * 16);
    city.Add(ur);

    // Lower left
    auto ll = make_shared<TileRoad>(&city);
    ll->SetLocation(grid * 8, grid * 18);
    city.Add(ll);

    // Lower right
    auto lr = make_shared<TileRoad>(&city);
    lr->SetLocation(grid * 12, grid * 18);
    city.Add(lr);

    city.SortTiles();

    ASSERT_EQ(ur, city.GetAdjacent(center, 1, -1)) << L"Upper right test";
    ASSERT_EQ(ll, city.GetAdjacent(center, -1, 1)) << L"Lower left test";
    ASSERT_EQ(lr, city.GetAdjacent(center, 1, 1)) << L"Lower right test";
}


TEST(CityTest, Iterator)
{
    // Construct a city object
    City city;

    // Add some tiles
    auto tile1 = make_shared<TileRoad>(&city);
    auto tile2 = make_shared<TileRoad>(&city);
    auto tile3 = make_shared<TileRoad>(&city);

    city.Add(tile1);
    city.Add(tile2);
    city.Add(tile3);

    // Begin points to the first item
    auto iter1 = city.begin();

    // End points after the last item
    auto iter2 = city.end();

    //know that iter1 is pointing to the first item in the list, tile1
    ASSERT_EQ(tile1, *iter1) << L"First item correct";

    ++iter1;
    ASSERT_EQ(tile2, *iter1) << L"Second item correct";

    ++iter1;
    ASSERT_EQ(tile3, *iter1) << L"Third item correct";

    //test that the != operator works for the end of the list
    ++iter1;
    ASSERT_FALSE(iter1 != iter2);
}


TEST(CityTest, Visitor)
{
    // Construct a city object
    City city;

    // Add some tiles of each time
    auto tile1 = make_shared<TileRoad>(&city);
    auto tile2 = make_shared<TileBuilding>(&city);
    auto tile3 = make_shared<TileLandscape>(&city);
    auto tile4 = make_shared<TileCoalmine>(&city);

    city.Add(tile1);
    city.Add(tile2);
    city.Add(tile3);
    city.Add(tile4);

    TestVisitor visitor;
    city.Accept(&visitor);
    ASSERT_EQ(1, visitor.mNumRoads) << L"Visitor number of roads";
    ASSERT_EQ(1, visitor.mNumBuildings) << L"Visitor number of buildings";
    ASSERT_EQ(1, visitor.mNumLandscapes) << L"Visitor number of landscapes";
    ASSERT_EQ(1, visitor.mNumCoalmines) << L"Visitor number of coalmines";

    City cityEmpty;
    TestVisitor visitorEmpty;
    cityEmpty.Accept(&visitorEmpty);
    ASSERT_EQ(0, visitorEmpty.mNumRoadsVisits) << L"Visit number of roads";
    ASSERT_EQ(0, visitorEmpty.mNumBuildingsVisits) << L"Visit number of buildings";
    ASSERT_EQ(0, visitorEmpty.mNumLandscapesVisits) << L"Visit number of landscapes";
    ASSERT_EQ(0, visitorEmpty.mNumCoalminesVisits) << L"Visit number of coalmines";
}