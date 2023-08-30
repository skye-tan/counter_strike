
#include "DuplicateAttributeException.h"

#ifndef DUPLICATEWeaponTypeEXCEPTION_H
#define DUPLICATEWeaponTypeEXCEPTION_H

/**
 * @brief Exception for when a player already has a specified type of weapon
 * 
 */
class DuplicateWeaponTypeException : public DuplicateAttributeException {

public:

    /**
     * @brief Construct a new DuplicateWeaponTypeException object
     * 
     * @param inputmsg the excpetion's message
     */
    DuplicateWeaponTypeException(std::string inputmsg = "duplicate weapon type");

};

#endif