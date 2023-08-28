
#include "DeadPlayerException.h"

#ifndef DEADBUYEREXCEPTION_H
#define DEADBUYEREXCEPTION_H

/**
 * @brief Exception for when a dead player tries to buy something
 * 
 */
class DeadBuyerException : public DeadPlayerException {

public:

    /**
     * @brief Construct a new DeadBuyerException object
     * 
     */
    DeadBuyerException();

};

#endif