
#include "DuplicateWeaponTypeException.h"

#ifndef DUPLICATEPISTOLEXCEPTION_H
#define DUPLICATEPISTOLEXCEPTION_H

/**
 * @brief Exception for when a player already has a pistol type weapon
 * 
 */
class DuplicatePistolException : public DuplicateWeaponTypeException {

public:

    /**
     * @brief Construct a new DuplicatePistolException object
     * 
     */
    DuplicatePistolException();

};

#endif