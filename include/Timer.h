
#ifndef TIMER_H
#define TIMER_H

/**
 * @brief Store a specified time in the game
 * 
 *   Stores the minutes, seconds and milliseconds of a specified
 * time in the game.
 * 
 */
class Timer {

public:

    /**
     * @brief Construct a new Timer object
     * 
     * @param input_minutes the minutes
     * @param input_seconds the seconds
     * @param input_milliseconds the milliseconds
     */
    Timer(const int input_minutes, const int input_seconds,
            const int input_milliseconds);

    /**
     * @brief Compares two Timer objects
     * 
     * @param timer the second Time object
     * @return true the second stored time is latter to this one or they are equal
     * @return false this stored time is after to the second one
     */
    bool operator <= (const Timer& timer);

    /**
     * @brief Get the minutes
     * 
     * @return int the minutes
     */
    int get_minutes() const;

    /**
     * @brief Get the seconds
     * 
     * @return int the seconds
     */
    int get_seconds() const;

    /**
     * @brief Get the milliseconds
     * 
     * @return int the milliseconds
     */
    int get_milliseconds() const;

private:

    /**
     * @brief The minutes of the stored time
     * 
     */
    int minutes;

    /**
     * @brief The seconds of the stored time
     * 
     */
    int seconds;

    /**
     * @brief The milliseconds of the stored time
     * 
     */
    int milliseconds;

};

#endif
