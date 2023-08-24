
#include <iostream>
#include "Player.h"
#include "All_Exceptions.h"
#include "gtest/gtest.h"

TEST(Player_Class, Basics) {

    Timer timer(1, 42, 123);
    Player test_player("player", 0, timer);

    EXPECT_EQ(test_player.get_username(), "player");
    EXPECT_EQ(test_player.get_join_round(), 0);
    EXPECT_EQ(test_player.get_join_time().get_minutes(), 1);
    EXPECT_EQ(test_player.get_join_time().get_seconds(), 42);
    EXPECT_EQ(test_player.get_join_time().get_milliseconds(), 123);
    EXPECT_EQ(test_player.is_dead(), true);

    test_player.new_round(true);

    EXPECT_EQ(test_player.is_dead(), false);

}

TEST(Player_Class, Buy_Pistol) {

    Timer timer_1(1, 42, 123);
    Timer timer_2(0, 2, 100);

    Player test_player("player", 0, timer_1);
    Pistol pistol_1("pistol", 1000);
    Pistol pistol_2("pistol", 10000);

    try {
        test_player.buy_pistol(pistol_1, timer_1, true);
    }
    catch (Dead_Buyer_Exception e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "deads can not buy");
    }

    test_player.new_round(true);

    try {
        test_player.buy_pistol(pistol_1, timer_1, true);
    }
    catch (Out_Of_Time_Exception e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "you are out of time");
    }

    try {
        test_player.buy_pistol(pistol_1, timer_2, true);
    }
    catch (Invalid_GunCategory_Exception e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "invalid category gun");
    }

    test_player.buy_pistol(pistol_1, timer_2, false);

    try {
        test_player.buy_pistol(pistol_1, timer_2, false);
    }
    catch (Duplicate_Pistol_Exception e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "you have a pistol");
    }

    test_player.new_round(false);

    try {
        test_player.buy_pistol(pistol_2, timer_2, false);
    }
    catch (Insufficient_Money_Exception e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "no enough money");
    }

    test_player.buy_pistol(pistol_1, timer_2, false);

}

TEST(Player_Class, Buy_Heavy) {

    Timer timer_1(1, 42, 123);
    Timer timer_2(0, 2, 100);

    Player test_player("player", 0, timer_1);
    Heavy_Gun heavy_1("heavy", 1000);
    Heavy_Gun heavy_2("heavy", 10000);


    try {
        test_player.buy_heavy_gun(heavy_1, timer_1, true);
    }
    catch (Dead_Buyer_Exception e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "deads can not buy");
    }

    test_player.new_round(true);

    try {
        test_player.buy_heavy_gun(heavy_1, timer_1, true);
    }
    catch (Out_Of_Time_Exception e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "you are out of time");
    }

    try {
        test_player.buy_heavy_gun(heavy_1, timer_2, true);
    }
    catch (Invalid_GunCategory_Exception e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "invalid category gun");
    }

    test_player.buy_heavy_gun(heavy_1, timer_2, false);

    try {
        test_player.buy_heavy_gun(heavy_1, timer_2, false);
    }
    catch (Duplicate_Heavy_Gun_Exception e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "you have a heavy");
    }

    test_player.new_round(false);

    try {
        test_player.buy_heavy_gun(heavy_2, timer_2, false);
    }
    catch (Insufficient_Money_Exception e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "no enough money");
    }

    test_player.buy_heavy_gun(heavy_1, timer_2, false);

}

TEST(Player_Class, Attack_Action) {

    Timer timer(1, 42, 123);
    Player test_attacker("player", 0, timer);
    Player test_attacked("player", 0, timer);
    Heavy_Gun heavy("heavy", 1000);

    try {
        test_attacker.attack(test_attacked, "heavy", true);
    }
    catch (Dead_Attacker_Exception e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "attacker is dead");
    }

    test_attacker.new_round(false);

    try {
        test_attacker.attack(test_attacked, "heavy", true);
    }
    catch (Dead_Attacked_Exception e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "attacked is dead");
    }

    test_attacked.new_round(false);

    try {
        test_attacker.attack(test_attacked, "heavy", true);
    }
    catch (Invalid_GunType_Exception e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "no such gun");
    }


    test_attacker.buy_heavy_gun(heavy, Timer(0, 0, 0), false);

    try {
        test_attacker.attack(test_attacked, "heavy", true);
    }
    catch (Friendly_Fire_Exception e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "friendly fire");
    }

    test_attacker.attack(test_attacked, "heavy", false);

}

TEST(Player_Class, Operators) {
    
    Timer timer_1(0, 2, 100);
    Timer timer_2(1, 42, 123);

    Player test_player_1("player", 0, timer_1);
    Player test_player_2("player", 1, timer_1);
    Player test_player_3("player", 1, timer_2);

    EXPECT_EQ(test_player_1 > test_player_2, true);
    EXPECT_EQ(test_player_1 > test_player_3, true);
    EXPECT_EQ(test_player_2 > test_player_3, true);

}
