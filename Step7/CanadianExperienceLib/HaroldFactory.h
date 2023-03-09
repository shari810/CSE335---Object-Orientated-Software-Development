/**
 * @file HaroldFactory.h
 * @author nicholas shari
 *
 *
 */

#ifndef CANADIANEXPERIENCE_HAROLDFACTORY_H
#define CANADIANEXPERIENCE_HAROLDFACTORY_H


class Actor;

/**
 * A factory class that builds Harold.
 */
class HaroldFactory {
private:

public:

    std::shared_ptr<Actor> Create(std::wstring imagesDir);
};

#endif //CANADIANEXPERIENCE_HAROLDFACTORY_H
