
#include "Custom_Exception.h"

#ifndef OUT_OF_TIME_EXCEPTION_H
#define OUT_OF_TIME_EXCEPTION_H

/**
 * @brief Exception for when the time limit for doing an action has passed
 * 
 */
class Out_Of_Time_Exception : public Custom_Exception {

public:

    /**
     * @brief Construct a new Out_Of_Time_Exception object
     * 
     */
    Out_Of_Time_Exception();

};

#endif