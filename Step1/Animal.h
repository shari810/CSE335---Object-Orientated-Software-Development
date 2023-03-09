/**
 * @file Animal.h
 * @author nicholas shari
 *
 * Base class for all animals.
 */

#ifndef STEP1_ANIMAL_H
#define STEP1_ANIMAL_H

/**
 * Base class for all animals.
 * All animals will be derived from this.
 */

class Animal {

public:
    virtual ~Animal();
    /** Display an animal. */
    virtual void DisplayAnimal() {}

    /** Determine if animal is female.
     *
     * @return dependant on animal type
     */
    virtual bool IsFemale() {return false;}


private:

};

#endif //STEP1_ANIMAL_H
