
#include <string>
#include "Weapon.h"

#ifndef KNIFE_H
#define KNIFE_H

/**
 * @brief Store the main attributes of a knife
 * 
 *   Name, damage and the recived reward which are the common attributes
 * of any kind of knife are stored here which will be initialized with constant
 * values in the constructor.
 * 
 */
class Knife : public Weapon {

public:

    /**
     * @brief Construct a new Pistol object
     */
    Knife();
    
};

#endif