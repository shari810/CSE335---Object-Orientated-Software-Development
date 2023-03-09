/**
 * @file GameTest.cpp
 * @author Tate Moorhouse
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <wx/filename.h>

using namespace std;

TEST(GameTest, Construct){
    Game game;
}

TEST(GameTest, Load)
{
    auto file1 = L"data/uml.xml";
    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(file1))
    {
        wxMessageBox(L"Unable to load uml file");
        return;
    }

    // Get the XML document root node
    auto root = xmlDoc.GetRoot();

    ASSERT_EQ(root->GetName(), L"uml");

    // Keep track of how many times a tag shows up
    int classTagCount = 0;
    int inheritanceTagCount = 0;
    int nameTagCount = 0;
    int attributeTagCount = 0;
    int operationTagCount = 0;
    int inheritTagCount = 0;

    //
    // Traverse the children of the root
    // node of the XML document in memory!!!!
    //
    auto child = root->GetChildren();
    for( ; child; child=child->GetNext())
    {
        auto child2 = child->GetChildren();
        for( ; child2; child2=child2->GetNext())
        {
            auto name = child2->GetName();
            if (name == L"name")
            {
                nameTagCount++;
            }
            else if (name == L"attribute")
            {
                attributeTagCount++;
            }
            else if (name == L"operation")
            {
                operationTagCount++;
            }
            else if (name == L"inherit")
            {
                inheritTagCount++;
            }
        }
        auto name = child->GetName();
        if (name == L"class")
        {
            classTagCount++;
        }
        else if (name == L"inheritance")
        {
            inheritanceTagCount++;
        }
    }

    //
    // Check to make sure the number of tags counted
    // Is the same as the number in the given file
    //
    ASSERT_EQ(classTagCount, 1);
    ASSERT_EQ(inheritanceTagCount, 1);
    ASSERT_EQ(inheritTagCount, 7);
    ASSERT_EQ(nameTagCount, 8);
    ASSERT_EQ(attributeTagCount, 16);
    ASSERT_EQ(operationTagCount, 10);

}

TEST(GameTest, Save)
{
    Game game;
    Content content = game.GetContents();
    std::vector<wxString> goodNames = content.GetGoodNames();
    std::vector<std::vector<wxString>> badNames = content.GetBadNames();
    std::vector<wxString> goodAttributes = content.GetGoodAttributes();
    std::vector<std::vector<wxString>>  badAttributes = content.GetBadAttributes();
    std::vector<wxString> goodOperations = content.GetGoodOperations();
    std::vector<std::vector<wxString>> badOperations = content.GetBadOperations();
    ASSERT_EQ(goodNames.size(), 4);
    ASSERT_EQ(badNames.size(), 4);
    ASSERT_EQ(goodAttributes.size(), 6);
    ASSERT_EQ(badAttributes.size(), 10);
    ASSERT_EQ(goodOperations.size(), 7);
    ASSERT_EQ(badOperations.size(), 3);

    ASSERT_EQ(goodNames[0], L"Employer");
    ASSERT_EQ(badNames[0][0], L"Should be capitalized");
    ASSERT_EQ(goodAttributes[0], L"age: int");
    ASSERT_EQ(badAttributes[0][0], L"Language artifact");
    ASSERT_EQ(goodOperations[0], L"Save(filename: string)");
    ASSERT_EQ(badOperations[0][0], L"Language artifact");


}


TEST(GameTest, HitTest) {
    Game game;

    ASSERT_EQ(game.HitTest(100, 200), nullptr) <<
                                                   L"Testing empty game";

    shared_ptr<Item> pen = make_shared<Pen>(&game);
    pen->SetLocation(100, 200);
    game.Add(pen);

    ASSERT_TRUE(game.HitTest(100, 200) == pen) <<
                                                     L"Testing item at 100, 200";

    // Test to ensure nullptr if we hit away from any image
    ASSERT_EQ(game.HitTest(0, 200), nullptr) << L"Testing item at 0, 200";

    // Add two overlapping umls
    shared_ptr<Item> uml1 = make_shared<Uml>(&game);
    uml1->SetLocation(400, 400);
    game.Add(uml1);

    ASSERT_TRUE(game.HitTest(400, 400) == uml1) <<
                                               L"Testing Uml at 400, 400";

    shared_ptr<Item> uml2 = make_shared<Uml>(&game);
    uml2->SetLocation(400, 400);
    game.Add(uml2);

    // Ensure the top one is found
    ASSERT_EQ(game.HitTest(400, 400), uml2) << L"Testing overlapping Uml";
}

