/**
 * @file Game.cpp
 * @author Tate Moorhouse
 */

#include "pch.h"
#include "Game.h"
#include "Player.h"
#include "GameView.h"
#include "Pen.h"

using namespace std;

///harold image to be drawn as player
wxString harold = (L"images/harold.png");
///sparty image to be drawn as player
wxString sparty = (L"images/sparty.png");


/**
 * Game Constructor
 */
Game::Game()
{
    auto xmlFile = L"data/uml.xml";
    Load(xmlFile);

    // Create a player
    mPlayer = make_shared<Player>(this, harold);
    mPlayer->SetLocation(0, 900);

    // Create a pen
    mPen = make_shared<Pen>(this);
    mPen->SetLocation(0,900);

    mItems.push_back(mPen);

    // Create Scoreboard
    mScoreboard = make_shared<Scoreboard>(this);

    // Create Scoreboard
    mScorestreak = make_shared<Scorestreak>(this);

    // Seed the random number generator
    std::random_device rd;
    mRandom.seed(rd());

}

/**
 * Load the aquarium from a .uml XML file.
 *
 * Opens the XML file and reads the nodes, creating items as appropriate.
 *
 * @param filename The filename of the file to load the game from.
 */
void Game::Load(const wxString& filename)
{

    wxXmlDocument xmlDoc;
    if (!xmlDoc.Load(filename)) {
        wxMessageBox(L"Unable to load Game file");
        return;
    }

    // Get the XML document root node
    auto root = xmlDoc.GetRoot();
    std::vector<wxString> badPair;

    //
    // Traverse the children of the root
    // node of the XML document in memory
    //
    auto child = root->GetChildren();
    for (; child; child = child->GetNext()) {
        // Travers each item in the children
        auto child2 = child->GetChildren();
        for (; child2; child2 = child2->GetNext()) {
            auto name = child2->GetName();
            wxXmlNode *theChild = child2->GetChildren();
            wxXmlAttribute *attribute = child2->GetAttributes();
            if (name==L"name") {
                // if attribute is true then the uml is bad
                if (attribute){
                    // if the child is not NULL you can pass the contents of the child
                    if (theChild){
                        badPair = {attribute->GetValue(), theChild->GetContent()};
                        mContent.AddBadName(badPair);
                    }
                        // if the child is NULL you need to pass empty string
                    else{
                        badPair = {attribute->GetValue(), L""};
                        mContent.AddBadName(badPair);
                    }
                }
                    // if the uml is supposed to be good add the content
                else{
                    mContent.AddGoodName(theChild->GetContent());
                }
            }
            else if (name==L"attribute") {
                if (attribute){
                    badPair = {attribute->GetValue(), theChild->GetContent()};
                    mContent.AddBadAttribute(badPair);
                }
                else{
                    mContent.AddGoodAttribute(theChild->GetContent());
                }
            }
            else if (name==L"operation") {
                if (attribute){
                    badPair = {attribute->GetValue(), theChild->GetContent()};
                    mContent.AddBadOperations(badPair);
                }
                else{
                    mContent.AddGoodOperations(theChild->GetContent());
                }
            }
            else if (name==L"inherit") {
            }
        }
    }
}

/**
 * Draw the game area
 * @param graphics The graphics context to draw on
 * @param width Width of the client window
 * @param height Height of the client window
 */
void Game::OnDraw(wxGraphicsContext* graphics, int width, int height)
{
    //
    // Automatic Scaling
    //
    auto scaleX = double(width)/double(Width);
    auto scaleY = double(height)/double(Height);
    mScale = min(scaleX, scaleY);

    mXOffset = width/2;
    mYOffset = 0;
    if (height>Height*mScale) {
        mYOffset = (float) ((height-Height*mScale)/2);
    }


    graphics->PushState();

    graphics->Translate(mXOffset, mYOffset);
    graphics->Scale(mScale, mScale);

    //
    // Draw in virtual pixels on the graphics context
    //
    // INSERT YOUR DRAWING CODE HERE

    // Draw the player
    mPlayer->Draw(graphics);

    // Draw the pen and UMLs
    for(auto item : mItems)
    {
        item->Draw(graphics);
    }
    if(IsClicked())
    {
        std::shared_ptr<Item> item = this->HitTest(mPen->GetX(), mPen->GetY());

    }

    mScoreboard->Draw(graphics);

    mScorestreak->Draw(graphics);

}


/**
* Get latest location of the mouse
* @param x X location clicked on
* @param y Y location clicked on
 * @param event movemeent event
 */
