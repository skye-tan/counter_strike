
#include <string>
#include "Weapon.h"

#ifndef HEAVY_GUN_H
#define HEAVY_GUN_H

/**
 * @brief Store the main attributes of a heavy gun
 * 
 *   Name, damage and the recived reward which are the common attributes
 * of any kind of heavy gun are stored here.
 * 
 */
class Heavy_Gun : public Weapon {
    
    /**
     * @brief Construct a new Pistol object
     * 
     * @param input_name Weapon's name
     * @param input_damage Damage dealt by this weapon
     * @param input_reward Recived reward for killing an enemy with this weapon
     */
    Heavy_Gun(const std::string input_name = "", const int input_damage = 0, const int input_reward = 0);

};

#endif