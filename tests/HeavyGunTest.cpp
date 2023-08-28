
#include "HeavyGun.h"
#include "gtest/gtest.h"

TEST(HeavyGunClass, Getters) {

    HeavyGun test_heavy_gun("AK", 2700, 31, 100);

    EXPECT_EQ(test_heavy_gun.get_name(), "AK");
    EXPECT_EQ(test_heavy_gun.get_price(), 2700);
    EXPECT_EQ(test_heavy_gun.get_damage(), 31);
    EXPECT_EQ(test_heavy_gun.get_reward(), 100);

}
