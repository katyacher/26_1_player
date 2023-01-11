#include <iostream>
#include "player.h"

int main() {
    std::cout << "26.1 Player\n";

    Player* player = new Player();

    std::cout << "Ganarate the tracks in the player automaticaly? (y/n): ";
    std::string answer;
    
    while(answer != "y" || answer != "n"){
        std::cin >> answer;
        if(answer == "y"){
            std::cout << "Tracklist created automaticaly:" << std::endl;
            player->print();
            break;
        } else if(answer == "n"){
            std::cout << "Enter a number of tracks in your player:" << std::endl;
            int number = 0;
            std::cin >> number;
            Player* player = new Player(number);
            break;
        } else {
            std::cout << "Unknown command. Try again: ";
        }
    }
    
    std::string command = "";

    while (command != "exit"){
        std::cout << "Enter the command (play/pause/stop/next/exit): ";
        std::cin >> command;
        if(command == "play"){
            player->play();
        } else if(command == "pause"){
            player->pause();
        } else if (command == "next"){
            player->next();
        } else if(command == "stop"){
            player->stop();
        } 
    };
    return 0;
}
