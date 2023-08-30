
#include "DeadPlayerException.h"

#ifndef DEADATTACKEREXCEPTION_H
#define DEADATTACKEREXCEPTION_H

/**
 * @brief Exception for when a dead player tries to attack another player
 * 
 */
class DeadAttackerException : public DeadPlayerException {

public:

    /**
     * @brief Construct a new DeadAttackerException object
     * 
     */
    DeadAttackerException();

};

#endif