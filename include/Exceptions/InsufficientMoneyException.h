
#include "CustomException.h"

#ifndef ISUFFICIENTMONEYEXCEPTION_H
#define ISUFFICIENTMONEYEXCEPTION_H

/**
 * @brief Store the exceptions for insufficient money.
 * 
 */
class InsufficientMoneyException : public CustomException {

public:

    /**
     * @brief Construct a new InsufficientMoneyException object
     * 
     */
    InsufficientMoneyException();

};

#endif