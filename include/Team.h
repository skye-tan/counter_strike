
#include "Player.h"
#include <vector>
#include <algorithm>
#include <sstream>

#ifndef TEAM_H
#define TEAM_H

/**
 * @brief Store and manage the members and legal weapons of a team
 * 
 *   Stores both the players and legal weapons of a team in a vector object
 * for better management of the game.
 * 
 */
class Team {

public:

    /**
     * @brief Construct a new Team object
     * 
     * @param input_legal_pistols vector containing the legal pistol guns of the team
     * @param input_legal_heavies vector containing the legal heavy guns of the team
     */
    Team(const std::vector<Pistol>& input_legal_pistols, const std::vector<HeavyGun>& input_legal_heavies);

    /**
     * @brief Destroy the Team object
     * 
     */
    ~Team();

    /**
     * @brief Get a specified player by username
     * 
     *   If the player does not exist in the team, an exception will be thrown.
     * 
     * @param username player's username
     * @return Player& the Player pbject
     */
    Player& get_player(const std::string username);

    /**
     * @brief Add a new player to the team
     * 
     *   The player will be added to the team after consideration of the
     * number of players present in the team and the duplication of the username.
     * 
     * @param username the new player's usesrname
     */
    void add_player(const Player& player);

    /**
     * @brief Check whether a player by the given username exists in this team or not
     * 
     * @param username the player's username
     * @return true the player exists in this team
     * @return false the player doesn't exist in this team
     */
    bool username_exists(const std::string username);

    /**
     * @brief Check whether a given weapon is legal pistol for this team or not and returns the
     * Pistol object.
     * 
     * @param weapon_name the weapon's name
     * @return Pistol& the Pistol object
     */
    Pistol& get_legal_pistol(const std::string weapon_name);

    /**
     * @brief Check whether a given weapon is legal pistol for this team or not and returns the
     * Heavy_Gun object.
     * 
     * @param weapon_name the weapon's name
     * @return HeavyGun& the Heavy_Gun object
     */
    HeavyGun& get_legal_heavy(const std::string weapon_name);

    /**
     * @brief Get the weapon type of a given weapon by name
     * 
     * @param weapon_name the weapon's name
     * @return std::string the type of the weapon
     */
    std::string get_weapon_type(const std::string weapon_name);

    /**
     * @brief Determine whether the team has alive member or not
     * 
     *   Return false if there isn't any members present.
     * 
     * @return true has alive member
     * @return false doesn't have alive member
     */
    bool has_alive_member();

    /**
     * @brief Start a new round for the memebrs of this team
     * 
     * @param is_winner determines whether this team is the winner of this round or not
     */
    void new_round(const bool is_winner);

    /**
     * @brief Get the ranking of the members
     * 
     * @return std::stringstream a stringstream contaning the ranking
     */
    std::stringstream get_ranking();

private:

    /**
     * @brief A vector contaning the members of the team
     * 
     */
    std::vector<Player> members;

    /**
     * @brief  A vector contaning the legal pistol guns for the team
     * 
     */
    std::vector<Pistol> legal_pistols;

    
    /**
     * @brief  A vector contaning the legal heavy guns for the team
     * 
     */
    std::vector<HeavyGun> legal_heavies;

};

#endif
