/**
 * @file ViewTimeline.cpp
 * @author Charles B. Owen
 */

#include "pch.h"

#include <wx/dcbuffer.h>
#include <wx/xrc/xmlres.h>
#include <sstream>
#include "ViewTimeline.h"
#include "TimelineDlg.h"
#include "Picture.h"
#include "MainFrame.h"
#include <memory>



// * @param imagesDir The directory containing the program images

/// Y location for the top of a tick mark
const int TickTop = 15;

/// The spacing between ticks in the timeline
const int TickSpacing = 4;

/// The length of a short tick mark
const int TickShort = 10;

/// The length of a long tick mark
const int TickLong = 20;

/// Size of the tick mark labels
const int TickFontSize = 15;

/// Space to the left of the scale
const int BorderLeft = 10;

/// Space to the right of the scale
const int BorderRight = 10;

/// Filename for the pointer image
const std::wstring PointerImageFile = L"/pointer.png";

/**
 * Constructor
 * @param parent The main wxFrame object

 */
ViewTimeline::ViewTimeline(MainFrame* parent) :
    wxScrolledCanvas(parent,
            wxID_ANY,
            wxDefaultPosition,
            wxSize(100, Height),
            wxBORDER_SIMPLE)
{
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    //int width = ( (this->GetPicture()->GetTimeline()->GetNumFrames()) * TickSpacing ) + BorderLeft + BorderRight;
    Bind(wxEVT_PAINT, &ViewTimeline::OnPaint, this);
    Bind(wxEVT_LEFT_DOWN, &ViewTimeline::OnLeftDown, this);
    Bind(wxEVT_LEFT_UP, &ViewTimeline::OnLeftUp, this);
    Bind(wxEVT_MOTION, &ViewTimeline::OnMouseMove, this);

    parent->Bind(wxEVT_COMMAND_MENU_SELECTED,
            &ViewTimeline::OnEditTimelineProperties, this,
            XRCID("EditTimelineProperties"));

    std::wstring imdir = parent->GetImageDir();
    mPointerImage = std::make_unique<wxImage>(imdir + PointerImageFile, wxBITMAP_TYPE_ANY);

}


/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void ViewTimeline::OnPaint(wxPaintEvent& event)
{
    int width = ( (this->GetPicture()->GetTimeline()->GetNumFrames()) * TickSpacing ) + BorderLeft + BorderRight;
    SetVirtualSize(width, Height);
    SetScrollRate(1, 0);

    wxAutoBufferedPaintDC dc(this);
    DoPrepareDC(dc);
    wxBrush background(*wxWHITE);
    dc.SetBackground(background);
    dc.Clear();

    // Create a graphics context
    auto graphics = std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create( dc ));

    wxPen pen(wxColour(128, 128, 128), 1);
    graphics->SetPen(pen);
    /**
    graphics->DrawRectangle(10, 10, 200, 60);

    wxFont font(wxSize(0, 16),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);
    graphics->SetFont(font, *wxBLACK);
    graphics->DrawText(L"Timeline!", 15, 15);
    */
    //auto time = wxDateTime::Now();
    //auto timeStr = time.Format(L"%x %T");
    //graphics->DrawText(timeStr, 15, 40);

    int tickNum = 0;
    int x1 = BorderLeft;
    int y1 = TickTop;
    int x2 = BorderLeft;
    int y2Short = TickTop + TickShort;
    int y2Long = TickTop + TickLong;
    while(tickNum < this->GetPicture()->GetTimeline()->GetNumFrames()){
        bool onSecond = (tickNum % this->GetPicture()->GetTimeline()->GetFrameRate()) == 0;

        if (onSecond) {
            graphics->StrokeLine(x1, y1, x2, y2Long);
            // Convert the tick number to seconds in a string
            std::wstringstream str;
            str << tickNum / this->GetPicture()->GetTimeline()->GetFrameRate();
            std::wstring wstr = str.str();

            wxFont font(wxSize(0, TickFontSize),
                    wxFONTFAMILY_SWISS,
                    wxFONTSTYLE_NORMAL,
                    wxFONTWEIGHT_NORMAL);
            graphics->SetFont(font, *wxBLACK);

            double w, h;
            graphics->GetTextExtent(wstr, &w, &h);
            graphics->DrawText(wstr,x1-(w/2),y2Long);
        }
        else{
            graphics->StrokeLine(x1, y1, x2, y2Short);
        }
        tickNum++;
        x1+=TickSpacing;
        x2+=TickSpacing;
    }
    if(mPointerBitmap.IsNull())
    {
        mPointerBitmap = graphics->CreateBitmapFromImage(*mPointerImage);
    }
    graphics->DrawBitmap(mPointerBitmap,
            this->GetPicture()->GetTimeline()->GetCurrentTime(), 10,
            mPointerImage->GetWidth(),
            mPointerImage->GetHeight());
}

/**
 * Handle the left mouse button down event
 * @param event
 */
void ViewTimeline::OnLeftDown(wxMouseEvent &event)
{

    GetPicture()->GetTimeline()->SetCurrentTime(5);
    GetPicture()->UpdateObservers();
}

/**
* Handle the left mouse button up event
* @param event
*/
void ViewTimeline::OnLeftUp(wxMouseEvent &event)
{
    OnMouseMove(event);
}

/**
* Handle the mouse move event
* @param event
*/
void ViewTimeline::OnMouseMove(wxMouseEvent &event)
{

}

/**
 * Force an update of this window when the picture changes.
 */
void ViewTimeline::UpdateObserver()
{
    Refresh();
}

/**
 * Handle an Edit>Timeline Properties... menu option
 * @param event The menu event
 */
void ViewTimeline::OnEditTimelineProperties(wxCommandEvent& event)
{



    TimelineDlg dlg(this->GetParent(), this->GetPicture()->GetTimeline() );
    if(dlg.ShowModal() == wxID_OK)
    {
        // The dialog box has changed the Tmeline settings
        UpdateObserver();
    }
}
