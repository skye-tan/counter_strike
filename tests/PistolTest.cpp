
#include "Pistol.h"
#include "gtest/gtest.h"

TEST(PistolClass, Getters) {

    Pistol test_pistol("Revolver", 600, 51, 150);

    EXPECT_EQ(test_pistol.get_name(), "Revolver");
    EXPECT_EQ(test_pistol.get_price(), 600);
    EXPECT_EQ(test_pistol.get_damage(), 51);
    EXPECT_EQ(test_pistol.get_reward(), 150);

}
