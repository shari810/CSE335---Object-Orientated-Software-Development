/**
 * @file AquariumTest.cpp
 * @author nicholas shari
 */

#include "gtest/gtest.h"
#include <pch.h>
#include <Aquarium.h>
#include <FishBeta.h>
#include <FishBubbles.h>
#include <FishMagikarp.h>
#include <DecorCastle.h>

#include <wx/filename.h>

#include <regex>
#include <string>
#include <fstream>
#include <streambuf>

using namespace std;

class AquariumTest : public ::testing::Test {
protected:
    /**
    * Create a path to a place to put temporary files
    */
    wxString TempPath()
    {
        // Create a temporary filename we can use
        auto path = wxFileName::GetTempDir() + L"/aquarium";
        if(!wxFileName::DirExists(path))
        {
            wxFileName::Mkdir(path);
        }

        return path;
    }

    /**
    * Read a file into a wstring and return it.
    * @param filename Name of the file to read
    * @return File contents
    */
    wstring ReadFile(const wxString &filename)
    {
        ifstream t(filename.ToStdString());
        wstring str((istreambuf_iterator<char>(t)),
                istreambuf_iterator<char>());

        return str;
    }

    /**
 * Test to ensure an aquarium .aqua file is empty
 */
    void TestEmpty(wxString filename)
    {
        cout << "Temp file: " << filename << endl;

        auto xml = ReadFile(filename);
        cout << xml << endl;

        ASSERT_TRUE(regex_search(xml, wregex(L"<\\?xml.*\\?>")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<aqua/>")));
    }

    /**
 *  Populate an aquarium with three Beta fish
 */
    void PopulateThreeBetas(Aquarium *aquarium)
    {
        auto fish1 = make_shared<FishBeta>(aquarium);
        fish1->SetLocation(100, 200);
        aquarium->Add(fish1);

        auto fish2 = make_shared<FishBeta>(aquarium);
        fish2->SetLocation(400, 400);
        aquarium->Add(fish2);

        auto fish3 = make_shared<FishBeta>(aquarium);
        fish3->SetLocation(600, 100);
        aquarium->Add(fish3);
    }

    void TestThreeBetas(wxString filename)
    {
        cout << "Temp file: " << filename << endl;

        auto xml = ReadFile(filename);
        cout << xml << endl;

        // Ensure three items
        ASSERT_TRUE(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));

        // Ensure the positions are correct
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\"")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\"")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\"")));

        // Ensure the types are correct
        ASSERT_TRUE(regex_search(xml,
                wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"beta\"/><item.* type=\"beta\"/></aqua>")));

    }

    void PopulateAllTypes(Aquarium *aquarium)
    {
        auto fish1 = make_shared<FishBeta>(aquarium);
        fish1->SetLocation(100, 200);
        aquarium->Add(fish1);

        auto fish2 = make_shared<FishBubbles>(aquarium);
        fish2->SetLocation(400, 400);
        aquarium->Add(fish2);

        auto fish3 = make_shared<FishMagikarp>(aquarium);
        fish3->SetLocation(600, 100);
        aquarium->Add(fish3);

        //add in castle
        auto castle = make_shared<DecorCastle>(aquarium);
        castle->SetLocation(500,500);
        aquarium->Add(castle);

    }

    void TestAllTypes(wxString filename)
    {
        cout << "Temp file: " << filename << endl;

        auto xml = ReadFile(filename);
        cout << xml << endl;

        // Ensure four items
        ASSERT_TRUE(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*<item.*</aqua>")));

        // Ensure the positions are correct
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\"")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\"")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\"")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"500\" y=\"500\"")));

        // Ensure the types are correct
        ASSERT_TRUE(regex_search(xml,
                wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"bubbles\"/><item.* type=\"magikarp\"/><item.* type=\"castle\"/></aqua>")));
    }

};

TEST_F(AquariumTest, Construct){
    Aquarium aquarium;
}

TEST_F(AquariumTest, HitTest) {
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

TEST_F(AquariumTest, Save) {
    // Create a path to temporary files
    auto path = TempPath();

    // Create an aquarium
    Aquarium aquarium;

    //
    // First test, saving an empty aquarium
    //
    auto file1 = path + L"/test1.aqua";
    aquarium.Save(file1);

    TestEmpty(file1);

    //
    // Now populate the aquarium
    //

    PopulateThreeBetas(&aquarium);

    auto file2 = path + L"/test2.aqua";
    aquarium.Save(file2);

    TestThreeBetas(file2);

    //
    // Test all types
    //
    Aquarium aquarium3;
    PopulateAllTypes(&aquarium3);

    auto file3 = path + L"/test3.aqua";
    aquarium3.Save(file3);

    TestAllTypes(file3);


}

TEST_F(AquariumTest, Clear)
{
    // Create a path to temporary files
    auto path = TempPath();



    //
    // Test all types
    //
    Aquarium aquarium4;

    auto file4 = path + L"/test4.aqua";

    //Test initial file is empty
    TestEmpty(file4);

    //add items to aqurium
    PopulateAllTypes(&aquarium4);

    //save the file
    aquarium4.Save(file4);

    //test to ensure items are in the xml file
    TestAllTypes(file4);

    //clear the mItems vector
    aquarium4.Clear();

    //save the cleared changes
    aquarium4.Save(file4);

    //retest to ensure file is empty
    TestEmpty(file4);


}

TEST_F(AquariumTest, Load) {
    // Create a path to temporary files
    auto path = TempPath();

    // Create an aquarium
    Aquarium aquarium;
    Aquarium aquarium2;

    //
    // First test, saving an empty aquarium
    //
    auto file1 = path + L"/test1.aqua";
    aquarium.Save(file1);

    TestEmpty(file1);

    aquarium2.Load(file1);
    aquarium2.Save(file1);
    TestEmpty(file1);

    //
    // Now populate the aquarium
    //

    PopulateThreeBetas(&aquarium);

    auto file2 = path + L"/test2.aqua";
    aquarium.Save(file2);

    TestThreeBetas(file2);

    aquarium2.Load(file2);
    aquarium2.Save(file2);
    TestThreeBetas(file2);

    //
    // Test all types
    //
    Aquarium aquarium3;
    PopulateAllTypes(&aquarium3);

    auto file3 = path + L"/test3.aqua";
    aquarium3.Save(file3);

    TestAllTypes(file3);

    aquarium2.Load(file3);
    aquarium2.Save(file3);
    TestAllTypes(file3);
}