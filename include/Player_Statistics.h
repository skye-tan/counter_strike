
#include "All_Exceptions.h"

#ifndef PLAYER_STATISTICS_H
#define PLAYER_STATISTICS_H

/**
 * @brief Store the statistics related to a specified player
 * 
 *   Stores and manages the number of kills and deaths and the amount of
 * money and health related to a specified player.
 * 
 */
class Player_Statistics {

public:

    /**
     * @brief Construct a new Player_Statistics object
     * 
     */
    Player_Statistics();

    /**
     * @brief Increase the number of kills by one
     * 
     */
    void increment_kills();

    /**
     * @brief Increase the number of deaths by one
     * 
     */
    void increment_deaths();

    /**
     * @brief Increase the amount of money by the given amount
     * 
     *   If the money is beyond 10000 then it will be reseted to 10000.
     * 
     * @param amount the amount which is going to be added to the money
     */
    void increase_money(const int amount);

    
    /**
     * @brief Decrease the amount of money by the given amount
     * 
     * @param amount the amount which is going to be taken from the money
     */
    void decrease_money(const int amount);

    /**
     * @brief Decrease the amount of health by the given amount
     * 
     *   If the health is below 0 then it will be reseted to 0.
     * 
     * @param amount the amount which is going to be taken from the health
     */
    void decrease_health(const int amount);

    /**
     * @brief Reset the amount of health to 100
     * 
     */
    void set_health_max();

    /**
     * @brief Reset the amount of health to 0
     * 
     */
    void set_health_min();

    /**
     * @brief Determines whether the player has enough money for the given amount or not
     * 
     * @param amount 
     * @return true player has enough money
     * @return false player doesn't have enough money
     */
    bool has_enough_money(const int amount) const;

    /**
     * @brief Get the kills
     * 
     * @return int number of kills
     */
    int get_kills() const;

    /**
     * @brief Get the deaths
     * 
     * @return int number of deaths
     */
    int get_deaths() const;

    /**
     * @brief Get the health 
     * 
     * @return int amount of health
     */
    int get_health() const;

    /**
     * @brief Get the money 
     * 
     * @return int amount of money
     */
    int get_money() const;

    /**
     * @brief Compare two statistics
     * 
     * @param second_statistics the second player
     * @return true both are equal
     * @return false they aren't equal
     */
    bool operator == (const Player_Statistics& second_statistics);

    /**
     * @brief Compare two statistics
     * 
     * @param second_statistics the second player
     * @return true this statistics is superior
     * @return false the second statistics is superior
     */
    bool operator > (const Player_Statistics& second_statistics);

private:

    /**
     * @brief The number players who have been killed by this player
     * 
     */
    int kills;

    /**
     * @brief The number times the player has died
     * 
     */
    int deaths;

    /**
     * @brief The amount of health that the player currently possesses
     * 
     */
    int health;

    /**
     * @brief The amount of money that the player currently possesses
     * 
     */
    int money;

};

#endif