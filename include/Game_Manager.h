
#include "All_Exceptions.h"
#include "Team.h"
#include "Timer.h"

#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

class Game_Manager {

public:

    Game_Manager();

    void add_user(const std::string username, const std::string team, const std::string time);

    void get_money(const std::string username, const std::string time);

    void get_health(const std::string username, const std::string time);

    void tap(const std::string attacker, const std::string atatcked,
                const std::string weapon_type, const std::string time);

    void buy(const std::string username, const std::string weapon_name, const std::string time);

    void score_board(const std::string time);

    void start_new_round();

    std::string get_winner();

    int get_current_round();

private:

    Team* terrorist;

    Team* counter_terrorist;

    int current_round;

    Timer current_time;

    void update_current_time(std::string time);

    Player& find_player(const std::string username);

};



#endif