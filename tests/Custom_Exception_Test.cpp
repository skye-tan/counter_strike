
#include "Custom_Exception.h"
#include "gtest/gtest.h"

TEST(Custom_Exception_Class, Getters) {

    Custom_Exception test_exception("exception");

    EXPECT_EQ(test_exception.what(), "exception");
    EXPECT_EQ(0, 0) << test_exception;

}
