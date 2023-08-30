
#include "DeadPlayerException.h"

#ifndef DEADATTACKEDEXCEPTION_H
#define DEADATTACKEDEXCEPTION_H

/**
 * @brief Exception for when a dead player has been attacked
 * 
 */
class DeadAttackedException : public DeadPlayerException {

public:

    /**
     * @brief Construct a new DeadAttackedException object
     * 
     */
    DeadAttackedException();

};

#endif