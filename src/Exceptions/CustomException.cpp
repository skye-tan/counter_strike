
#include <CustomException.h>

CustomException::CustomException(std::string input_msg) : msg(input_msg) {};

const std::string& CustomException::what() const {
    return msg;
}

std::ostream& operator<<(std::ostream &os, const CustomException &exp) {
    os << exp.what();
    return os;
}