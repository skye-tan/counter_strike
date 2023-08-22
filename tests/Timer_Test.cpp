
#include "Timer.h"
#include "gtest/gtest.h"

TEST(Timer_Class, Getters) {

    Timer test_timer(2, 25, 178);

    EXPECT_EQ(test_timer.get_minutes(), 2);
    EXPECT_EQ(test_timer.get_seconds(), 25);
    EXPECT_EQ(test_timer.get_milliseconds(), 178);

}
