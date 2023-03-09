/**
 * @file Cow.h
 * @author nicholas shari
 *
 * Class that describes a Farm.
 *
 * This class describes a cow.
 */

#ifndef STEP1_COW_H
#define STEP1_COW_H

#include <string>

#include "Animal.h"

/**
 * Class that describes a cow
 *
 * Holds type of cow, name, milk production values.
 */
class Cow : public Animal {

public:
    /// The types of cow we can have on our farm
    enum class Type {Bull, BeefCow, MilkCow};

    void ObtainCowInformation();

    void DisplayAnimal();

    bool IsFemale() override;

private:
    /// The cow's name
    std::string mName;

    /// The type of cow: Bull, BeefCow, or MilkCow
    Type mType =Type::MilkCow;

    /// The milk production for a cow in gallons per day
    double mMilkProduction = 0;

};

#endif //STEP1_COW_H
