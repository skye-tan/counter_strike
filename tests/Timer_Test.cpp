
#include "Timer.h"
#include "gtest/gtest.h"

TEST(Timer_Class, Getters) {

    Timer test_timer(2, 25, 178);

    EXPECT_EQ(test_timer.get_minutes(), 2);
    EXPECT_EQ(test_timer.get_seconds(), 25);
    EXPECT_EQ(test_timer.get_milliseconds(), 178);

}

TEST(Timer_Class, Operators) {

    Timer test_timer_1(2, 25, 178);
    Timer test_timer_2(1, 25, 178);

    EXPECT_EQ(test_timer_1 > test_timer_2, true);
    EXPECT_EQ(test_timer_1 > test_timer_1, false);
    EXPECT_EQ(test_timer_1 >= test_timer_1, true);

}
