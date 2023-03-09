/**
 * @file Farm.cpp
 * @author nicholas shari
 */

#include "Farm.h"

/**
 * Farm destructor
 */
Farm::~Farm()
{
    // Iterate over all of the animals, destroying
    // each one.
    for (auto animal : mInventory)
    {
        delete animal;
    }

    // And clear the list
    mInventory.clear();
}

/** Add an animal to the farm inventory.
 *
 * @param animal An animal to add to the inventory
 */
void Farm::AddAnimal(Animal *animal)
{
    mInventory.push_back(animal);
}

/**
 * Display the farm inventory.
 */
void Farm::DisplayInventory()
{
    for (auto animal : mInventory)
    {
        animal->DisplayAnimal();
    }
}


/**
 * Loops through the animal inventory
 * determines if each animal is a female.
 * Then increments the female count by +1.
 *
 * @return int number of females found
 */
int Farm::TotalFemales()
{
    int females = 0;
    for (auto animal : mInventory)
    {
        if (animal->IsFemale())
        {
            females +=1;
        }
    }
    return females;
}