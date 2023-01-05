#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "track.h"

class Player{
    std::vector<Track*> tracks;
    Track* current_track;
    
public: 
    Player();
    Player(int number);
    ~Player();

    void addTrack(std::string name, int duration);
    bool has_track(std::string name);
    void print();
    void play(std::string name);
    void pause();
    void next();
    void stop();
};