
#include "Custom_Exception.h"

#ifndef ISUFFICIENT_MONEY_EXCEPTION_H
#define ISUFFICIENT_MONEY_EXCEPTION_H

/**
 * @brief Store the exceptions for insufficient money.
 * 
 */
class Insufficient_Money_Exception : public Custom_Exception {

public:

    /**
     * @brief Construct a new Insufficient_Money_Exception object
     * 
     */
    Insufficient_Money_Exception();

};

#endif