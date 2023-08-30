
#include "DuplicateUserNameException.h"

DuplicateUserNameException::DuplicateUserNameException() :
    DuplicateAttributeException("you are already in this game") {}
