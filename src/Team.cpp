
#include "Team.h"

Team::Team(const std::vector<Pistol>& input_legal_pistols, const std::vector<Heavy_Gun>& input_legal_heavies) : 
        legal_pistols(input_legal_pistols), legal_heavies(input_legal_heavies) {}

Player& Team::get_player(const std::string username) {
    for (Player& player : members) {
        if (player.get_username() == username) {
            return player;
        }
    }
    throw Invalid_UserName_Exception();
}

void Team::add_player(const Player& player) {
    if (username_exists(player.get_username())) {
        throw Duplicate_UserName_Exception();
    }
    if (members.size() == 10) {
        throw Full_Team_Exception();
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

Pistol* Team::get_legal_pistol(const std::string weapon_name) {
    for (Pistol& pistol : legal_pistols) {
        if (pistol.get_name() == weapon_name) {
            return &pistol;
        }
    }
    return NULL;
}

Heavy_Gun* Team::get_legal_heavy(const std::string weapon_name) {
    for (Heavy_Gun& heavy : legal_heavies) {
        if (heavy.get_name() == weapon_name) {
            return &heavy;
        }
    }
    return NULL;
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

    for (int i = 0; i < members.size(); i++) {
        ranking << i + 1 << " " << members[i].get_username() << " " <<
                members[i].get_statistics().get_kills() << " " <<
                members[i].get_statistics().get_deaths() << std::endl;
    }

    return ranking;

}
