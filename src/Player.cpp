
#include "Player.h"
#include "AllExceptions.h"

Timer Player::join_dead_line = Timer(0, 3, 0);
Timer Player::shop_dead_line = Timer(0, 45, 0);

Player::Player(const std::string input_username, const int input_join_round, Timer input_join_time) :
    username(input_username), join_round(input_join_round), join_time(input_join_time) {
        if (join_dead_line <= join_time) {
            statistics.set_health_min();
        }
    }

void Player::buy_pistol(Pistol& pistol) {

    weapons.add_pistol(pistol);

    if (!statistics.has_enough_money(pistol.get_price())) {
        weapons.remove_pistol();
        throw InsufficientMoneyException();
    }

    statistics.decrease_money(pistol.get_price());

}

void Player::buy_heavy_gun(HeavyGun& heavy_gun) {

    weapons.add_heavy_gun(heavy_gun);

    if (!statistics.has_enough_money(heavy_gun.get_price())) {
        weapons.remove_heavy_gun();
        throw InsufficientMoneyException();
    }

    statistics.decrease_money(heavy_gun.get_price());

}

void Player::can_buy(const Timer& current_time) {
    if (is_dead()) {
        throw DeadBuyerException();
    }
    if (shop_dead_line <= current_time) {
        throw OutOfTimeException();
    }
}

void Player::attack(Player& attacked, const std::string weapon_type, const bool same_team) {

    if (is_dead()) {
        throw DeadAttackerException();
    }

    if (attacked.is_dead()) {
        throw DeadAttackedException();
    }

    Weapon* used_weapon = weapons.get_knife();
    if (weapon_type == "pistol") {
        used_weapon = weapons.get_pistol();
    }
    else if (weapon_type == "heavy") {
        used_weapon = weapons.get_heavy_gun();
    }

    if (same_team) {
        throw FriendlyFireException();
    }

    if (attacked.got_attacked(used_weapon->get_damage())) {
        statistics.increment_kills();
        statistics.increase_money(used_weapon->get_reward());
    }

}

bool Player::got_attacked(const int damage) {

    statistics.decrease_health(damage);

    if (is_dead()) {
        statistics.increment_deaths();
        return true;
    }
    return false;
    
}

bool Player::is_dead() const {
    return (statistics.get_health() == 0);
}

void Player::new_round(const bool has_won) {
    statistics.set_health_max();
    if (has_won) {
        statistics.increase_money(2700);
    }
    else {
        statistics.increase_money(2400);
        weapons.remove_heavy_gun();
        weapons.remove_pistol();
    }
}

bool Player::operator > (const Player& second_player) {
    if (statistics > second_player.get_statistics()) {
        return true;
    }
    else if (statistics == second_player.get_statistics()) {
        if (join_round < second_player.get_join_round()) {
            return true;
        }
        else if (join_round == second_player.get_join_round() &&
                    join_time <= second_player.get_join_time()) {
            return true;
        }
    }
    return false;
}

std::string Player::get_username() const {
    return username;
}

PlayerStatistics Player::get_statistics() const {
    return statistics;
}

Timer Player::get_join_time() const {
    return join_time;
}

int Player::get_join_round() const {
    return join_round;
}
