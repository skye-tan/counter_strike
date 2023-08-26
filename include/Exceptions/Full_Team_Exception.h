
#include "Custom_Exception.h"

#ifndef FULL_TEAM_EXCEPTION_H
#define FULL_TEAM_EXCEPTION_H

/**
 * @brief Exception for when a team is full.
 * 
 */
class Full_Team_Exception : public Custom_Exception {

public:

    /**
     * @brief Construct a new Full_Team_Exception object
     * 
     */
    Full_Team_Exception();

};

#endif