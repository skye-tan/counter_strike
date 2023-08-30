
#include "Knife.h"
#include "gtest/gtest.h"

TEST(KnifeClass, Getters) {

    Knife* test_Knife = Knife::get_instance();

    EXPECT_EQ(test_Knife->get_name(), "Knife");
    EXPECT_EQ(test_Knife->get_price(), 0);
    EXPECT_EQ(test_Knife->get_damage(), 43);
    EXPECT_EQ(test_Knife->get_reward(), 500);

}
