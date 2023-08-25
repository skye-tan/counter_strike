
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include "Game_Manager.h"

Game_Manager::Game_Manager() :
    current_round(0), current_time(Timer(0, 0, 0)) {

    std::vector<Pistol> legal_pistols_terrorist;
    legal_pistols_terrorist.push_back(Pistol("Revolver", 600, 51 ,150));
    legal_pistols_terrorist.push_back(Pistol("Glock-18", 300, 11 ,200));

    std::vector<Heavy_Gun> legal_heavies_terrorist;
    legal_heavies_terrorist.push_back(Heavy_Gun("AK", 2700, 31 ,100));
    legal_heavies_terrorist.push_back(Heavy_Gun("AWP", 4300, 110 ,50));

    terrorist = new Team(legal_pistols_terrorist, legal_heavies_terrorist);

    std::vector<Pistol> legal_pistols_counter_terrorist;
    legal_pistols_counter_terrorist.push_back(Pistol("Desert-Eagle", 600, 53 ,175));
    legal_pistols_counter_terrorist.push_back(Pistol("UPS-S", 300, 13 ,225));

    std::vector<Heavy_Gun> legal_heavies_counter_terrorist;
    legal_heavies_counter_terrorist.push_back(Heavy_Gun("M4A1", 2700, 29 ,100));
    legal_heavies_counter_terrorist.push_back(Heavy_Gun("AWP", 4300, 110 ,50));

    counter_terrorist = new Team(legal_pistols_counter_terrorist, legal_heavies_counter_terrorist);
    
}

Game_Manager::~Game_Manager() {
    delete terrorist;
    delete counter_terrorist;
}

void Game_Manager::add_user(const std::string username, const std::string team, const std::string time) {
    update_current_time(time);
    try {

        if (terrorist->username_exists(username) || counter_terrorist->username_exists(username)) {
            throw Duplicate_UserName_Exception();
        }
        Player player(username, current_round, current_time);

        if (team == "Terrorist") {
            terrorist->add_player(player);
        }
        else {
            counter_terrorist->add_player(player);
        }

        std::cout << "this user added to " << team << std::endl;

    }
    catch (Duplicate_UserName_Exception e) {
        std::cout << e << std::endl;
    }
    catch (Full_Team_Exception e) {
        std::cout << e << std::endl;
    }
}

void Game_Manager::get_money(const std::string username, const std::string time) {
    update_current_time(time);
    try {
        Player player = find_player(username);
        std::cout << player.get_statistics().get_money() << std::endl;
    }
    catch (Invalid_UserName_Exception e) {
        std::cout << e << std::endl;
    }
}

void Game_Manager::get_health(const std::string username, const std::string time) {
    update_current_time(time);
    try {
        Player player = find_player(username);
        std::cout << player.get_statistics().get_health() << std::endl;
    }
    catch (Invalid_UserName_Exception e) {
        std::cout << e << std::endl;
    }
}

void Game_Manager::tap(const std::string attacker, const std::string attacked, const std::string weapon_type, const std::string time) {
    update_current_time(time);
    try {

        Player player_attacker = find_player(attacker);
        Player player_attacked = find_player(attacked);

        bool same_team = (terrorist->username_exists(attacker) && terrorist->username_exists(attacked)) ||
        (counter_terrorist->username_exists(attacker) && counter_terrorist->username_exists(attacked));

        player_attacker.attack(player_attacked, weapon_type, same_team);

        std::cout << "nice shot" << std::endl;

    }
    catch (Invalid_UserName_Exception e) {
        std::cout << e << std::endl;
    }
    catch (Dead_Attacker_Exception e) {
        std::cout << e << std::endl;
    }
    catch (Dead_Attacked_Exception e) {
        std::cout << e << std::endl;
    }
    catch (Invalid_GunType_Exception e) {
        std::cout << e << std::endl;
    }
    catch (Friendly_Fire_Exception e) {
        std::cout << e << std::endl;
    }
}

void Game_Manager::buy(const std::string username, const std::string weapon_name, const std::string time) {
    update_current_time(time);
    try {

        Player player = find_player(username);
        player.can_buy(current_time);

        bool is_terrorist = terrorist->username_exists(username);

        Pistol* pistol = NULL;
        Heavy_Gun* heavy = NULL;

        if (is_terrorist) {
            pistol = terrorist->get_legal_pistol(weapon_name);
            heavy = terrorist->get_legal_heavy(weapon_name); 
        }
        else {
            pistol = counter_terrorist->get_legal_pistol(weapon_name);
            heavy = counter_terrorist->get_legal_heavy(weapon_name);
        }

        if (pistol != NULL) {
            player.buy_pistol(*pistol);
        }
        else if (heavy != NULL) {
            player.buy_heavy_gun(*heavy);
        }
        else {
            throw Invalid_GunCategory_Exception();
        }

        std::cout << "I hope you can use it" << std::endl;

    }
    catch (Invalid_UserName_Exception e) {
        std::cout << e << std::endl;
    }
    catch (Dead_Buyer_Exception e) {
        std::cout << e << std::endl;
    }
    catch (Out_Of_Time_Exception e) {
        std::cout << e << std::endl;
    }
    catch (Invalid_GunCategory_Exception e) {
        std::cout << e << std::endl;
    }
    catch (Duplicate_Pistol_Exception e) {
        std::cout << e << std::endl;
    }
    catch (Duplicate_Heavy_Gun_Exception e) {
        std::cout << e << std::endl;
    }
    catch (Insufficient_Money_Exception e) {
        std::cout << e << std::endl;
    }
}

void Game_Manager::score_board(const std::string time) {

    update_current_time(time);

    std::cout << "Counter-Terrorist-Players:" << std::endl;
    std::cout << counter_terrorist->get_ranking().str();

    std::cout << "Terrorist-Players:" << std::endl;
    std::cout << terrorist->get_ranking().str();

}

void Game_Manager::start_new_round() {

    std::string winner = get_winner();
    std::cout << winner  << " won" << std::endl;

    bool terroris_won = winner == "Terrorist" ? true : false;

    terrorist->new_round(terroris_won);
    counter_terrorist->new_round(!terroris_won);

    current_round++;

}

std::string Game_Manager::get_winner() {

    bool terrorist_has_alive = terrorist->has_alive_member();
    bool counter_terrorist_has_alive = terrorist->has_alive_member();

    if (!terrorist_has_alive && !counter_terrorist_has_alive) {
        return "Counter-Terrorist";
    }
    else if (counter_terrorist_has_alive) {
        return "Counter-Terrorist";
    }
    else {
        return "Terrorist";
    }

}

int Game_Manager::get_current_round() {
    return current_round;
}

void Game_Manager::update_current_time(std::string time) {

    std::string minutes, seconds, milliseconds;
    std::stringstream time_stream(time);

    std::getline(time_stream, minutes, ':');
    std::getline(time_stream, seconds, ':');
    std::getline(time_stream, milliseconds, ':');

    current_time = Timer(stoi(minutes), stoi(seconds), stoi(milliseconds));

}

Player& Game_Manager::find_player(const std::string username) {
    if (terrorist->username_exists(username)) {
        return terrorist->get_player(username);
    }
    else if (counter_terrorist->username_exists(username)) {
        return counter_terrorist->get_player(username);
    }
    throw Invalid_UserName_Exception();
}