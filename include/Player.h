
#include <string>
#include "Player_Statistics.h"
#include "Weapon_Bundle.h"
#include "All_Exceptions.h"
#include "Timer.h"

#ifndef PLAYER_H
#define PLAYER_H

/**
 * @brief Store the information amput the player
 * 
 *   Manages the actions which can be done by a player and like buying weapons,
 * attacking and getting attacked and stores the specifications of statistic information
 * about the player.
 * 
 */
class Player {

public:

    /**
     * @brief Construct a new Player object
     * 
     * @param input_username player's username
     * @param join_time the time when the player has joined the game
     */
    Player(const std::string input_username = "no name", const int input_join_round = 0,
            const Timer& input_join_time = Timer(0, 0, 0));

    /**
     * @brief Buy a new pistol type waepon for the player
     * 
     *   All the problems that might happen are checked and proper
     * exceptions will be thrown should there be any kind of hazard.
     * 
     * @param pistol the pistol object which the player want's to buy
     * @param current_time current time of this round
     * @param invalid_gun determines whether the weapon is legal or not
     */
    void buy_pistol(Pistol& pistol, const Timer& current_time, const bool invalid_gun); 

    /**
     * @brief Buy a new heavy type waepon for the player
     * 
     *   All the problems that might happen are checked and proper
     * exceptions will be thrown should there be any kind of hazard.
     * 
     * @param pistol the heavy object which the player want's to buy
     * @param current_time current time of this round
     * @param invalid_gun determines whether the weapon is legal or not
     */
    void buy_heavy_gun(Heavy_Gun& heavy_gun, const Timer& current_time, const bool invalid_gu); 

    /**
     * @brief Manage the attacking action for this player
     * 
     * @param attacked the player which has been attacked
     * @param weapon_type the type of waepon used by this player
     * @param same_team determines whether the players are in the same team or not
     */
    void attack(Player& attacked, const std::string weapon_type, const bool same_team);

    /**
     * @brief Manage the properties of the player when being attacked
     * 
     *   Apart from mangement of the properties, this method determines whether the player has died
     * after being attacked or not by returning a boolean type variable.
     * 
     * @param weapon the weapon used to attack this player
     * @return true the player is dead
     * @return false the player isn't dead
     */
    bool got_attacked(const Weapon& weapon);

    /**
     * @brief Detemine wheter the player is dead or not
     * 
     * @return true the player is dead
     * @return false the player is alive
     */
    bool is_dead() const;

    /**
     * @brief Resets some variables when a new round has been started
     * 
     *   Proper amount of money will be given to the player based on
     * whether the player has won the previous round or not. Also if
     * the player has lost the last round, all of his weapons apart from
     * the knife will be discarded. 
     * 
     * @param has_won determines whether the player has won the previous round or not
     */
    void new_round(const bool has_won);

    /**
     * @brief Compare two players
     * 
     * @param player the second player
     * @return true this player us superior
     * @return false the second player is superior
     */
    bool operator > (const Player& player);

    /**
     * @brief Get the username of the player
     * 
     * @return std::string the player's username
     */
    std::string get_username() const;

private:

    /**
     * @brief The player's username
     * 
     */
    std::string username;

    /**
     * @brief the round when the player joined the game
     * 
     */
    int join_round;

    /**
     * @brief the time when the player joined the game
     * 
     */
    Timer join_time;

    /**
     * @brief A Weapon_Bundle object containing the player's weapons
     * 
     */
    Weapon_Bundle* weapons;

    /**
     * @brief A Player_Statistics object responsible for mangement
     * of the player's statistic information
     * 
     */
    Player_Statistics* statistics;

    static Timer join_dead_line;
    static Timer shop_dead_line;

};

#endif
