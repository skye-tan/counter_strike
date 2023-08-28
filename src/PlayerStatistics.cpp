
#include <PlayerStatistics.h>
#include "AllExceptions.h"

PlayerStatistics::PlayerStatistics() :
    kills(0), deaths(0), health(100), money(1000) {}

void PlayerStatistics::increment_kills() {
    kills++;
}

void PlayerStatistics::increment_deaths() {
    deaths++;
}

void PlayerStatistics::increase_money(const int amount) {
    money += amount;
    money = money > 10000 ? 10000 : money;
}

void PlayerStatistics::decrease_money(const int amount) {
    if (!has_enough_money(amount)) {
        throw InsufficientMoneyException();
    }
    money -= amount;
}

void PlayerStatistics::decrease_health(const int amount) {
    health -= amount;
    health = health < 0 ? 0 : health;
}

void PlayerStatistics::set_health_max() {
    health = 100;
}

void PlayerStatistics::set_health_min() {
    health = 0;
}

bool PlayerStatistics::has_enough_money(const int amount) const {
    return (money >= amount);
}

bool PlayerStatistics::operator == (const PlayerStatistics& second_statistics) {
    return (kills == second_statistics.get_kills() && deaths == second_statistics.get_deaths());
}

bool PlayerStatistics::operator > (const PlayerStatistics& second_statistics) {
    if (kills > second_statistics.get_kills()) {
        return true;
    }
    else if (kills == second_statistics.get_kills() &&
                deaths < second_statistics.get_deaths()) {
        return true;
    }
    return false;
}

int PlayerStatistics::get_kills() const {
    return kills;
}

int PlayerStatistics::get_deaths() const {
    return deaths;
}

int PlayerStatistics::get_health() const {
    return health;
}

int PlayerStatistics::get_money() const {
    return money;
}