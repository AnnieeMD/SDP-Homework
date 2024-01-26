#include "Runner.hpp"

void Runner::run() {

    std::cout << "Welcome to our app!" << std::endl;

    Commands commands;
    std::string command, generalCommand;

    int counterOfCommands = 0;

    while(true) {

        // commands.toLower(command);

        std::cout << "Please enter a valid command or type \"help\" for more information." << std::endl;

        std::cout << ">";
        std::getline(std::cin, command);

        std::size_t nonSpace = command.find_first_not_of(" ");
        command.erase(0, nonSpace);

        std::size_t space = command.find(" ");

        generalCommand = command.substr(0, space);

        commands.toLower(generalCommand);

        bool firstCommands = generalCommand != "help" && generalCommand != "load";
        
        if (counterOfCommands == 0 && firstCommands) {
            
            throw std::invalid_argument("Please type help for more information or load a tree first!");
        }

        commands.process(command);

        std::cout << "------------------" << std::endl;

        // commands.toLower(generalCommand);

        if (generalCommand == "exit") {

            break;
        }
        
        counterOfCommands++;
    }
}