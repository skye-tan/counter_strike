
#include "CustomException.h"

#ifndef DUPLICATEATTRIBUTEEXCEPTION_H
#define DUPLICATEATTRIBUTEEXCEPTION_H

/**
 * @brief Exception for when a duplicate attribute has been given
 * 
 */
class DuplicateAttributeException : public CustomException {

public:

    /**
     * @brief Construct a new DuplicateAttributeException object
     * 
     * @param inputmsg the excpetion's message
     */
    DuplicateAttributeException(std::string inputmsg = "duplicate attribute");

};

#endif