/**
 * @file Farm.h
 * @author nicholas shari
 *
 * Class that describes a Farm.
 *
 * This class holds a collection of animals that make
 * up the inventory of a farm.
 */

#ifndef STEP1_FARM_H
#define STEP1_FARM_H

#include <vector>

#include "Cow.h"


/**
 * Class that describes a farm.
 *
 * Holds a collection of animals that make up the farm
 * inventory.
 */
class Farm {

public:

    ~Farm();

    void AddAnimal(Animal *animal);

    void DisplayInventory();

    int TotalFemales();

private:
    /// A list with the inventory of all animals on the farm
    std::vector<Animal *> mInventory;

};

#endif //STEP1_FARM_H
