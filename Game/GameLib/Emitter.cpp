/**
 * @file Emitter.cpp
 * @author Tate Moorhouse
 */

#include "pch.h"
#include "Emitter.h"

/// Maximum number to determine the probability of the uml type
const int MaxTypeNum = 10;

/// Minimum number to determine the probability of the uml type
const int MinTypeNum = 0;

/// Maximum number to determine the number of attributes to have
const int MaxNum = 4;

/// Minimum number to determine the number of attributes to have
const int MinNum = 0;

/// Maximum number to determine which part of uml will be bad
const int MaxBadNum =3 ;

/// Minimum number to determine which part of uml will be bad
const int MinBadNum = 0;

/// Minimum number to determine the x location of uml
const int MinX = -600;

/// Maximum number to determine the x location of uml
const int MaxX = 100;



/**
 * Constructor
 */
Emitter::Emitter(Game *game)
{
    mGame = game;
}

/**
 * Randomizes the construction of the uml
 */
 void Emitter::RandomizeValues(){
    SetType(mGame, MaxTypeNum, MinTypeNum);
    SetAttributeNumber(mGame, MaxNum, MinNum);
    SetOperationNumber(mGame, MaxNum, MinNum);
    SetItemBad(mGame, MaxBadNum, MinBadNum);
    SetX(mGame, MaxX, MinX);
 }


/**
 * Randomly decide if the uml will be good or bad
 *
 * @param game the reference to the game this uml belongs to
 * @param maxNum the max number for the random number generator
 * @param minNum the min number for the random number generator
 */
void Emitter::SetType(Game *game, int maxNum, int minNum)
{
    std::uniform_real_distribution<> distributionX(minNum, maxNum);
    int randomNum = distributionX(game->GetRandom());
    if (randomNum >= 5)
    {
        mBad = false;
    }
}

/**
 * Randomly decide the number of attributes a uml will have
 *
 * @param game the reference to the game this uml belongs to
 * @param maxNum the max number for the random number generator
 * @param minNum the min number for the random number generator
 */
void Emitter::SetAttributeNumber(Game *game, int maxNum, int minNum) {
    std::uniform_real_distribution<> distributionX(minNum, maxNum);
    mAttributeNum = distributionX(game->GetRandom());
}

/**
 * Randomly decide which item will be bad
 *
 * @param game the reference to the game this uml belongs to
 * @param maxNum the max number for the random number generator
 * @param minNum the min number for the random number generator
 */
 void Emitter::SetItemBad(Game *game, int maxNum, int minNum)
{
    std::uniform_real_distribution<> distributionX(minNum, maxNum);
    mItemBad= distributionX(game->GetRandom());
}

/**
 * Randomly decide the number of operations a uml will have
 *
 * @param game the reference to the game this uml belongs to
 * @param maxNum the max number for the random number generator
 * @param minNum the min number for the random number generator
 */
void Emitter::SetOperationNumber(Game *game, int maxNum, int minNum) {
    std::uniform_real_distribution<> distributionX(minNum, maxNum);
    mOperationNum = distributionX(game->GetRandom());
}

/**
 * Randomly decide the x spawn location of a uml
 *
 * @param game the reference to the game this uml belongs to
 * @param maxX the max number for the random number generator
 * @param minX the min number for the random number generator
 */
 void Emitter::SetX(Game *game, int maxX, int minX){
    std::uniform_real_distribution<> distributionX(minX, maxX);
    mX = distributionX(game->GetRandom());
 }

/**
 * Creates a uml object based on the randomly generated numbers
 * @return uml object to be added to the game
 */
