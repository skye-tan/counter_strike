
#include "Custom_Exception.h"
#include "Insufficient_Money_Exception.h"
#include "Full_Team_Exception.h"
#include "Friendly_Fire_Exception.h"
#include "Dead_Player_Exception.h"
#include "Dead_Buyer_Exception.h"
#include "Dead_Attacker_Exception.h"
#include "Dead_Attacked_Exception.h"
#include "Invalid_Attribute_Exception.h"
#include "Invalid_UserName_Exception.h"
#include "Invalid_GunType_Exception.h"
#include "Invalid_GunCategory_Exception.h"
#include "Duplicate_Attribute_Exception.h"
#include "Duplicate_UserName_Exception.h"
#include "Duplicate_WeaponType_Exception.h"
#include "Duplicate_Heavy_Gun_Exception.h"
#include "Duplicate_Pistol_Exception.h"
#include "gtest/gtest.h"

TEST(Exceptions, Custom) {

    Custom_Exception test_exception("exception");

    EXPECT_EQ(test_exception.what(), "exception");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, Insufficient_Money) {

    Insufficient_Money_Exception test_exception;

    EXPECT_EQ(test_exception.what(), "no enough money");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, Full_Team) {

    Full_Team_Exception test_exception;

    EXPECT_EQ(test_exception.what(), "this team is full");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, Friendly_Fire) {

    Friendly_Fire_Exception test_exception;

    EXPECT_EQ(test_exception.what(), "friendly fire");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, Dead_Player) {

    Dead_Player_Exception test_exception("player is dead");

    EXPECT_EQ(test_exception.what(), "player is dead");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, Dead_Buyer) {

    Dead_Buyer_Exception test_exception;

    EXPECT_EQ(test_exception.what(), "deads can not buy");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, Dead_Attacker) {

    Dead_Attacker_Exception test_exception;

    EXPECT_EQ(test_exception.what(), "attacker is dead");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, Dead_Attacked) {

    Dead_Attacked_Exception test_exception;

    EXPECT_EQ(test_exception.what(), "attacked is dead");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, Invalid_Attribute) {

    Invalid_Attribute_Exception test_exception;

    EXPECT_EQ(test_exception.what(), "invalid attribute");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, Invalid_UserName) {

    Invalid_UserName_Exception test_exception;

    EXPECT_EQ(test_exception.what(), "invalid username");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, Invalid_GunType) {

    Invalid_GunType_Exception test_exception;

    EXPECT_EQ(test_exception.what(), "no such gun");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, Invalid_GunCategory) {

    Invalid_GunCategory_Exception test_exception;

    EXPECT_EQ(test_exception.what(), "invalid category gun");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, Duplicate_Attribute) {

    Duplicate_Attribute_Exception test_exception;

    EXPECT_EQ(test_exception.what(), "duplicate attribute");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, Duplicate_UserName) {

    Duplicate_UserName_Exception test_exception;

    EXPECT_EQ(test_exception.what(), "you are already in this game");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, Duplicate_WeaponType) {

    Duplicate_WeaponType_Exception test_exception;

    EXPECT_EQ(test_exception.what(), "duplicate weapon type");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, Duplicate_Heavy_Gun) {

    Duplicate_Heavy_Gun_Exception test_exception;

    EXPECT_EQ(test_exception.what(), "you have a heavy");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, Duplicate_Pistol) {

    Duplicate_Pistol_Exception test_exception;

    EXPECT_EQ(test_exception.what(), "you have a pistol");
    EXPECT_EQ(0, 0) << test_exception;

}
