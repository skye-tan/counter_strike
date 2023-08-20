
#include "Dead_Player_Exception.h"

#ifndef DEAD_ATTACKER_EXCEPTION_H
#define DEAD_ATTACKER_EXCEPTION_H

/**
 * @brief Exception for when a dead player tries to attack another player
 * 
 */
class Dead_Attacker_Exception : public Dead_Player_Exception {

public:

    /**
     * @brief Construct a new Dead_Attacker_Exception object
     * 
     */
    Dead_Attacker_Exception();

};

#endif