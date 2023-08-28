
#include "CustomException.h"

#ifndef OUTOFTIMEEXCEPTION_H
#define OUTOFTIMEEXCEPTION_H

/**
 * @brief Exception for when the time limit for doing an action has passed
 * 
 */
class OutOfTimeException : public CustomException {

public:

    /**
     * @brief Construct a new OutOfTimeException object
     * 
     */
    OutOfTimeException();

};

#endif