
#include <string>
#include <iostream>

#ifndef CUSTOM_EXCEPTION_H
#define CUSTOM_EXCEPTION_H

/**
 * @brief Store the exceptions that might occur.
 * 
 *   A class for creating custom exception that might occur
 * through the program.
 * 
 */
class Custom_Exception {

public:

    /**
     * @brief Construct a new Custom_Exception object
     * 
     * @param input_msg the excpetion's message
     */
    Custom_Exception(std::string input_msg);

    /**
     * @brief Return the exception's message
     * 
     * @return const std::string& 
     */
    const std::string& what() const;

    /**
     * @brief Overload << operator for this class
     * 
     * @param os 
     * @param exp 
     * @return std::ostream& 
     */
    friend std::ostream& operator<<(std::ostream& os, const Custom_Exception& exp);

private:

    /**
     * @brief Exception's message
     */
    const std::string msg;

};

#endif