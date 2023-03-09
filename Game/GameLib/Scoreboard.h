/**
 * @file Scoreboard.h
 * @author nicholas shari
 *
 *
 */

#ifndef PROJECT1_SCOREBOARD_H
#define PROJECT1_SCOREBOARD_H

#include <memory>

class Game;

/**
 * Scoreboard class that displays the
 * Correct, Unfair, and Missed Scores
 */
class Scoreboard {
private:

    /// The game the item is contained in
    Game *mGame;

    ///Correct UMLs hit
    int mCorrect;
    ///Umls missed
    int mMissed;
    ///UMLs hit unfairly
    int mUnfair;


public:

    Scoreboard() = delete;
    Scoreboard(const Scoreboard &) = delete;
    void operator=(const Scoreboard &) = delete;

    Scoreboard(Game *game);
    void Draw(wxGraphicsContext *graphics);

    /**
     * Getter for mCorrect
     * @return mCorrect
     */
    int GetCorrect() const { return mCorrect; }

    void Update(double elapsed);


    void IncrementCorrect();

    void IncrementUnfair();

    void IncrementMissed();
};

#endif //PROJECT1_SCOREBOARD_H
