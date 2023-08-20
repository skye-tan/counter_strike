
#include "Duplicate_Attribute_Exception.h"

#ifndef DUPLICATE_WeaponType_EXCEPTION_H
#define DUPLICATE_WeaponType_EXCEPTION_H

/**
 * @brief Exception for when a player already has a specified type of weapon
 * 
 */
class Duplicate_WeaponType_Exception : public Duplicate_Attribute_Exception {

public:

    /**
     * @brief Construct a new Duplicate_WeaponType_Exception object
     * 
     * @param input_msg the excpetion's message
     */
    Duplicate_WeaponType_Exception(std::string input_msg = "duplicate weapon type");

};

#endif