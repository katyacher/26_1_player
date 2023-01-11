#include <iostream>
#include <cstdlib>
#include <ctime>
#include "player.h"

Player::Player(){
    tracks = {};
    std::vector<std::string> names {"Concert", "Symphony", "Opera", "Sonata", "Cantata"};

    for(int i = 0; i < 5; i++){
        std::string name = names[i];

        std::tm duration_tm{};
        duration_tm.tm_min = std::rand() % 10;
        duration_tm.tm_sec = std::rand() % 60;

        Track* track = new Track(name, duration_tm); //the date creates automatically
        tracks.push_back(track); 
    }

    current_track = tracks[0];
    is_playing = false;
    paused = false;
}

Player::Player(int number){
    for(int i = 0; i < number; i++){
        std::string name;
        std::cout << "Enter the name of track: ";
        std::cin >> name;

        std::tm duration_tm{};
        std::cout << "Enter a duration of your track (format 00:00): ";
        std::cin >> std::get_time(&duration_tm, "%M:%S");

        Track* track = new Track(name, duration_tm); //the date creates automatically
        tracks.push_back(track); 
    }
    current_track = tracks[0];
    is_playing = false;
    paused = false;
}

bool Player::contains(std::string name){
    for(auto track: tracks){
        if(track->get_name() == name){
            return true;
        }
    }
    return false;
}


void Player::play(){
    if(!is_playing && !paused){
        std::cout << "Choose a track from the following: " << std::endl;
        print();
        std::string name;
        std::cin >> name;
        if(!contains(name)) {
            std::cout << "There is no such track in the player." << std::endl;
        } else {
            for(auto track: tracks){
                if(track->get_name() == name){
                    current_track = track;
                    std::cout << current_track->get_name() << " plays. " << std::endl;
                    is_playing = true;
                }
            } 
        }   
    } else if(is_playing && paused) {
        std::cout << current_track->get_name() << " continues to play" << std::endl;
        paused = false;
    }
}

void Player::pause(){
    if(is_playing && !paused) {
        paused = true;
        std::cout << current_track->get_name() << " paused" << std::endl;
    }
}

void Player::next(){
    current_track = (tracks[std::rand() % tracks.size()]);
    is_playing = true;
    paused = false;
    std::cout << current_track->get_name() << " plays. " << std::endl;
}

void Player::stop(){
    if(is_playing){
        is_playing = false;
        paused = false;
        std::cout << current_track->get_name() << " is stoped." << std::endl;
    }
}

void Player::print(){
    for(auto track: tracks){
        std::cout << "----------------" << std::endl;
        track->info();
    }
};

Player::~Player(){
    for(auto track: tracks){
        delete track;
    }
}