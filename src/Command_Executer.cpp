
#include "Command_Executer.h"

Command_Executer::Command_Executer() {
    game_manager = new Game_Manager();
}

Command_Executer::~Command_Executer() {
    delete game_manager;
}

void Command_Executer::start() {

    int number_of_rounds;
    std::cin >> number_of_rounds;

    while(game_manager->get_current_round() < number_of_rounds) {

        int number_of_commands;
        std::string junk;
        std::cin >> junk >> number_of_commands;

        while(number_of_commands--) {

            std::string command;
            std::cin >> command;

            if (command == "ADD-USER") {
                std::string username, team, time;
                std::cin >> username >> team >> time;
                game_manager->add_user(username, team, time);
            }
            else if (command == "GET-MONEY") {
                std::string username, time;
                std::cin >> username >> time;
                game_manager->get_money(username, time);
            }
            else if (command == "GET-HEALTH") {
                std::string username, time;
                std::cin >> username >> time;
                game_manager->get_health(username, time);
            }
            else if (command == "TAP") {
                std::string attacker, attacked, weapon_type, time;
                std::cin >> attacker >> attacked >> weapon_type >> time;
                game_manager->tap(attacker, attacked, weapon_type, time);
            }
            else if (command == "BUY") {
                std::string username, weapon_name, time;
                std::cin >> username >> weapon_name >> time;
                game_manager->buy(username, weapon_name, time);
            }
            else if (command == "SCORE-BOARD") {
                std::string time;
                std::cin >> time;
                game_manager->score_board(time);
            }

        }

        game_manager->start_new_round();

    }

}