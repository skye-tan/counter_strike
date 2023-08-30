
#include "Timer.h"
#include "gtest/gtest.h"

TEST(TimerClass, Getters) {

    Timer test_timer(2, 25, 178);

    EXPECT_EQ(test_timer.get_minutes(), 2);
    EXPECT_EQ(test_timer.get_seconds(), 25);
    EXPECT_EQ(test_timer.get_milliseconds(), 178);

}

TEST(TimerClass, Operators) {

    Timer test_timer_1(2, 25, 178);
    Timer test_timer_2(1, 25, 178);

    EXPECT_EQ(test_timer_2 <= test_timer_1, true);
    EXPECT_EQ(test_timer_1 <= test_timer_1, false);

}
