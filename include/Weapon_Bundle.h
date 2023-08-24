
#include "Pistol.h"
#include "Heavy_Gun.h"
#include "Knife.h"

#ifndef WEAPOM_BUNDLE_H
#define WEAPOM_BUNDLE_H

/**
 * @brief Store the three kinds of weapon a player possesses.
 *  
 *   A bundle which contains a pistol, a heavy_gun and a knife
 * which a player possesses and manages those weapons.
 * 
 */
class Weapon_Bundle {

public:

    /**
     * @brief Construct a new Weapon_Bundle object.
     * 
     */
    Weapon_Bundle();

    /**
     * @brief Add a new pistol
     * 
     * @param pistol the new pistol which is going to be placed in the bundle
     */
    void add_pistol(Pistol& pistol);

    /**
     * @brief Add a new heavy gun
     * 
     * @param heavy_gun the new heavy gun which is going to be placed in the bundle
     */
    void add_heavy_gun(Heavy_Gun& heavy_gun);

    /**
     * @brief Remove the current pistol
     * 
     */
    void remove_pistol();

    /**
     * @brief Remove the current heavy gun
     * 
     */
    void remove_heavy_gun();

    /**
     * @brief Get the pistol.
     * 
     * @return Pistol
     */
    Pistol get_pistol() const;

    /**
     * @brief Get the heavy gun.
     * 
     * @return Heavy_Gun
     */
    Heavy_Gun get_heavy_gun() const;

    /**
     * @brief Get the knife.
     * 
     * @return Knife
     */
    Knife get_knife() const;
    

private:

    /**
     * @brief Player's pistol.
     * 
     *   A pointer to a Pistol object which acts as the player's pistol type weapon.
     * 
     */
    Pistol* pistol;

    /**
     * @brief  Player's heavy gun.
     *
     *   A pointer to a Heavy_Gun object which acts as the player's heavy type weapon.
     * 
     */
    Heavy_Gun* heavy_gun;

    /**
     * @brief Player's knife.
     *
     *   A pointer to a Knife object which acts as the player's knife.
     * 
     */
    Knife* knife;

};

#endif