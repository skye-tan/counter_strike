
#include "Custom_Exception.h"

#ifndef FRIENDLY_FIRE_EXCEPTION_H
#define FRIENDLY_FIRE_EXCEPTION_H

/**
 * @brief Exception for when a friendly player has been attacked.
 * 
 */
class Friendly_Fire_Exception : public Custom_Exception {

public:

    /**
     * @brief Construct a new Friendly_Fire_Exception object
     * 
     */
    Friendly_Fire_Exception();

};

#endif