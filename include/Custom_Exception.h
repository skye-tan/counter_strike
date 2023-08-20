
#include <string>
#include <iostream>

#ifndef CUSTOM_EXCEPTION_H
#define CUSTOM_EXCEPTION_H

class Custom_Exception {

public:

    Custom_Exception(std::string input_msg);

    const std::string& what() const;

    friend std::ostream& operator<<(std::ostream& os, const Custom_Exception& exp);

private:

    const std::string msg;

};

#endif