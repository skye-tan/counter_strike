
#include <string>

#ifndef WEAPON_H
#define WEAPON_H

/**
 * @brief Store the main attributes of a weapon
 * 
 *   Name, damage and the recived reward which are the common attributes
 * of any kind of weapon are stored here and other classes related to the
 * specified weapons will inherite from this class
 * 
 */
class Weapon {

public:

    /**
     * @brief Construct a new Weapon object
     * 
     * @param input_name Weapon's name
     * @param input_damage Damage dealt by this weapon
     * @param input_reward Recived reward for killing an enemy with this weapon
     */
    Weapon(const std::string input_name = "", const int input_damage = 0, const int input_reward = 0);

    /**
     * @brief Get weapon's name
     * 
     * @return std::string 
     */
    std::string get_name() const;

    /**
     * @brief Get the damage dealt by this weapon
     * 
     * @return int 
     */
    int get_damage() const;

    /**
     * @brief Get the recived reward for killing an enemy with this weapon
     * 
     * @return int 
     */
    int get_reward() const;

private:

    /**
     * @brief Name of this weapon
     * 
     *   A unique name for this weapon
     * 
     */
    std::string name;

    /**
     * @brief Damage dealt by this weapon
     * 
     *   The amount of damage which is dealt when an enemy has been
     * attacked by this weapon
     * 
     */
    int damage;

    /**
     * @brief Reward recived after killing an enemy by this weapon
     *  
     *   The amount of money recived after killing an enemy player
     * using this weapon
     * 
     */
    int reward;

};

#endif