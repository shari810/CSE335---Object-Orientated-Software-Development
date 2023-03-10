/**
 * @file Emitter.h
 * @author Tate Moorhouse
 *
 * Class to handle the logic of emitting a UML
 */

#ifndef PROJECT1_EMITTER_H
#define PROJECT1_EMITTER_H

#include "Content.h"
#include "Uml.h"
#include "Game.h"


/**
 * Emitter class to construct UML and add it to the Game Item container to be displayed.
 */
class Emitter {
private:
    ///game class being used
    Game *mGame;
    ///temporary uml generated while adding to the game
    std::shared_ptr<Item> mTempUml;

    ///X-position
    int mX;
    ///Y-position
    int mY=0;
    ///Is the UML bad or good
    bool mBad = true;
    ///Number of attributes to have
    int mAttributeNum;
    ///Number of operations it has.
    int mOperationNum;
    ///Determine bad item attributes
    int mItemBad;

public:
    /**
     * Emitter constructor
     * @param game the game the emitter is connected to
     */
    Emitter(Game *game);

    void SetType(Game *game, int maxNum, int minNum);

    void SetAttributeNumber(Game *game, int maxNum, int minNum);

    void SetOperationNumber(Game *game, int maxNum, int minNum);

    /**
     * function to return the type generated by the emitter
     * @return bool representing the uml type
     */
    bool GetType(){return mBad;}

    /**
     * function to return the number of attributes generated
     * @return int representing number of attributes
     */
     int GetAttributeNumber(){return mAttributeNum;}

    /**
    * function to return the number of operations generated
    * @return int representing number of operations
    */
    int GetOperationNumber(){return mOperationNum;}

    /**
     * function to return the game the emitter is apart of
     * @return the game the emitter is apart of
     */
     Game * GetGame(){return mGame;}

    /**
     * function to return the Item to be bad
     * @return int indicating which item to make bad
     */
    int GetItemBad(){return mItemBad;}

    void SetItemBad(Game *game, int maxNum, int minNum);

    /**
     * Adds a UML to the game
     * @param game Game containing the UMLs
     */
    void CreateUml(Game *game);

    void AddUmlAttributes(std::shared_ptr<Item> uml, int num, std::vector<wxString> add, std::vector<wxString> content,
                          bool type);

    void RandomizeValues();

    void SetX(Game *game, int maxX, int minX);
};


#endif //PROJECT1_EMITTER_H
