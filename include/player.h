#pragma once
#include <iostream>
#include <vector>
#include "track.h"

class Player{
private:
    std::vector<Track> tracks;
    Track current_track;
    
    enum State{
        Stop,
        Play, 
        Pause
    };
    
    State current_state;

    bool contains(std::string name);
    
public: 
    Player();
    Player(int number);
    ~Player();
 
    void play();
    void pause();
    void next();
    void stop();
    void print();
};