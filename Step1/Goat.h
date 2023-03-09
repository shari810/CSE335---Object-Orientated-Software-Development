/**
 * @file Goat.h
 * @author nicholas shari
 *
 *
 * Declaration of goat class.
 */

#ifndef STEP1_GOAT_H
#define STEP1_GOAT_H

#include <string>
#include "Animal.h"

/**
 * This class describes a goat.
 */

class Goat : public Animal{

public:
    /// The types of goat we can have on our farm
    enum class Type {Nanny, Billy, Wether, maleKid, femaleKid};

    void ObtainGoatInformation();

    void DisplayAnimal();

    bool IsFemale() override;

private:
    /// The goats's name
    std::string mName;

    /// The type of goat: Nanny, Billy, Wether, MaleKid, FemaleKid
    Type mType =Type::Nanny;


};

#endif //STEP1_GOAT_H
