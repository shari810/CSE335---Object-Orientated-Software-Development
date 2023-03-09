/**
 * @file AquariumApp.h
 * @author nicholas shari
 *
 * Main interface for aquarium
 */

#ifndef AQUARIUM_AQUARIUMAPP_H
#define AQUARIUM_AQUARIUMAPP_H

#include <MainFrame.h>

/**
 * Aquarium inherited from wxApp to allow drawing.
 */
class AquariumApp : public wxApp {

public:
    bool OnInit() override;

private:

};

#endif //AQUARIUM_AQUARIUMAPP_H
