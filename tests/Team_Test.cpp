
#include <iostream>
#include "Team.h"
#include "All_Exceptions.h"
#include "gtest/gtest.h"

TEST(Player_Class, Player_Management) {

    std::vector<Pistol> legal_pistols;
    std::vector<Heavy_Gun> legal_heavies;

    Team test_team(legal_pistols, legal_heavies);

    Timer timer_1(1, 0, 0);
    Player player_1("ali", 0, timer_1);

    Timer timer_2(2, 0, 0);
    Player player_2("ali", 0, timer_2);

    Timer timer_3(0, 0, 0);
    Player player_3("ahmad", 0, timer_3);

    test_team.add_player(player_1);

    try {
        test_team.add_player(player_2);
    }
    catch (Duplicate_UserName_Exception e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "you are already in this game");
    }

    EXPECT_EQ(test_team.username_exists("ali"), true);
    EXPECT_EQ(test_team.username_exists("mohammad"), false);
    EXPECT_EQ(test_team.has_alive_member(), false);

    test_team.new_round(true);

    EXPECT_EQ(test_team.has_alive_member(), true);

    try {
        Player recived_player = test_team.get_player("mohammad");
    }
    catch (Invalid_UserName_Exception e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "invalid username");
    }

    Player recived_player = test_team.get_player("ali");
    EXPECT_EQ(recived_player.get_username(), player_1.get_username());

    test_team.add_player(player_3);
    std::cout << test_team.get_ranking().str();
    
}

TEST(Player_Class, Weapon_Management) {

    std::vector<Pistol> legal_pistols;
    legal_pistols.push_back(Pistol("Revolver", 600, 51 ,150));
    legal_pistols.push_back(Pistol("Glock-18", 300, 11 ,200));

    std::vector<Heavy_Gun> legal_heavies;
    legal_heavies.push_back(Heavy_Gun("AK", 2700, 31 ,100));
    legal_heavies.push_back(Heavy_Gun("AWP", 4300, 110 ,50));

    Team test_team(legal_pistols, legal_heavies);

    Pistol pistol = test_team.get_legal_pistol("Revolver");
    Heavy_Gun heavy = test_team.get_legal_heavy("AK");

    EXPECT_EQ(pistol.get_name(), "Revolver");
    EXPECT_EQ(heavy.get_name(), "AK");

}
