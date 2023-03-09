/**
 * @file GameView.cpp
 * @author Jonathan Ayoub
 */


#include "pch.h"
#include <wx/dcbuffer.h>
#include <wx/stdpaths.h>

#include "ids.h"
#include "GameView.h"

using namespace std;

///Frames used to create a consistent drawing appearance.
const int FrameDuration = 30;

/**
* Initialize the aquarium view class.
* @param parent The parent window for this class
*/
void GameView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY,
            wxDefaultPosition, wxDefaultSize,
            wxFULL_REPAINT_ON_RESIZE);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    Bind(wxEVT_PAINT, &GameView::OnPaint, this);
    Bind(wxEVT_MOTION, &GameView::OnMouseMove, this);
    Bind(wxEVT_LEFT_DOWN, &GameView::OnLeftDown, this);

    mTimer.SetOwner(this);
    mTimer.Start(FrameDuration);
    Bind(wxEVT_TIMER, &GameView::OnTimer, this);
    mStopWatch.Start();
}

/**
 *
 * @param mainFrame program window
 * @param menuBar menu bar a the top
 * @param variantMenu variant selection drop down menu
 * @param fileMenu file drop down menu
 */
void GameView::AddMenus(wxFrame* mainFrame, wxMenuBar* menuBar, wxMenu* variantMenu, wxMenu* fileMenu)
{

    //
    //  Variant menu options
    //
    variantMenu->Append(IDM_VARIANT_STANDARD, L"&Standard", L"Enable to show standard view", wxITEM_CHECK);
    variantMenu->Append(IDM_VARIANT_CUSTOM, L"&Custom", L"Enable to show custom view", wxITEM_CHECK);

    mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnVariantStandard, this, IDM_VARIANT_STANDARD);
    mainFrame->Bind(wxEVT_UPDATE_UI, &GameView::OnUpdateVariantStandard, this, IDM_VARIANT_STANDARD);
    mainFrame->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnVariantCustom, this, IDM_VARIANT_CUSTOM);
    mainFrame->Bind(wxEVT_UPDATE_UI, &GameView::OnUpdateVariantCustom, this, IDM_VARIANT_CUSTOM);
}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void GameView::OnPaint(wxPaintEvent& event)
{
    //  Update First then draw.
    // Compute the time that has elapsed
    // since the last call to OnPaint.
    auto newTime = mStopWatch.Time();
    auto elapsed = (double) (newTime-mTime)*0.001;
    mTime = newTime;

    if (newTime > 2)
    {
        mGame.UpdateUML(elapsed);
    }

    if (mGame.IsClicked()) {
        //
        // Update
        //
        mGame.PenUpdate(elapsed);
        mGame.TwoSecondsMinus(elapsed);
//        mTwoSecond -= elapsed;

        //
        // Reset Pen after 2 seconds
        //
//        if(mTwoSecond <= 0)
        if (mGame.GetTwoSeconds() <= 0)
        {
            mGame.SetTwoSeconds(2);
//            mTwoSecond = 2;
            mGame.SetClicked(false);
            mGame.GetPen()->SetLocation(0,900);
        }
        //
        // Reset Pen after it hits the border of play area
        //
        if (mGame.GetPen()->GetY() > 1000 ||  mGame.GetPen()->GetY() < 0 || mGame.GetPen()->GetX() > 625 ||  mGame.GetPen()->GetX() < -625)
        {
            mGame.SetTwoSeconds(2);
//            mTwoSecond = 2;
            mGame.SetClicked(false);
            mGame.GetPen()->SetLocation(0,900);
        }
    }

    // Create a double-buffered display context
    wxAutoBufferedPaintDC dc(this);

    wxBrush background(*wxBLACK);
    dc.SetBackground(background);
    dc.Clear();

    // Create a graphics context
    auto gc = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));

    wxRect rect = GetRect();
    auto scaleX = double(rect.GetWidth())/double(1250);
    auto scaleY = double(rect.GetHeight())/double(1000);
    mScale = min(scaleX, scaleY);
    mXOffset = 0;
    mYOffset = 0;
    if (rect.GetWidth()>1250*mScale) {
        mXOffset = (float) ((rect.GetWidth()-1250*mScale)/2);
    }
    if (rect.GetHeight()>1000*mScale) {
        mYOffset = (float) ((rect.GetHeight()-1000*mScale)/2);
    }
    if (!mCheck) {
        // Load background
        mBackground = std::make_shared<wxImage>(L"images/Background.jpg");
        mBackgroundBitmap = gc->CreateBitmapFromImage(*mBackground);
        gc->DrawBitmap(mBackgroundBitmap, mXOffset, mYOffset, 1250*mScale, 1000*mScale);
    }
    else {
        //Default Variant
        wxBrush rectBrush(*wxWHITE);
        gc->SetBrush(rectBrush);
        gc->DrawRectangle(mXOffset, mYOffset, 1250*mScale, 1000*mScale);
    }
    gc->Clip(mXOffset,mYOffset,1250*mScale,1000*mScale);
    // Tell the game class to draw
    mGame.OnDraw(gc.get(), rect.GetWidth(), rect.GetHeight());

}

/**
 * Menu event handler Variant>Standard menu option
 * @param event Menu event
 */
void GameView::OnVariantStandard(wxCommandEvent& event)
{
    if (mCheck) {
    }
    else { mCheck = !mCheck; }

}

/**
 * Update handler for Variant>Standard menu option
 * @param event Update event
 */
void GameView::OnUpdateVariantStandard(wxUpdateUIEvent& event)
{
    event.Check(mCheck);
}

/**
 * Menu event handler Variant>Custom menu option
 * @param event Menu event
 */
void GameView::OnVariantCustom(wxCommandEvent& event)
{
    if (!mCheck) {
    }
    else { mCheck = !mCheck; }
}

/**
 * Update handler for Variant>Custom menu option
 * @param event Update event
 */
void GameView::OnUpdateVariantCustom(wxUpdateUIEvent& event)
{
    event.Check(!mCheck);
}

/**
 * Handle movement of the mouse over the playing area
 *
 * @param event Mouse event
 */
void GameView::OnMouseMove(wxMouseEvent& event)
{
    mGame.UpdateMouseCoordinate(event.GetX(), event.GetY(), event);

    Refresh();
}

/**
 * Handle the left mouse button down event
 *
 * @param event
 */
void GameView::OnLeftDown(wxMouseEvent& event)
{
    if (!mGame.IsClicked()) {
        mGame.SetClicked(true);
    }
//    Refresh();

}

/**
 * Handle the timer event
 *
 * @param event Timer event
 */
void GameView::OnTimer(wxTimerEvent& event)
{
    Refresh();
}
