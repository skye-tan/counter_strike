
#include "DuplicateWeaponTypeException.h"

#ifndef DUPLICATEHEAVYGUNEXCEPTION_H
#define DUPLICATEHEAVYGUNEXCEPTION_H

/**
 * @brief Exception for when a player already has a heavy type weapon
 * 
 */
class DuplicateHeavyGunException : public DuplicateWeaponTypeException {

public:

    /**
     * @brief Construct a new DuplicateHeavyGunException object
     * 
     */
    DuplicateHeavyGunException();

};

#endif