
#include "DeadPlayerException.h"

DeadPlayerException::DeadPlayerException(std::string input_msg) :
    CustomException(input_msg) {}