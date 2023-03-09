/**
 * @file SpartyFactory.h
 * @author nicholas shari
 *
 *
 */

#ifndef CANADIANEXPERIENCE_SPARTYFACTORY_H
#define CANADIANEXPERIENCE_SPARTYFACTORY_H

class Actor;

/**
 * A factory class that builds Sparty
 */

class SpartyFactory {
private:

public:

    std::shared_ptr<Actor> Create(std::wstring imagesDir);

};

#endif //CANADIANEXPERIENCE_SPARTYFACTORY_H
