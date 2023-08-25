
#include "All_Exceptions.h"
#include "Team.h"
#include "Timer.h"

#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

/**
 * @brief Manage different commands
 * 
 *   It has access to players and teams for managing them
 * 
 */
class Game_Manager {

public:

    /**
     * @brief Construct a new Game_Manager object
     * 
     */
    Game_Manager();

    /**
     * @brief Destroy the Game_Manager object
     * 
     */
    ~Game_Manager();

    /**
     * @brief Add a new player to the given team
     * 
     * @param username player's username
     * @param team the target team
     * @param time the time when this event takes place
     */
    void add_user(const std::string username, const std::string team, const std::string time);

    /**
     * @brief Get a specified player's money
     * 
     * @param username player's username
     * @param time the time when this event takes place
     */
    void get_money(const std::string username, const std::string time);

    /**
     * @brief Get a specified player's health
     * 
     * @param username player's username
     * @param time the time when this event takes place
     */
    void get_health(const std::string username, const std::string time);

    /**
     * @brief Manage the attacking action of a player to another
     * 
     * @param attacker the player who attacks 
     * @param attacked the player who have been attacked
     * @param weapon_type the weapon's type used by the attacker
     * @param time the time when this event takes place
     */
    void tap(const std::string attacker, const std::string attacked,
                const std::string weapon_type, const std::string time);

    /**
     * @brief Manage the shopping action of a player
     * 
     * @param username the player who wants to shop a weapon
     * @param weapon_name the name of the target weapon
     * @param time the time when this event takes place
     */
    void buy(const std::string username, const std::string weapon_name, const std::string time);

    /**
     * @brief Print the scor board for both teams
     * 
     * @param time the time when this event takes place
     */
    void score_board(const std::string time);

    /**
     * @brief Start a new round for both teams
     * 
     */
    void start_new_round();

    /**
     * @brief Get the winner of the current round
     * 
     * @return std::string the team name of the winner
     */
    std::string get_winner();

    /**
     * @brief Get the current round number
     * 
     * @return int the current round number
     */
    int get_current_round();

private:

    /**
     * @brief A poniter to the terrorist's team
     * 
     */
    Team* terrorist;

    /**
     * @brief A poniter to the counter_terrorist's team
     * 
     */
    Team* counter_terrorist;

    /**
     * @brief The number of current round
     * 
     */
    int current_round;

    /**
     * @brief The time of the current round
     * 
     */
    Timer current_time;

    /**
     * @brief Update the current time of this round by extracting it from the given string
     * 
     * @param time the given string containing the desired time
     */
    void update_current_time(std::string time);

    /**
     * @brief Find a player by username by searching both teams
     * 
     * @param username the player's username
     * @return Player& the player with the given username
     */
    Player& find_player(const std::string username);

};

#endif
