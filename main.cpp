#include <iostream>
#include "player.h"

int main() {
    std::cout << "26.1 Player\n";

    Player* player = new Player();
    
    player->print();
    /*

    std::cout << "Ganarate the tracks in the player automaticaly? (y/n): ";
    std::string answer;
    
    while(answer != "y" || answer != "n"){
        std::cin >> answer;
        if(answer == "y"){
            player.autoInit();
        } else if(answer == "n"){
            std::cout << "Enter number of tracks in your player:" << std::endl;
            int number = 0;
            std::cin >> number;
            player.init(number);
        } else {
            std::cout << "Unknown command. Try again: ";
        }
    }
    */

    std::string command = "";

    while (command != "exit"){
        std::cout << "Enter the command (play/pause/stop/next/exit): ";
        std::cin >> command;
        if(command == "play"){
            std::cout << " Input track name: ";
            std::string name;
            std::cin >> name;
            if(player->has_track(name)){
                player->play(name);
            } else {
                std::cout << "Tere is no such track in the player. Try again." << std::endl;
            }
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
