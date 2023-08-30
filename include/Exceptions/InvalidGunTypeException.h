
#include "InvalidAttributeException.h"

#ifndef INVALIDGUNTYPEEXCEPTION_H
#define INVALIDGUNTYPEEXCEPTION_H

/**
 * @brief Exception for when a given gun doesn't exist
 * 
 */
class InvalidGunTypeException : public InvalidAttributeException {

public:

    /**
     * @brief Construct a new InvalidGunTypeException object
     * 
     */
    InvalidGunTypeException();

};

#endif