
#include "Invalid_Attribute_Exception.h"

#ifndef INVALID_GUNNAME_EXCEPTION_H
#define INVALID_GUNNAME_EXCEPTION_H

/**
 * @brief Exception for when a given gun's name doesn't exist
 * 
 */
class Invalid_GunName_Exception : public Invalid_Attribute_Exception {

public:

    /**
     * @brief Construct a new Invalid_GunName_Exception object
     * 
     */
    Invalid_GunName_Exception();

};

#endif