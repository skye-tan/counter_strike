
#include "AllExceptions.h"
#include "WeaponBundle.h"
#include "gtest/gtest.h"

TEST(WeaponBundleClass, PistolAtrribute) {

    WeaponBundle test_bundle;
    Pistol test_pistol("Revolver", 600, 51, 150);

    try {
        test_bundle.get_pistol();
    }
    catch (InvalidGunTypeException e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "no such gun");
    }

    test_bundle.add_pistol(test_pistol);
    EXPECT_EQ(test_bundle.get_pistol()->get_name(), "Revolver");
    EXPECT_EQ(test_bundle.get_pistol()->get_price(), 600);
    EXPECT_EQ(test_bundle.get_pistol()->get_damage(), 51);
    EXPECT_EQ(test_bundle.get_pistol()->get_reward(), 150);

    try {
        test_bundle.add_pistol(test_pistol);
    }
    catch (DuplicatePistolException e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "you have a pistol");
    }
    
    test_bundle.remove_pistol();
    try {
        test_bundle.get_pistol();
    }
    catch (InvalidGunTypeException e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "no such gun");
    }

}

TEST(Weapon_Bundle_Class, HeavyGunAtrribute) {

    WeaponBundle test_bundle;
    HeavyGun test_heavy_gun("AK", 2700, 31, 100);

    try {
        test_bundle.get_heavy_gun();
    }
    catch (InvalidGunTypeException e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "no such gun");
    }

    test_bundle.add_heavy_gun(test_heavy_gun);
    EXPECT_EQ(test_bundle.get_heavy_gun()->get_name(), "AK");
    EXPECT_EQ(test_bundle.get_heavy_gun()->get_price(), 2700);
    EXPECT_EQ(test_bundle.get_heavy_gun()->get_damage(), 31);
    EXPECT_EQ(test_bundle.get_heavy_gun()->get_reward(), 100);

    try {
        test_bundle.add_heavy_gun(test_heavy_gun);
    }
    catch (DuplicateHeavyGunException e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "you have a heavy");
    }

    test_bundle.remove_heavy_gun();

        try {
        test_bundle.get_heavy_gun();
    }
    catch (InvalidGunTypeException e) {
        std::cout << e << std::endl;
        EXPECT_EQ(e.what(), "no such gun");
    }

}

TEST(WeaponBundleClass, KnifeAtrribute) {

    WeaponBundle test_bundle;

    EXPECT_EQ(test_bundle.get_knife()->get_name(), "Knife");
    EXPECT_EQ(test_bundle.get_knife()->get_damage(), 43);
    EXPECT_EQ(test_bundle.get_knife()->get_reward(), 500);

}
