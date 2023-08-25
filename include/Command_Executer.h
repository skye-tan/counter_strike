
#include "Game_Manager.h"
#include <iostream>

#ifndef COMMAND_EXECUTER_H
#define COMMAND_EXECUTER_H

/**
 * @brief Read and excute commands from standard input
 * 
 */
class Command_Executer {

public:

    /**
     * @brief Construct a new Command_Executer object
     * 
     */
    Command_Executer();

    /**
     * @brief Start reading and executing commands
     * 
     */
    void start();

private:

    /**
     * @brief A pointer to a Game_Manager object for executing commands
     * 
     */
    Game_Manager* game_manager;

};

#endif