
#include "CustomException.h"
#include "InsufficientMoneyException.h"
#include "FullTeamException.h"
#include "FriendlyFireException.h"
#include "DeadPlayerException.h"
#include "DeadBuyerException.h"
#include "DeadAttackerException.h"
#include "DeadAttackedException.h"
#include "InvalidAttributeException.h"
#include "InvalidUserNameException.h"
#include "InvalidGunTypeException.h"
#include "InvalidGunCategoryException.h"
#include "DuplicateAttributeException.h"
#include "DuplicateUserNameException.h"
#include "DuplicateWeaponTypeException.h"
#include "DuplicateHeavyGunException.h"
#include "DuplicatePistolException.h"
#include "OutOfTimeException.h"
#include "gtest/gtest.h"

TEST(Exceptions, Custom) {

    CustomException test_exception("exception");

    EXPECT_EQ(test_exception.what(), "exception");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, InsufficientMoney) {

    InsufficientMoneyException test_exception;

    EXPECT_EQ(test_exception.what(), "no enough money");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, FullTeam) {

    FullTeamException test_exception;

    EXPECT_EQ(test_exception.what(), "this team is full");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, FriendlyFire) {

    FriendlyFireException test_exception;

    EXPECT_EQ(test_exception.what(), "friendly fire");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, DeadPlayer) {

    DeadPlayerException test_exception("player is dead");

    EXPECT_EQ(test_exception.what(), "player is dead");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, DeadBuyer) {

    DeadBuyerException test_exception;

    EXPECT_EQ(test_exception.what(), "deads can not buy");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, DeadAttacker) {

    DeadAttackerException test_exception;

    EXPECT_EQ(test_exception.what(), "attacker is dead");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, DeadAttacked) {

    DeadAttackedException test_exception;

    EXPECT_EQ(test_exception.what(), "attacked is dead");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, InvalidAttribute) {

    InvalidAttributeException test_exception;

    EXPECT_EQ(test_exception.what(), "invalid attribute");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, InvalidUserName) {

    InvalidUserNameException test_exception;

    EXPECT_EQ(test_exception.what(), "invalid username");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, Invalid_GunType) {

    InvalidGunTypeException test_exception;

    EXPECT_EQ(test_exception.what(), "no such gun");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, InvalidGunCategory) {

    InvalidGunCategoryException test_exception;

    EXPECT_EQ(test_exception.what(), "invalid category gun");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, DuplicateAttribute) {

    DuplicateAttributeException test_exception;

    EXPECT_EQ(test_exception.what(), "duplicate attribute");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, DuplicateUserName) {

    DuplicateUserNameException test_exception;

    EXPECT_EQ(test_exception.what(), "you are already in this game");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, DuplicateWeaponType) {

    DuplicateWeaponTypeException test_exception;

    EXPECT_EQ(test_exception.what(), "duplicate weapon type");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, DuplicateHeavyGun) {

    DuplicateHeavyGunException test_exception;

    EXPECT_EQ(test_exception.what(), "you have a heavy");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, DuplicatePistol) {

    DuplicatePistolException test_exception;

    EXPECT_EQ(test_exception.what(), "you have a pistol");
    EXPECT_EQ(0, 0) << test_exception;

}

TEST(Exceptions, OutOfTime) {

    OutOfTimeException test_exception;

    EXPECT_EQ(test_exception.what(), "you are out of time");
    EXPECT_EQ(0, 0) << test_exception;

}
