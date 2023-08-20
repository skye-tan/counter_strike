
#include "Custom_Exception.h"

#ifndef DEAD_PLAYER_EXCEPTION_H
#define DEAD_PLAYER_EXCEPTION_H

/**
 * @brief Exception for when a dead player tries to do something.
 * 
 */
class Dead_Player_Exception : public Custom_Exception {

public:

    /**
     * @brief Construct a new Dead_Player_Exception object
     * 
     * @param input_msg the excpetion's message
     */
    Dead_Player_Exception(std::string input_msg);

};

#endif