void Emitter::CreateUml(Game *game)
{
    RandomizeValues();
    // The contents from the xml
    Content contents = game->GetContents();
    // A pointer for the item we are loading
    mTempUml = std::make_shared<Uml>(game);
    // get bad names
    std::vector<std::vector<wxString>> badNames = contents.GetBadNames();
    // shuffle the list of names
    std::shuffle(badNames.begin(), badNames.end(), game->GetRandom());
    // get bad attributes
    std::vector<std::vector<wxString>> badAttributes = contents.GetBadAttributes();
    // shuffle bad Attributes
    std::shuffle(badAttributes.begin(), badAttributes.end(), game->GetRandom());
    // get bad operations
    std::vector<std::vector<wxString>> badOperations = contents.GetBadOperations();
    // shuffle bad Operations
    std::shuffle(badOperations.begin(), badOperations.end(), game->GetRandom());
    // get good names
    std::vector<wxString> goodNames = contents.GetGoodNames();
    // shuffle good names
    std::shuffle(goodNames.begin(), goodNames.end(), game->GetRandom());
    // get good attributes
    std::vector<wxString> goodAttributes = contents.GetGoodAttributes();
    // shuffle good attributes
    std::shuffle(goodAttributes.begin(), goodAttributes.end(), game->GetRandom());
    // get good operations
    std::vector<wxString> goodOperations = contents.GetGoodOperations();
    // shuffle good operations
    std::shuffle(goodOperations.begin(), goodOperations.end(), game->GetRandom());

    std::vector<wxString> attributesAdded = {};
    std::vector<wxString> operationsAdded = {};

    // if the random generator decides the uml should be bad
    if (GetType())
    {
        // int representing which of the 3 characteristics of a class should be bad
        int itemBad = GetItemBad();
        // if itemBad is 0 then the name characteristic of the uml will be bad
        if (itemBad == 0 || (itemBad == 1 && mAttributeNum == 0) || (itemBad == 2 && mOperationNum == 0))
        {
            // Set the bad name
            mTempUml->SetBadMessage(badNames[0][0]);
            mTempUml->SetName(badNames[0][1]);

            // set good attributes if there are supposed to be attributes
            if (mAttributeNum != 0){
                AddUmlAttributes(mTempUml, mAttributeNum, attributesAdded,
                                 goodAttributes, true);
            } else {
                mTempUml->SetAttributes(attributesAdded);
            }
            // add good operations if there are supposed to be
            if (mOperationNum != 0){
                AddUmlAttributes(mTempUml, mOperationNum, operationsAdded,
                                 goodOperations, false);
            } else{
                mTempUml->SetOperations(operationsAdded);
            }
        }
        else if (itemBad == 1){
            // set good name
            mTempUml->SetName(goodNames[0]);
            // set one bad attribute
            mTempUml->SetBadMessage(badAttributes[0][0]);
            attributesAdded.push_back(badAttributes[0][1]);
            // add good attributes
            if (mAttributeNum != 1){
                AddUmlAttributes(mTempUml, mAttributeNum - 1, attributesAdded,
                                 goodAttributes, true);
            } else{
                mTempUml->SetAttributes(attributesAdded);
            }
            // add good operations
            if (mOperationNum != 0){
                AddUmlAttributes(mTempUml, mOperationNum, operationsAdded,
                                 goodOperations, false);
            }
        }
        else if (itemBad == 2){
            // set good name
            mTempUml->SetName(goodNames[0]);

            // set good attributes
            if (mAttributeNum != 0){
                AddUmlAttributes(mTempUml, mAttributeNum, attributesAdded, goodAttributes, true);
            }
            else{
                mTempUml->SetAttributes(attributesAdded);
            }

            // set first bad operation
            mTempUml->SetBadMessage(badOperations[0][0]);
            operationsAdded.push_back(badOperations[0][1]);

            // set remaining operations
            if (mOperationNum != 1){
                AddUmlAttributes(mTempUml, mOperationNum - 1, operationsAdded,
                                 goodOperations, false);
            }
            mTempUml->SetOperations(operationsAdded);
        }
    }
    // if the uml is supposed to be good
    else
    {
        // sets the uml type to good
        mTempUml->SetBad(mBad);

        mTempUml->SetName(goodNames[0]);

        if (mAttributeNum != 0){
            AddUmlAttributes(mTempUml, mAttributeNum, attributesAdded, goodAttributes, true);
        }
        else{
            mTempUml->SetAttributes(attributesAdded);
        }
        // loop for how many operations there should be
        if (mOperationNum != 0){
            AddUmlAttributes(mTempUml, mOperationNum, operationsAdded, goodOperations, false);
        }
        else{
            mTempUml->SetOperations(operationsAdded);
        }
    }
    mTempUml->SetLocation(mX,mY);
    game->AddItem(mTempUml);
}

/**
 * Function to set uml attributes
 * @param uml uml to add contents to
 * @param num number to loop
 * @param add list of attributes to add
 * @param content the content from the game contents
 * @param type bool determining which uml object to set
 */
 void Emitter::AddUmlAttributes(std::shared_ptr<Item> uml, int num, std::vector<wxString> add, std::vector<wxString> content, bool type){
     for (int i = 0; i < num; i++){
         add.push_back(content[i]);
     }
     if (type){
         uml->SetAttributes(add);
     }
     else{
         uml->SetOperations(add);
     }
 }

