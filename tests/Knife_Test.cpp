
#include "Knife.h"
#include "gtest/gtest.h"

TEST(Knife_Class, Getters) {

    Knife test_Knife;

    EXPECT_EQ(test_Knife.get_name(), "Knife");
    EXPECT_EQ(test_Knife.get_damage(), 43);
    EXPECT_EQ(test_Knife.get_reward(), 500);

}
