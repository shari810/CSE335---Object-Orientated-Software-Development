/**
 * @file Scorestreak.h
 * @author Jonathan Ayoub
 *
 *
 */

#ifndef PROJECT1_SCORESTREAK_H
#define PROJECT1_SCORESTREAK_H

#include "Item.h"
#include <memory>

class Game;

/**
 * Scorestreak class to provide functionality when certain in game metrics are met.
 */
class Scorestreak {
private:
    /// The game the item is contained in
    Game *mGame;
    ///Counts the current correct streak of UMLs hit or good UMLs avoided
    int mStreakCounter;
    ///Boolean for 5-streak
    bool mFirstStreakUsed = false;
    ///Boolean for 10-streak
    bool mSlowMotionUsed = false;

public:

    Scorestreak() = delete;
    Scorestreak(const Scorestreak &) = delete;
    void operator=(const Scorestreak &) = delete;

    Scorestreak(Game *game);
    void Draw(wxGraphicsContext *graphics);

    void Update(double elapsed);

    void IncrementCounter();

    /**
     * Getter for mStreakCounter
     * @return mStreakCounter
     */
    int GetIncrementCounter() const { return mStreakCounter; }


    /**
     * Removes bad class from the screen
     * @param items items container from game
     */
    void RemoveBadStreak(std::vector<std::shared_ptr<Item>>* items);

    /**
     * Will nuke all the UML's on screen except pen/harold
     * @return activate the 15-streak clear all
     */
    bool NukeStreak();
    /**
     * Set streak to zero
     */
    void StreakBroke();

    /**
     * Slow motion mode will turn off and return game to normal state.
     * @param game game the scorestreak was activated in
     */
    void SlowMotionStreakDeactivate(Game game);

    /**
     * Getter for mSlowMotionUsed
     * @return mSlowMotionUsed
     */
    bool GetSlowMotionUsed() const {return mSlowMotionUsed;}

    /**
     * Slow motion mode will make speed slower for 5 seconds
     * @param game game the scorestreak is activated in
     */
    void SlowMotionStreakActivate(Game game);
};


#endif //PROJECT1_SCORESTREAK_H
