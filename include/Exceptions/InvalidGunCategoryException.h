
#include "InvalidAttributeException.h"

#ifndef INVALIDGUNCATEGORYEXCEPTION_H
#define INVALIDGUNCATEGORYEXCEPTION_H

/**
 * @brief Exception for when a given gun's name isn't valid for the specified team
 * 
 */
class InvalidGunCategoryException : public InvalidAttributeException {

public:

    /**
     * @brief Construct a new InvalidGunCategoryException object
     * 
     */
    InvalidGunCategoryException();

};

#endif