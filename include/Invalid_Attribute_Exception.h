
#include "Custom_Exception.h"

#ifndef INVALID_ATTRIBUTE_EXCEPTION_H
#define INVALID_ATTRIBUTE_EXCEPTION_H

/**
 * @brief Exception for when a given attribute is invalid
 * 
 */
class Invalid_Attribute_Exception : public Custom_Exception {

public:

    /**
     * @brief Construct a new Invalid_Attribute_Exception object
     * 
     * @param input_msg the excpetion's message
     */
    Invalid_Attribute_Exception(std::string input_msg = "invalid attribute");

};

#endif