
#include "Custom_Exception.h"

#ifndef DUPLICATE_ATTRIBUTE_EXCEPTION_H
#define DUPLICATE_ATTRIBUTE_EXCEPTION_H

/**
 * @brief Exception for when a duplicate attribute has been given
 * 
 */
class Duplicate_Attribute_Exception : public Custom_Exception {

public:

    /**
     * @brief Construct a new Duplicate_Attribute_Exception object
     * 
     * @param input_msg the excpetion's message
     */
    Duplicate_Attribute_Exception(std::string input_msg = "duplicate attribute");

};

#endif