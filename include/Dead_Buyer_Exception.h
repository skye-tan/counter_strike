
#include "Dead_Player_Exception.h"

#ifndef DEAD_BUYER_EXCEPTION_H
#define DEAD_BUYER_EXCEPTION_H

/**
 * @brief Exception for when a dead player tries to buy something
 * 
 */
class Dead_Buyer_Exception : public Dead_Player_Exception {

public:

    /**
     * @brief Construct a new Dead_Buyer_Exception object
     * 
     */
    Dead_Buyer_Exception();

};

#endif