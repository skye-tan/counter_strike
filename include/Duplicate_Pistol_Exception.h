
#include "Duplicate_WeaponType_Exception.h"

#ifndef DUPLICATE_PISTOL_EXCEPTION_H
#define DUPLICATE_PISTOL_EXCEPTION_H

/**
 * @brief Exception for when a player already has a pistol type weapon
 * 
 */
class Duplicate_Pistol_Exception : public Duplicate_WeaponType_Exception {

public:

    /**
     * @brief Construct a new Duplicate_Pistol_Exception object
     * 
     */
    Duplicate_Pistol_Exception();

};

#endif