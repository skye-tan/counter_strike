
#include "CustomException.h"

#ifndef FULLTEAMEXCEPTION_H
#define FULLTEAMEXCEPTION_H

/**
 * @brief Exception for when a team is full.
 * 
 */
class FullTeamException : public CustomException {

public:

    /**
     * @brief Construct a new FullTeamException object
     * 
     */
    FullTeamException();

};

#endif