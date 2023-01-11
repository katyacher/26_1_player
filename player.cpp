#include <iostream>
#include <cstdlib>
#include "player.h"

Player::Player(){
    tracks = {};
    std::vector<std::string> names {"Concert", "Symphony", "Opera", "Sonata", "Cantata"};
    for(int i = 0; i < 5; i++){
        std::string name = names[i];
        int duration = (rand() % 120) + 180;
        Track* track = new Track(name, duration); //the date creates automatically
        tracks.push_back(track); 
    }
    current_track = tracks[0];
}

Player::Player(int number){
    for(int i = 0; i < number; i++){
        std::string name;
        std::cout << "Enter the name of track: ";
        std::cin >> name;

        int duration = 0;
        std::cout << "Enter a duration of your track: ";
        std::cin >> duration;

        Track* track = new Track(name, duration); //the date creates automatically
        tracks.push_back(track); 
    }
    current_track = tracks[0];
}

bool Player::has_track(std::string name){
    for(auto track: tracks){
        if(track->get_name() == name){
            return true;
        }
    }
    return false;
}

void Player::print(){
    for(auto track: tracks){
        track->info();
    }
};

void Player::play(std::string name){
    if(current_track->is_paused()){
        current_track->started();
        current_track->info();
        std::cout << " continues to play" << std::endl;
    } else {
        for(auto track: tracks){
            if(track->get_name() == name){
                current_track->stoped();
                current_track = track;
                if(!track->is_started()){
                    track->started();
                    track->info();
                    std::cout << " starts to play" << std::endl;
                }
            }
        }
    }
}

void Player::pause(){
    current_track->paused();
}

void Player::next(){
    current_track = (tracks[std::rand() % tracks.size()]);
    play(current_track->get_name()); 
}

void Player::stop(){
    if(current_track->is_started()){
        current_track->stoped();
        std::cout << "Track " << current_track->get_name() << " is stoped." << std::endl;
    }
}
Player::~Player(){
    for(auto track: tracks){
        delete track;
    }
}
