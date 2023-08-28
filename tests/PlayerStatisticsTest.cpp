
#include <iostream>
#include "PlayerStatistics.h"
#include "AllExceptions.h"
#include "gtest/gtest.h"

TEST(PlayerStatisticsClass, Getters) {

    PlayerStatistics test_statistics;

    EXPECT_EQ(test_statistics.get_kills(), 0);
    EXPECT_EQ(test_statistics.get_deaths(), 0);
    EXPECT_EQ(test_statistics.get_health(), 100);
    EXPECT_EQ(test_statistics.get_money(), 1000);
    EXPECT_EQ(test_statistics.has_enough_money(500), true);
    EXPECT_EQ(test_statistics.has_enough_money(1000), true);
    EXPECT_EQ(test_statistics.has_enough_money(1500), false);

}

TEST(PlayerStatisticsClass, DeathsAndKillsModification) {

    PlayerStatistics test_statistics;

    test_statistics.increment_kills();
    test_statistics.increment_kills();
    EXPECT_EQ(test_statistics.get_kills(), 2);

    test_statistics.increment_deaths();
    EXPECT_EQ(test_statistics.get_deaths(), 1);

}

TEST(PlayerStatisticsClass, HealthModification) {

    PlayerStatistics test_statistics;

    test_statistics.set_health_min();
    EXPECT_EQ(test_statistics.get_health(), 0);

    test_statistics.set_health_max();
    EXPECT_EQ(test_statistics.get_health(), 100);

    test_statistics.decrease_health(45);
    EXPECT_EQ(test_statistics.get_health(), 55);

    test_statistics.decrease_health(100);
    EXPECT_EQ(test_statistics.get_health(), 0);

}

TEST(PlayerStatisticsClass, MoneyModification) {

    PlayerStatistics test_statistics;

    test_statistics.increase_money(1000);
    EXPECT_EQ(test_statistics.has_enough_money(1500), true);
    EXPECT_EQ(test_statistics.has_enough_money(2000), true);
    EXPECT_EQ(test_statistics.has_enough_money(2500), false);

    test_statistics.decrease_money(500);
    EXPECT_EQ(test_statistics.has_enough_money(1000), true);
    EXPECT_EQ(test_statistics.has_enough_money(1500), true);
    EXPECT_EQ(test_statistics.has_enough_money(2000), false);

    try {
        test_statistics.decrease_money(2000);
    }
    catch (InsufficientMoneyException e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "no enough money");
    }

}

TEST(PlayerStatisticsClass, Operators) {

    PlayerStatistics test_statistics_1;
    PlayerStatistics test_statistics_2;

    test_statistics_1.increment_kills();
    EXPECT_EQ(test_statistics_1 > test_statistics_2, true);

    test_statistics_2.increment_kills();
    EXPECT_EQ(test_statistics_1 == test_statistics_2, true);

    test_statistics_2.increment_deaths();
    EXPECT_EQ(test_statistics_1 > test_statistics_2, true);

}
