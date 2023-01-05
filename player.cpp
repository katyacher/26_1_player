#include <iostream>
#include <cstdlib>
#include "player.h"

Player::Player(){
    tracks = {};
    for(int i = 0; i < 5; i++){
        std::string name = "Track" + std::to_string(i + 1);
        int duration = std::rand() % 10;
        addTrack(name, duration); 
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

        addTrack(name, duration); //the date creates automatically
    }
    current_track = tracks[0];
}


void Player::addTrack(std::string name, int duration){
    Track* track = new Track(name, duration);
    tracks.push_back(track);
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
    for(auto track: tracks){
        if(track->get_name() == name){
            current_track = track;
            if(!track->is_started()){
                track->started();
                track->info();
                std::cout << " is playing" << std::endl;
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
    for(auto it: tracks){
        delete it;
    }
}
