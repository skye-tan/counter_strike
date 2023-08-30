
#include "CustomException.h"

#ifndef DEADPLAYEREXCEPTION_H
#define DEADPLAYEREXCEPTION_H

/**
 * @brief Exception for when a dead player tries to do something.
 * 
 */
class DeadPlayerException : public CustomException {

public:

    /**
     * @brief Construct a new DeadPlayerException object
     * 
     * @param inputmsg the excpetion's message
     */
    DeadPlayerException(std::string inputmsg = "player is dead");

};

#endif