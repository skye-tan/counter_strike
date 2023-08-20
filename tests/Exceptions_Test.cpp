
#include "Custom_Exception.h"
#include "Insufficient_Money_Exception.h"
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
