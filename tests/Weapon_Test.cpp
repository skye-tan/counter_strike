#include "Weapon.h"
#include "gtest/gtest.h"

TEST(FirstTest, PartOne) {

    Weapon test_weapon("test", 270, 130);

    EXPECT_EQ(test_weapon.get_name(), "test");
    EXPECT_EQ(test_weapon.get_damage(), 270);
    EXPECT_EQ(test_weapon.get_reward(), 130);

}