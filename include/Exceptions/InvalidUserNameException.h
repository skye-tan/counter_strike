
#include "InvalidAttributeException.h"

#ifndef INVALIDUSERNAMEEXCEPTION_H
#define INVALIDUSERNAMEEXCEPTION_H

/**
 * @brief Exception for when a given username doesn't exist
 * 
 */
class InvalidUserNameException : public InvalidAttributeException {

public:

    /**
     * @brief Construct a new InvalidUserNameException object
     * 
     */
    InvalidUserNameException();

};

#endif