
#include "Weapon.h"

#ifndef KNIFE_H
#define KNIFE_H

/**
 * @brief Store the main attributes of a knife int a singleton class
 * 
 *   Name, damage and the recived reward which are the common attributes
 * of any kind of knife are stored here which will be initialized with constant
 * values in the constructor.
 * 
 */
class Knife : public Weapon {

public:

    /**
     * @brief Get the instance object
     * 
     * @return Knife* 
     */
    static Knife* get_instance();

    /**
     * @brief Delete the instance object
     * 
     */
    static void delete_instance();

    /**
     * @brief  Delete copy constructor
     * 
     * @param obj 
     */
    Knife(const Knife& obj) = delete;

    /**
     * @brief Delete assignment operator
     * 
     * @param obj 
     * @return Knife& 
     */
    Knife& operator = (const Knife& obj) = delete;

private:

    /**
     * @brief Construct a new Pistol object
     */
    Knife();

    /**
     * @brief The single unique Knife insatnce
     * 
     */
    static Knife* singleton_knife;
    
};

#endif