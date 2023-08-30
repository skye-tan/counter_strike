
#include <iostream>
#include "Player.h"
#include "AllExceptions.h"
#include "gtest/gtest.h"

TEST(PlayerClass, Basics) {

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

TEST(PlayerClass, BuyPistol) {

    Timer timer_1(1, 42, 123);

    Player test_player("player", 0, timer_1);
    Pistol pistol_1("pistol", 1000);
    Pistol pistol_2("pistol", 10000);

    try {
        test_player.can_buy(timer_1);
    }
    catch (DeadBuyerException e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "deads can not buy");
    }

    test_player.new_round(true);

    try {
        test_player.can_buy(timer_1);
    }
    catch (OutOfTimeException e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "you are out of time");
    }

    test_player.buy_pistol(pistol_1);

    try {
        test_player.buy_pistol(pistol_1);
    }
    catch (DuplicatePistolException e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "you have a pistol");
    }

}

TEST(PlayerClass, BuyHeavy) {

    Timer timer_1(1, 42, 123);

    Player test_player("player", 0, timer_1);
    HeavyGun heavy_1("heavy", 1000);
    HeavyGun heavy_2("heavy", 10000);


    try {
        test_player.can_buy(timer_1);
    }
    catch (DeadBuyerException e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "deads can not buy");
    }

    test_player.new_round(true);

    try {
        test_player.can_buy(timer_1);
    }
    catch (OutOfTimeException e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "you are out of time");
    }

    test_player.buy_heavy_gun(heavy_1);

    try {
        test_player.buy_heavy_gun(heavy_1);
    }
    catch (DuplicateHeavyGunException e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "you have a heavy");
    }

}

TEST(PlayerClass, AttackAction) {

    Timer timer(1, 42, 123);
    Player test_attacker("player", 0, timer);
    Player test_attacked("player", 0, timer);
    HeavyGun heavy("heavy", 1000);

    try {
        test_attacker.attack(test_attacked, "heavy", true);
    }
    catch (DeadAttackerException e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "attacker is dead");
    }

    test_attacker.new_round(false);

    try {
        test_attacker.attack(test_attacked, "heavy", true);
    }
    catch (DeadAttackedException e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "attacked is dead");
    }

    test_attacked.new_round(false);

    try {
        test_attacker.attack(test_attacked, "heavy", true);
    }
    catch (InvalidGunTypeException e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "no such gun");
    }

    test_attacker.buy_heavy_gun(heavy);

    try {
        test_attacker.attack(test_attacked, "heavy", true);
    }
    catch (FriendlyFireException e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "friendly fire");
    }

    test_attacker.attack(test_attacked, "heavy", false);

}

TEST(PlayerClass, Operators) {
    
    Timer timer_1(0, 2, 100);
    Timer timer_2(1, 42, 123);

    Player test_player_1("player", 0, timer_1);
    Player test_player_2("player", 1, timer_1);
    Player test_player_3("player", 1, timer_2);

    EXPECT_EQ(test_player_1 > test_player_2, true);
    EXPECT_EQ(test_player_1 > test_player_3, true);
    EXPECT_EQ(test_player_2 > test_player_3, true);

}
