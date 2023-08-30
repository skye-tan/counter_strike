
#include "Timer.h"

Timer::Timer(const int input_minutes, const int input_seconds,
            const int input_milliseconds) :
            minutes(input_minutes), seconds(input_seconds), milliseconds(input_milliseconds) {}

bool Timer::operator <= (const Timer& timer) {
    if (minutes < timer.get_minutes()) {
        return true;
    }
    else if (minutes == timer.get_minutes() && seconds < timer.get_seconds()) {
        return true;
    }
    else if (minutes == timer.get_minutes() && seconds == timer.get_seconds() &&
                milliseconds < timer.get_milliseconds()) {
        return true;
    }
    else if (minutes == timer.get_minutes() && seconds == timer.get_seconds() &&
                milliseconds == timer.get_milliseconds()) {
        return true;
    }
    return false;
}

int Timer::get_minutes() const {
    return minutes;
}

int Timer::get_seconds() const {
    return seconds;
}

int Timer::get_milliseconds() const {
    return milliseconds;
}