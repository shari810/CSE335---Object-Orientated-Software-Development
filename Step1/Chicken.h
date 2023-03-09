/**
 * @file Chicken.h
 *
 * @author nicholas shari
 *
 * Declaration of the Chicken class.
 */

#ifndef STEP1_CHICKEN_H
#define STEP1_CHICKEN_H

#include <string>

#include "Animal.h"

/** Class that describes a chicken.
*/
class Chicken : public Animal
{
public:

    void ObtainChickenInformation();
    void DisplayAnimal();

    bool IsFemale() override;

private:
    /// The chicken's ID
    std::string mId;


};


#endif //STEP1_CHICKEN_H