void Game::UpdateMouseCoordinate(int x, int y, wxMouseEvent& event)
{
    mPx = (x-mXOffset)/mScale;
    mPy = (y-mYOffset)/mScale;
}

/**
 * Add an item to the game
 *
 * @param item New item to add
 */
void Game::Add(std::shared_ptr<Item> item)
{
    mItems.push_back(item);
}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Game::PenUpdate(double elapsed)
{
    mItems[0]->Update(elapsed);
}


/**
 * Searches through the items in the game and checks if any UMLS
 * are in the destroyed state
 */
void Game::FindDestroyed(){
    if (!mDestroying){
        for (auto i = mItems.begin()+1; i!=mItems.end(); i++) {
            // if we find an uml that is destroyed
            if ((*i)->GetDestroyed()){
                // get the uml location from list
                auto loc = find(begin(mItems), end(mItems), (*i));
                // if the loc is not the end of the list begin duration
                // to display message
                if (loc != end(mItems)){
                    mDestroyedDuration = mDuration;
                    mDestroying = true;
                    if ((mDuration - mDestroyedDuration) >= 1 && loc != end(mItems)){
                        mItems.erase(loc);
                        mDestroyedDuration = 0;
                        mDestroying = false;
                    }
                    mScorestreak->RemoveBadStreak(&mItems);
                    break;
                }
            }
        }
    }
    else{
        for (auto i = mItems.begin()+1; i!=mItems.end(); i++) {
            auto loc = find(begin(mItems), end(mItems), (*i));
            if ((*i)->GetDestroyed()){
                if ((mDuration - mDestroyedDuration) >= 1 && loc != end(mItems)){
                    mItems.erase(loc);
                    mDestroyedDuration = 0;
                    mDestroying = false;
                }
                mScorestreak->RemoveBadStreak(&mItems);
                break;
            }
        }
    }

}

/**
 * Handles UML Update for animation
 * @param elapsed  The time since the last update
 */
void Game::UpdateUML(double elapsed)
{
    mDuration = mDuration+elapsed;

    this->FindDestroyed();

    if(mScorestreak->GetIncrementCounter() == 10 && mSlowMotionActivated == false && mScorestreak->GetSlowMotionUsed() == false)
    {
        mSlowMotionActivated = true;
        mScorestreak->SlowMotionStreakActivate(*this);
        mSlowMotionDuration = mDuration;
    }
    if( (mDuration-mSlowMotionDuration)>=5 && mSlowMotionActivated == true)
    {
        mScorestreak->SlowMotionStreakDeactivate(*this);
        mSlowMotionActivated = false;
    }


    //create emitters to make UMLs
    if ((mDuration-mPreviousDuration)>=2 && mSlowMotionActivated == false) {
        Emitter emitter(this);
        emitter.CreateUml(this);
        mPreviousDuration = mDuration;
    }
    else if((mDuration-mPreviousDuration)>=2 && mSlowMotionActivated == true)
    {
        mPreviousDuration = mDuration;
    }

    // temporary code to allow UMLs to continue moving
    // causes speed-up when mouse-clicked to activate pen
    // due to two updates being called simultaneously
    for (int i = 1; i <= size(mItems)-1; i++)
    {
        mItems[i]->Update(elapsed);

        //Height-50 only registers when the UML's Name is the only visible part left on screen.
        if ( (mItems[i]->GetY() >= Height-50) && (mItems[i]->GetBad()))
        {
            if (mItems[i]->GetCounted() == false) {
                mScoreboard->IncrementMissed();
                mItems[i]->SetCounted(true);
            }
        }
    }
}

std::shared_ptr<Item> Game::HitTest(int x, int y)
{
    bool found = false;
    for (auto i = mItems.begin()+1; i!=mItems.end(); i++) {
        if ((*i)->HitTest(x, y) && !((*i)->GetDestroyed()))
        {
            if ( (*i)->GetBad() )
            {
                mScoreboard->IncrementCorrect();
                mScorestreak->IncrementCounter();
            }
            else
            {
                mScoreboard->IncrementUnfair();
                mScorestreak->StreakBroke();
            }
            auto loc = find(begin(mItems), end(mItems), (*i));
            if (loc != end(mItems))
            {
                found = true;
                std::shared_ptr<Item> theItem = *loc;
                theItem->DisplayDestroyedMessage();
                theItem->SetDestroyed(true);
                break;
            }
        }
    }
    if (found){
        if (mScorestreak->NukeStreak()){
            mItems.clear();
            mItems.push_back(mPen);
        }
        this->SetTwoSeconds(2);
        this->SetClicked(false);
        this->GetPen()->SetLocation(0,900);
        return nullptr;
    }

    return nullptr;
}