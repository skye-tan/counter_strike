
#include <Custom_Exception.h>

Custom_Exception::Custom_Exception(std::string input_msg) : msg(input_msg) {};

const std::string& Custom_Exception::what() const {
    return msg;
}

std::ostream& operator<<(std::ostream &os, const Custom_Exception &exp) {
    os << exp.what();
    return os;
}