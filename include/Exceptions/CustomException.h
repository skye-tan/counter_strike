
#include <string>
#include <iostream>

#ifndef CUSTOMEXCEPTION_H
#define CUSTOMEXCEPTION_H

/**
 * @brief Store the exceptions that might occur.
 * 
 *   A class for creating custom exception that might occur
 * through the program.
 * 
 */
class CustomException {

public:

    /**
     * @brief Construct a new Custom_Exception object
     * 
     * @param input_msg the excpetion's message
     */
    CustomException(std::string input_msg = "exception happened");

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
    friend std::ostream& operator<<(std::ostream& os, const CustomException& exp);

private:

    /**
     * @brief Exception's message
     */
    const std::string msg;

};

#endif