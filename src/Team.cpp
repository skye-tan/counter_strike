
#include "Team.h"
#include "AllExceptions.h"

Team::Team(const std::vector<Pistol>& input_legal_pistols, const std::vector<HeavyGun>& input_legal_heavies) : 
        legal_pistols(input_legal_pistols), legal_heavies(input_legal_heavies) {}

Player& Team::get_player(const std::string username) {
    for (Player& player : members) {
        if (player.get_username() == username) {
            return player;
        }
    }
    throw InvalidUserNameException();
}

void Team::add_player(const Player& player) {
    if (username_exists(player.get_username())) {
        throw DuplicateUserNameException();
    }
    if (members.size() == 10) {
        throw FullTeamException();
    }
    members.push_back(player);
}

bool Team::username_exists(const std::string username) {
    for (Player& player : members) {
        if (player.get_username() == username) {
            return true;
        }
    }
    return false;
}

Pistol& Team::get_legal_pistol(const std::string weapon_name) {
    for (Pistol& pistol : legal_pistols) {
        if (pistol.get_name() == weapon_name) {
            return pistol;
        }
    }
    throw InvalidGunCategoryException();
}

HeavyGun& Team::get_legal_heavy(const std::string weapon_name) {
    for (HeavyGun& heavy : legal_heavies) {
        if (heavy.get_name() == weapon_name) {
            return heavy;
        }
    }
    throw InvalidGunCategoryException();
}

std::string Team::get_weapon_type(const std::string weapon_name) {
    for (HeavyGun& heavy : legal_heavies) {
        if (heavy.get_name() == weapon_name) {
            return "heavy";
        }
    }
    for (Pistol& pistol : legal_pistols) {
        if (pistol.get_name() == weapon_name) {
           return "pistol";
        }
    }
    throw InvalidGunCategoryException();
}

bool Team::has_alive_member() {
    for (Player& player : members) {
        if (!player.is_dead()) {
            return true;
        }
    }
    return false;
}

void Team::new_round(const bool is_winner) {
    for (Player& player : members) {
        player.new_round(is_winner);
    }
}

std::stringstream Team::get_ranking() {

    sort(members.begin(), members.end(), [](Player &first, Player &second) { 
        return first > second; 
    });

    std::stringstream ranking;

    int counter = 1;
    for (Player& player : members) {
        ranking << counter << " " << player.get_username() << " " <<
                player.get_statistics().get_kills() << " " <<
                player.get_statistics().get_deaths() << std::endl;
        counter++;
    }

    return ranking;

}
