/**
 * @file PlayerTest.cpp
 * @author nicholas shari
 */

#include <pch.h>
#include "gtest/gtest.h"


#include <Player.h>
#include <Game.h>
#include <Item.h>
#include <wx/graphics.h>

using namespace std;

TEST(PlayerTest, Swap)
{
    Game game;

    wxString harold = (L"images/harold.png");
    wxString bob =  (L"images/bob.png");
    wxString sparty = (L"images/sparty.png");
    wxString vinnie = (L"images/vinnie.png");

    Player haroldPlayer(&game,harold);
    Player player1(&game,harold);
    Player player2(&game,harold);
    Player player3(&game,harold);


    //ensure the files start the same
    ASSERT_EQ(haroldPlayer.GetImageFileName(),player1.GetImageFileName());
    ASSERT_EQ(haroldPlayer.GetImageFileName(),player2.GetImageFileName());
    ASSERT_EQ(haroldPlayer.GetImageFileName(),player3.GetImageFileName());


    player1.SwapImageBob();
    //check to see if the image is no longer harold
    ASSERT_NE(haroldPlayer.GetImageFileName(),player1.GetImageFileName());

    player2.SwapImageSparty();
    //check to see if the image is no longer harold
    ASSERT_NE(haroldPlayer.GetImageFileName(),player2.GetImageFileName());

    player3.SwapImageVinnie();
    //check to see if the image is no longer harold
    ASSERT_NE(haroldPlayer.GetImageFileName(),player3.GetImageFileName());

}
