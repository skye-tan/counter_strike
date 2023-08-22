
#include "Player.h"

Player::Player(const std::string input_username, const Timer& input_join_time) :
    username(input_username), join_time(input_join_time) {
        
        if (join_time >= Timer(0, 3, 0)) {
            statistics->set_health_min();
        }
        
    }

void Player::buy_pistol(Pistol& pistol, const bool invalid_gun) {

    if (is_dead()) {
        throw Dead_Buyer_Exception();
    }

    if (join_time >= Timer(0, 45, 0)) {
        throw Out_Of_Time_Exception();
    }

    if (invalid_gun) {
        throw Invalid_GunCategory_Exception();
    }

    weapons->add_pistol(pistol);

    if (!statistics->has_enough_money(pistol.get_price())) {
        weapons->remove_pistol();
        throw Insufficient_Money_Exception();
    }

    statistics->decrease_money(pistol.get_price());

}

void Player::buy_heavy_gun(Heavy_Gun& heavy_gun, const bool invalid_gun) {

    if (is_dead()) {
        throw Dead_Buyer_Exception();
    }

    if (join_time >= Timer(0, 45, 0)) {
        throw Out_Of_Time_Exception();
    }

    if (invalid_gun) {
        throw Invalid_GunCategory_Exception();
    }

    weapons->add_heavy_gun(heavy_gun);

    if (!statistics->has_enough_money(heavy_gun.get_price())) {
        weapons->remove_heavy_gun();
        throw Insufficient_Money_Exception();
    }

    statistics->decrease_money(heavy_gun.get_price());

}

void Player::attack(Player& attacked, const std::string& weapon_type, const bool same_team) {

    if (is_dead()) {
        throw Dead_Attacker_Exception();
    }

    if (attacked.is_dead()) {
        throw Dead_Attacked_Exception();
    }

    Weapon used_weapon = weapons->get_knife();
    if (weapon_type == "pistol") {
        used_weapon = weapons->get_pistol();
    }
    else if (weapon_type == "heavy") {
        used_weapon = weapons->get_heavy_gun();
    }

    if (same_team) {
        throw Friendly_Fire_Exception();
    }

    if (attacked.got_attacked(used_weapon)) {
        statistics->increment_kills();
        statistics->increase_money(used_weapon.get_reward());
    }

}

bool Player::got_attacked(const Weapon& weapon) {

    statistics->decrease_health(weapon.get_damage());

    if (is_dead()) {
        statistics->increment_deaths();
        return true;
    }
    return false;
    
}

bool Player::is_dead() const {
    return (statistics->get_health() == 0);
}

void Player::new_round(const bool has_won) {
    join_time = Timer(0, 0, 0);
    statistics->set_health_max();
    if (has_won) {
        statistics->increase_money(2700);
    }
    else {
        statistics->increase_money(2300);
        weapons->remove_heavy_gun();
        weapons->remove_pistol();
    }
}

bool Player::operator > (const Player& player) {
    //TODO   
    return false;
}

std::string Player::get_username() const {
    return username;
}
