#pragma once
#include <iostream>
#include <vector>
#include "track.h"

class Player{
private:
    std::vector<Track> tracks;
<<<<<<< HEAD
    Track* current_track;
    enum State{
        Stop,
        Play,
        Pause
    };

=======
    Track current_track;
    
    enum State{
        Stop,
        Play, 
        Pause
    };
    
>>>>>>> 15b16a686eeaa1735f5560c8e886c4149927d70c
    State current_state;

    bool contains(std::string name);
    
public: 
    Player();
    Player(int number);
    ~Player();
<<<<<<< HEAD

=======
 
>>>>>>> 15b16a686eeaa1735f5560c8e886c4149927d70c
    void play();
    void pause();
    void next();
    void stop();
    void print();
};