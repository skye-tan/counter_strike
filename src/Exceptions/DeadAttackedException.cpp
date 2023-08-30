
#include "DeadAttackedException.h"

DeadAttackedException::DeadAttackedException() :
    DeadPlayerException("attacked is dead") {}