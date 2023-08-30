
#include "GameManager.h"
#include <iostream>

#ifndef COMMANDEXECUTER_H
#define COMMANDEXECUTER_H

/**
 * @brief Read and excute commands from standard input
 * 
 */
class CommandExecuter {

public:

    /**
     * @brief Construct a new Command_Executer object
     * 
     */
    CommandExecuter();

    /**
     * @brief Start reading and executing commands
     * 
     */
    void start();

private:

    /**
     * @brief A GameManager object for executing commands
     * 
     */
    GameManager game_manager;

};

#endif