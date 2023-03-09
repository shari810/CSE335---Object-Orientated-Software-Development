/**
 * @file Uml.h
 * @author Tate Moorhouse
 *
 * Class that represent UML Objects
 */
#ifndef PROJECT1_UML_H
#define PROJECT1_UML_H

#include "Item.h"
#include "Game.h"


/**
 * UML class to be displayed in the game and interacted with.
 */
class Uml : public Item {
private:
    ///Game the UML is generated in
    Game *mGame;
    ///Boolean if UML is bad
    bool mBad = true;
    ///string name for UML class
    wxString mName;
    ///Message if good UML is hit by pen
    wxString mBadMessage = L"Unfair!";
    ///container for all possible UML attributes
    std::vector<wxString> mAttributes;
    ///container for all possible UML operations
    std::vector<wxString> mOperations;
    ///boolean if UML is flagged as destroyed
    bool mDestroyed = false;
    ///boolean if uml has been counted
    bool mCounted = false;
    ///width of UML box
    double mBoxWid = 0;
    ///height of UML box
    double mBoxHit = 0;

    /// Current duration of production
    double mDuration = 0;

    /// UML speed in the X direction
    /// in pixels per second
    double mSpeedX;

    /// UML speed in the Y direction
    /// in pixels per second
    double mSpeedY;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    long mTime = 0;

protected:

public:
    /// Default constructor (disabled)
    Uml() = delete;

    /// Copy constructor (disabled)
    Uml(const Uml &) = delete;

    /// Assignment operator
    void operator=(const Uml &) = delete;

    Uml(Game *game);

    /**
     * Sets the uml to bad if needed
     * @param bad bool representing if the uml should be bad
     */
    void SetBad(bool bad) override {mBad = bad;}

    /**
     * Sets the name of the uml
     * @param name string representing the name
     */
    void SetName(wxString name) override {mName = name;}

    /**
     * Sets the attributes of the uml
     * @param attributes vector containing the attributes of the uml
     */
    void SetAttributes(std::vector<wxString> attributes) override {mAttributes = attributes;}

    /**
     * Sets the operations of the uml
     * @param operations vector containing the operations of the uml
     */
    void SetOperations(std::vector<wxString> operations) override {mOperations = operations;}

    /**
     * Sets the bad message to display when bad uml is hit
     * @param badMessage string to be displayed when bad uml is hit
     */
    void SetBadMessage(wxString badMessage) override {mBadMessage = badMessage;}

    void Draw(wxGraphicsContext *graphics) override;

    bool HitTest(int x, int y) override;

    /**
     * Returns the width of the uml
     * @return double representing width of the uml
     */
    double GetWid() override {return mBoxWid;}

    /**
     * Returns the height of the uml
     * @return double representing height of the uml
     */
    double GetHeight() override {return mBoxHit;}

    /**
     * Return the mBad value
     * @return boolean representing the bad/good value of the UML
     */
    bool GetBad() const override {return mBad;}

    /**
     * Sets the UMLs attribute to counted if it has been registered off screen.
     * @param counted
     */
    void SetCounted(bool counted) override {mCounted = counted;}

    /**
     * Returns the UMLs counted
     * @return mCounted representing if the UML was registered as off screen.
     */
    bool GetCounted() const override {return mCounted;}

    /**
     * Sets the destroyed boolean of the uml
     * @param destroyed true or false
     */
    void SetDestroyed(bool destroyed) override {mDestroyed = destroyed;}

    /**
     * Returns the destroyed state of the UML
     * @return bool representing destroyed state
     */
    bool GetDestroyed() override {return mDestroyed;}

    void DisplayDestroyedMessage() override;

    void Update(double elapsed) override;

    /**
     * Double the mSpeed of an item
     */
    void DoubleSpeed() override {mSpeedY = mSpeedY*10, mSpeedX = mSpeedX*10;}
    /**
    * Half the mSpeed of an item
    */
    void HalfSpeed() override {mSpeedY = mSpeedY/10, mSpeedX = mSpeedX/10;}
};


#endif //PROJECT1_UML_H
