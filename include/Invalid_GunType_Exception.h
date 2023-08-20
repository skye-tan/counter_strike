
#include "Invalid_Attribute_Exception.h"

#ifndef INVALID_GUNTYPE_EXCEPTION_H
#define INVALID_GUNTYPE_EXCEPTION_H

/**
 * @brief Exception for when a given gun doesn't exist
 * 
 */
class Invalid_GunType_Exception : public Invalid_Attribute_Exception {

public:

    /**
     * @brief Construct a new Invalid_GunType_Exception object
     * 
     */
    Invalid_GunType_Exception();

};

#endif