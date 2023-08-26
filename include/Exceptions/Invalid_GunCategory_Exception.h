
#include "Invalid_Attribute_Exception.h"

#ifndef INVALID_GUNCATEGORY_EXCEPTION_H
#define INVALID_GUNCATEGORY_EXCEPTION_H

/**
 * @brief Exception for when a given gun's name isn't valid for the specified team
 * 
 */
class Invalid_GunCategory_Exception : public Invalid_Attribute_Exception {

public:

    /**
     * @brief Construct a new Invalid_GunCategory_Exception object
     * 
     */
    Invalid_GunCategory_Exception();

};

#endif