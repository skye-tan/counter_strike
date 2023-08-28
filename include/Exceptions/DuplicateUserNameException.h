
#include "DuplicateAttributeException.h"

#ifndef DUPLICATEUSERNAMEEXCEPTION_H
#define DUPLICATEUSERNAMEEXCEPTION_H

/**
 * @brief Exception for when a duplicate attribute has been given
 * 
 */
class DuplicateUserNameException : public DuplicateAttributeException {

public:

    /**
     * @brief Construct a new DuplicateUserNameException object
     * 
     */
    DuplicateUserNameException();

};

#endif