
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include "GameManager.h"
#include "AllExceptions.h"

GameManager::GameManager() :
    current_round(0), current_time(Timer(0, 0, 0)) {

    std::vector<Pistol> legal_pistols_terrorist;
    legal_pistols_terrorist.push_back(Pistol("Revolver", 600, 51 ,150));
    legal_pistols_terrorist.push_back(Pistol("Glock-18", 300, 11 ,200));

    std::vector<HeavyGun> legal_heavies_terrorist;
    legal_heavies_terrorist.push_back(HeavyGun("AK", 2700, 31 ,100));
    legal_heavies_terrorist.push_back(HeavyGun("AWP", 4300, 110 ,50));

    terrorist = new Team(legal_pistols_terrorist, legal_heavies_terrorist);

    std::vector<Pistol> legal_pistols_counter_terrorist;
    legal_pistols_counter_terrorist.push_back(Pistol("Desert-Eagle", 600, 53 ,175));
    legal_pistols_counter_terrorist.push_back(Pistol("UPS-S", 300, 13 ,225));

    std::vector<HeavyGun> legal_heavies_counter_terrorist;
    legal_heavies_counter_terrorist.push_back(HeavyGun("M4A1", 2700, 29 ,100));
    legal_heavies_counter_terrorist.push_back(HeavyGun("AWP", 4300, 110 ,50));

    counter_terrorist = new Team(legal_pistols_counter_terrorist, legal_heavies_counter_terrorist);
    
}

GameManager::~GameManager() {
    delete terrorist;
    delete counter_terrorist;
}

void GameManager::add_user(const std::string username, const std::string team, const std::string time) {
    update_current_time(time);
    try {

        if (terrorist->username_exists(username) || counter_terrorist->username_exists(username)) {
            throw DuplicateUserNameException();
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
    catch (DuplicateUserNameException e) {
        std::cout << e << std::endl;
    }
    catch (FullTeamException e) {
        std::cout << e << std::endl;
    }
}

void GameManager::get_money(const std::string username, const std::string time) {
    update_current_time(time);
    try {
        Player& player = find_player(username);
        std::cout << player.get_statistics().get_money() << std::endl;
    }
    catch (InvalidUserNameException e) {
        std::cout << e << std::endl;
    }
}

void GameManager::get_health(const std::string username, const std::string time) {
    update_current_time(time);
    try {
        Player& player = find_player(username);
        std::cout << player.get_statistics().get_health() << std::endl;
    }
    catch (InvalidUserNameException e) {
        std::cout << e << std::endl;
    }
}

void GameManager::tap(const std::string attacker, const std::string attacked, const std::string weapon_type, const std::string time) {
    update_current_time(time);
    try {

        Player& player_attacker = find_player(attacker);
        Player& player_attacked = find_player(attacked);

        bool same_team = (terrorist->username_exists(attacker) && terrorist->username_exists(attacked)) ||
        (counter_terrorist->username_exists(attacker) && counter_terrorist->username_exists(attacked));

        player_attacker.attack(player_attacked, weapon_type, same_team);

        std::cout << "nice shot" << std::endl;

    }
    catch (InvalidUserNameException e) {
        std::cout << e << std::endl;
    }
    catch (DeadAttackerException e) {
        std::cout << e << std::endl;
    }
    catch (DeadAttackedException e) {
        std::cout << e << std::endl;
    }
    catch (InvalidGunTypeException e) {
        std::cout << e << std::endl;
    }
    catch (FriendlyFireException e) {
        std::cout << e << std::endl;
    }
}

void GameManager::buy(const std::string username, const std::string weapon_name, const std::string time) {
    update_current_time(time);
    try {

        Player& player = find_player(username);
        player.can_buy(current_time);

        bool is_terrorist = terrorist->username_exists(username);

        if (is_terrorist) {
            std::string weapon_type = terrorist->get_weapon_type(weapon_name);
            if (weapon_type == "pistol") {
                player.buy_pistol(terrorist->get_legal_pistol(weapon_name));
            }
            else {
                player.buy_heavy_gun(terrorist->get_legal_heavy(weapon_name));
            }
        }
        else {
            std::string weapon_type = counter_terrorist->get_weapon_type(weapon_name);
            if (weapon_type == "pistol") {
                player.buy_pistol(counter_terrorist->get_legal_pistol(weapon_name));
            }
            else {
                player.buy_heavy_gun(counter_terrorist->get_legal_heavy(weapon_name));
            }
        }

        std::cout << "I hope you can use it" << std::endl;

    }
    catch (InvalidUserNameException e) {
        std::cout << e << std::endl;
    }
    catch (DeadBuyerException e) {
        std::cout << e << std::endl;
    }
    catch (OutOfTimeException e) {
        std::cout << e << std::endl;
    }
    catch (InvalidGunCategoryException e) {
        std::cout << e << std::endl;
    }
    catch (DuplicatePistolException e) {
        std::cout << e << std::endl;
    }
    catch (DuplicateHeavyGunException e) {
        std::cout << e << std::endl;
    }
    catch (InsufficientMoneyException e) {
        std::cout << e << std::endl;
    }
}

void GameManager::score_board(const std::string time) {

    update_current_time(time);

    std::cout << "Counter-Terrorist-Players:" << std::endl;
    std::cout << counter_terrorist->get_ranking().str();

    std::cout << "Terrorist-Players:" << std::endl;
    std::cout << terrorist->get_ranking().str();

}

void GameManager::start_new_round() {

    std::string winner = get_winner();
    std::cout << winner  << " won" << std::endl;

    bool terroris_won = winner == "Terrorist" ? true : false;

    terrorist->new_round(terroris_won);
    counter_terrorist->new_round(!terroris_won);

    current_time = Timer(0, 0, 0);
    current_round++;

}

std::string GameManager::get_winner() {

    bool terrorist_has_alive = terrorist->has_alive_member();
    bool counter_terrorist_has_alive = counter_terrorist->has_alive_member();

    if (terrorist_has_alive && !counter_terrorist_has_alive) {
        return "Terrorist";
    }
    else {
        return "Counter-Terrorist";
    }

}

int GameManager::get_current_round() {
    return current_round;
}

void GameManager::update_current_time(std::string time) {

    std::string minutes, seconds, milliseconds;
    std::stringstream time_stream(time);

    std::getline(time_stream, minutes, ':');
    std::getline(time_stream, seconds, ':');
    std::getline(time_stream, milliseconds);

    current_time = Timer(stoi(minutes), stoi(seconds), stoi(milliseconds));

}

Player& GameManager::find_player(const std::string username) {
    if (terrorist->username_exists(username)) {
        return terrorist->get_player(username);
    }
    else if (counter_terrorist->username_exists(username)) {
        return counter_terrorist->get_player(username);
    }
    throw InvalidUserNameException();
}