/**
 * @file Goat.cpp
 * @author nick
 */

#include "Goat.h"

#include <iostream>
using namespace std;


/**
 * Obtain information from the user about this goat.
 *
 * Asks the user for the information that describes a goat.
 */
void Goat::ObtainGoatInformation()
{
    cout << endl;
    cout << "Input information about the goat" << endl;

    // Obtain the name.
    cout << "Name: ";
    cin >> mName;

    // Obtain the type using a menu. We have a loop so
    // we can handle errors.
    bool valid = false;
    while (!valid) {
        cout << "1: Nanny" << endl;
        cout << "2: Billy" << endl;
        cout << "3: Wether" << endl;
        cout << "4: Male Kid" << endl;
        cout << "5: Female Kid" << endl;
        cout << "Enter selection and return: ";
        int option;
        cin >> option;
        if (!cin) {
            // We have an error. Clear the input and try again
            cin.clear();
            cin.ignore();
            continue;
        }

        switch (option) {
        case 1:
            mType = Type::Nanny;
            valid = true;
            break;

        case 2:
            mType = Type::Billy;
            valid = true;
            break;

        case 3:
            mType = Type::Wether;
            valid = true;
            break;

        case 4:
            mType = Type::maleKid;
            valid = true;
            break;

        case 5:
            mType = Type::femaleKid;
            valid = true;
            break;
        }

    }
}



/**
 * Display information about this goat.
 */
void Goat::DisplayAnimal()
{
    cout << mName << ": ";
    switch (mType)
    {
    case Type::Nanny:
        cout << "Nanny" << endl;
        break;

    case Type::Billy:
        cout << "Billy" << endl;
        break;

    case Type::Wether:
        cout << "Wether" << endl;
        break;

    case Type::maleKid:
        cout << "Male Kid" << endl;
        break;

    case Type::femaleKid:
        cout << "Female Kid" << endl;
        break;

    }
}

/**
 * If the goat is a Nanny or Female Kid
 *
 * @return true
 */
bool Goat::IsFemale()
{

    if (mType == Type::Nanny || mType == Type::femaleKid)
    {
        return true;
    }
    else
    {
        return false;
    }
}