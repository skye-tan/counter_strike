
#include "CustomException.h"

#ifndef INVALIDATTRIBUTEEXCEPTION_H
#define INVALIDATTRIBUTEEXCEPTION_H

/**
 * @brief Exception for when a given attribute is invalid
 * 
 */
class InvalidAttributeException : public CustomException {

public:

    /**
     * @brief Construct a new InvalidAttributeException object
     * 
     * @param inputmsg the excpetion's message
     */
    InvalidAttributeException(std::string inputmsg = "invalid attribute");

};

#endif