#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "track.h"

class Player{
    std::vector<Track*> tracks;
    Track* current_track;
    bool is_playing;
    bool paused;
    
public: 
    Player();
    Player(int number);
    ~Player();

    bool contains(std::string name);
    void play();
    void pause();
    void next();
    void stop();
    void print();
};