
#include "Heavy_Gun.h"
#include "gtest/gtest.h"

TEST(Heavy_Gun_Class, Getters) {

    Heavy_Gun test_heavy_gun("AK", 31, 100);

    EXPECT_EQ(test_heavy_gun.get_name(), "AK");
    EXPECT_EQ(test_heavy_gun.get_damage(), 31);
    EXPECT_EQ(test_heavy_gun.get_reward(), 100);

}
