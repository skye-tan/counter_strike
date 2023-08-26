
#include "Invalid_Attribute_Exception.h"

#ifndef INVALID_USERNAME_EXCEPTION_H
#define INVALID_USERNAME_EXCEPTION_H

/**
 * @brief Exception for when a given username doesn't exist
 * 
 */
class Invalid_UserName_Exception : public Invalid_Attribute_Exception {

public:

    /**
     * @brief Construct a new Invalid_UserName_Exception object
     * 
     */
    Invalid_UserName_Exception();

};

#endif