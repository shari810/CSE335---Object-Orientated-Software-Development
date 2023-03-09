/**
 * @file NicholasTylerShariView.h
 * @author nicholas shari
 *
 * view the me
 */

#ifndef NICHOLASTYLERSHARI_NICHOLASTYLERSHARIVIEW_H
#define NICHOLASTYLERSHARI_NICHOLASTYLERSHARIVIEW_H



/**
 * View class for our white view panel and drawing
 */
class NicholasTylerShariView : public wxWindow {
private:

    void OnPaint(wxPaintEvent& event);

public:

    void Initialize(wxFrame* parent);


};

#endif //NICHOLASTYLERSHARI_NICHOLASTYLERSHARIVIEW_H
