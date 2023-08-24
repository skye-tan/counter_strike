
#include <Player_Statistics.h>

Player_Statistics::Player_Statistics() :
    kills(0), deaths(0), health(100), money(1000) {}

void Player_Statistics::increment_kills() {
    kills++;
}

void Player_Statistics::increment_deaths() {
    deaths++;
}

void Player_Statistics::increase_money(const int amount) {
    money += amount;
    money = money > 10000 ? 10000 : money;
}

void Player_Statistics::decrease_money(const int amount) {
    if (!has_enough_money(amount)) {
        throw Insufficient_Money_Exception();
    }
    money -= amount;
}

void Player_Statistics::decrease_health(const int amount) {
    health -= amount;
    health = health < 0 ? 0 : health;
}

void Player_Statistics::set_health_max() {
    health = 100;
}

void Player_Statistics::set_health_min() {
    health = 0;
}

bool Player_Statistics::has_enough_money(const int amount) const {
    return (money >= amount);
}

bool Player_Statistics::operator == (const Player_Statistics& second_statistics) {
    return (kills == second_statistics.get_kills() && deaths == second_statistics.get_deaths());
}

bool Player_Statistics::operator > (const Player_Statistics& second_statistics) {
    if (kills > second_statistics.get_kills()) {
        return true;
    }
    else if (kills == second_statistics.get_kills() &&
                deaths < second_statistics.get_deaths()) {
        return true;
    }
    return false;
}

int Player_Statistics::get_kills() const {
    return kills;
}

int Player_Statistics::get_deaths() const {

    return deaths;
}

int Player_Statistics::get_health() const {
    return health;
}