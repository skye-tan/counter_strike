
#include "Weapon.h"

#ifndef PISTOL_H
#define PISTOL_H

/**
 * @brief Store the main attributes of a pistol
 * 
 *   Name, damage and the recived reward which are the common attributes
 * of any kind of pistol are stored here.
 * 
 */
class Pistol : public Weapon {

public:

    /**
     * @brief Construct a new Pistol object
     * 
     * @param input_name Weapon's name
     * @param input_price Money needed to buy this waepon
     * @param input_damage Damage dealt by this weapon
     * @param input_reward Recived reward for killing an enemy with this weapon
     */
    Pistol(const std::string input_name = "", const int input_price = 0, 
            const int input_damage = 0, const int input_reward = 0);

};

#endif