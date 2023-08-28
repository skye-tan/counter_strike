
#include "CustomException.h"

#ifndef FRIENDLYFIREEXCEPTION_H
#define FRIENDLYFIREEXCEPTION_H

/**
 * @brief Exception for when a friendly player has been attacked.
 * 
 */
class FriendlyFireException : public CustomException {

public:

    /**
     * @brief Construct a new FriendlyFireException object
     * 
     */
    FriendlyFireException();

};

#endif