
#include "Duplicate_WeaponType_Exception.h"

#ifndef DUPLICATE_HEAVY_GUN_EXCEPTION_H
#define DUPLICATE_HEAVY_GUN_EXCEPTION_H

/**
 * @brief Exception for when a player already has a heavy type weapon
 * 
 */
class Duplicate_Heavy_Gun_Exception : public Duplicate_WeaponType_Exception {

public:

    /**
     * @brief Construct a new Duplicate_Heavy_Gun_Exception object
     * 
     */
    Duplicate_Heavy_Gun_Exception();

};

#endif