
#include "Dead_Player_Exception.h"

#ifndef DEAD_ATTACKED_EXCEPTION_H
#define DEAD_ATTACKED_EXCEPTION_H

/**
 * @brief Exception for when a dead player has been attacked
 * 
 */
class Dead_Attacked_Exception : public Dead_Player_Exception {

public:

    /**
     * @brief Construct a new Dead_Attacked_Exception object
     * 
     */
    Dead_Attacked_Exception();

};

#endif