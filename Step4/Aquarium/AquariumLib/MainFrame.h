/**
 * @file MainFrame.h
 * @author nicholas shari
 *
 * The top-level (main) frame of the application
 */

#ifndef AQUARIUM_MAINFRAME_H
#define AQUARIUM_MAINFRAME_H


/**
 * The top-level (main) frame of the application
 */
class MainFrame : public wxFrame{

public:

    void Initialize();

private:

    void OnExit(wxCommandEvent& event);

    void OnHelp(wxCommandEvent& event);
};

#endif //AQUARIUM_MAINFRAME_H
