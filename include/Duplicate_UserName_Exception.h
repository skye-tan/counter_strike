
#include "Duplicate_Attribute_Exception.h"

#ifndef DUPLICATE_USERNAME_EXCEPTION_H
#define DUPLICATE_USERNAME_EXCEPTION_H

/**
 * @brief Exception for when a duplicate attribute has been given
 * 
 */
class Duplicate_UserName_Exception : public Duplicate_Attribute_Exception {

public:

    /**
     * @brief Construct a new Duplicate_UserName_Exception object
     * 
     */
    Duplicate_UserName_Exception();

};

#endif