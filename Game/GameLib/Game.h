/**
 * @file Game.h
 * @author Tate Moorhouse
 *
 * Class representing the actual game
 */

#ifndef PROJECT1_GAME_H
#define PROJECT1_GAME_H

#include <memory>
#include "Player.h"
#include "Scoreboard.h"
#include "Content.h"
#include "Emitter.h"
#include "Pen.h"
#include "Scorestreak.h"
#include <random>


/**
 * Game class that contains all the items to draw.
 */
class Game {
private:
    /// All of the items in game
    std::vector<std::shared_ptr<Item>> mItems;

    //std::shared_ptr<Emitter> mEmitter;

    ///Duration of the game
    double mDuration = 0;
    ///Previous duration before last elasped
    double mPreviousDuration = 0;
    ///Boolean for SlowMotion scorestreak
    bool mSlowMotionActivated = false;
    ///Duration of the slowmotion streak
    double mSlowMotionDuration = 0;
    ///Duration of the Destroyed streak
    double mDestroyedDuration = 0;
    ///Boolean for activation of Destroy streak
    bool mDestroying = false;

    /// Game area in virtual pixels
    const static int Width = 1250;

    /// Game area height in virtual pixels
    const static int Height = 1000;

    ///virtual pixels x-pos offset
    double mXOffset = 0;
    ///virtual pixels y-pos offset
    double mYOffset = 0;
    ///scale to transform the images in the window
    double mScale = 0;
    ///player item
    std::shared_ptr<Player> mPlayer;
    ///pen item
    std::shared_ptr<Item> mPen;
    ///UML content,attributes,values
    Content mContent;
    ///std::shared_ptr<Item> mTempUml;

    ///Pen x
    double mPx=-1;
    ///Pen y
    double mPy=-1;
    ///Clicked attribute for Pen
    bool mClicked = false;
    ///Scoreboard to be drawn
    std::shared_ptr<Scoreboard> mScoreboard;
    ///Scorestreak to be drawn and perks for 5,10,15 scorestreaks
    std::shared_ptr<Scorestreak> mScorestreak;

    /// Random number generator
    std::mt19937 mRandom;

    /// two seconds
    double mTwoSecond = 2;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    long mTime = 0;

public:
    Game();
    void Load(const wxString &filename);

    void OnDraw(wxGraphicsContext* graphics, int width, int height);

    void UpdateMouseCoordinate(int x, int y, wxMouseEvent& event);

    void Add(std::shared_ptr<Item> item);

    void PenUpdate(double elapsed);

    /**
     * Getter for mClicked
     * @return mClicked boolean value
     */
    bool IsClicked() const { return mClicked; }

    /**
     * Setter for mClicked
     * @param Clicked true or false value to determine if clicked
     */
    void SetClicked(bool Clicked) { mClicked = Clicked; }

    /**
     * Getter for mPx
     * @return mPx pen X
     */
    double GetPx() const { return mPx; }
    /**
     * Getter for mPy
     * @return mPy pen y
     */
    double GetPy() const { return mPy; }

    /**
     * Getter for the pen item
     * @return mPen pen item
     */
    std::shared_ptr<Item> GetPen() const { return mPen; }

    /**
     * getter for player item
     * @return mPlayer player item
     */
    std::shared_ptr<Player> GetPlayer() const { return mPlayer; }

    /**
     * Add item to the game item list
     * @param item the item to add
     */
    void AddItem(std::shared_ptr<Item> item) {mItems.push_back(item);}

    /**
     * Get the list of items in the game
     * @return the list of items in the game
     */
    std::vector<std::shared_ptr<Item>> GetItems(){return mItems;}

    /**
     * Get the contents loaded from the xml
     * @return contents of the game
     */
    Content GetContents(){return mContent;}

    /**
    * Get the random number generator
    * @return Pointer to the random number generator
    */
    std::mt19937 &GetRandom() {return mRandom;}

    //void DeleteItem(std::shared_ptr<Item> item);

    //bool UmlDestroyer(Item *PenDestroy);


    /**
     *
     * @param x
     * @param y
     * @return
     */
    std::shared_ptr<Item> HitTest(int x, int y);

    void UpdateUML(double elapsed);

    /**
     * Getter for mTwoSecond
     * @return mTwoSeconds
     */
    double GetTwoSeconds() { return mTwoSecond; }
    /**
     * Subtracts from mTwoSecond
     * @param number number to be subtract from mTwoSecond
     */
    void TwoSecondsMinus(double number) { mTwoSecond -= number; }
    /**
     * Sets mTwoSeconds to param
     * @param number Number to set mTwoSeconds to
     */
    void SetTwoSeconds(double number) { mTwoSecond = number; }

    void FindDestroyed();

};


#endif //PROJECT1_GAME_H
