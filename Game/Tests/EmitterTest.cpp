/**
 * @file Emitter.cpp
 * @author Tate Moorhouse
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <Emitter.h>
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <wx/filename.h>

using namespace std;

const unsigned int RandomSeed = 1238197374;

TEST(EmitterTest, Construct){
    Game game;
    game.GetRandom().seed(RandomSeed);
    Emitter emitter(&game);
}

TEST(EmitterTest, SetType){
    Game game;
    game.GetRandom().seed(RandomSeed);
    Emitter emitter(&game);

    emitter.SetType(&game, 0, 1);

    ASSERT_TRUE(emitter.GetType());
}

TEST(EmitterTest, SetAttributeNumber){
    Game game;
    game.GetRandom().seed(RandomSeed);
    Emitter emitter(&game);

    emitter.SetAttributeNumber(&game, 0, 4);
    ASSERT_LE(emitter.GetAttributeNumber(), 3);
    ASSERT_GE(emitter.GetAttributeNumber(), 0 );
}

TEST(EmitterTest, SetOperationNumber){
    Game game;
    game.GetRandom().seed(RandomSeed);
    Emitter emitter(&game);

    emitter.SetOperationNumber(&game, 0, 4);
    ASSERT_LE(emitter.GetOperationNumber(), 3);
    ASSERT_GE(emitter.GetOperationNumber(), 0 );
}

TEST(EmitterTest, SetItemBad){
    Game game;
    game.GetRandom().seed(RandomSeed);
    Emitter emitter(&game);

    emitter.SetItemBad(&game, 0, 3);
    ASSERT_LE(emitter.GetItemBad(), 2);
    ASSERT_GE(emitter.GetItemBad(), 0 );
}

TEST(EmitterTest, CreateUml){
    Game game;
    game.GetRandom().seed(RandomSeed);
    Emitter emitter(&game);
    emitter.CreateUml(&game);

    ASSERT_EQ(2, game.GetItems().size());
}
