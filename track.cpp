#include <iostream>
#include "track.h"

Track::Track(std::string name_, int duration_):name(name_), duration(duration_){
    std::time_t time  = std::time(nullptr);
    date = localtime(&time);

    start = false;
    pause = false;
}

std::string Track::get_name(){
    return name;
}

void Track::info(){
    std::cout << name << " (date: " << date->tm_mday << "." << date->tm_mon << "." << date->tm_year << ", ";
    std::cout << "duration: " << duration << ")"; 
}

void Track::paused(){
    if(!pause){
        pause = true;
        std::cout << "Track " << name << " on pause" << std::endl;
    }
}

void Track::started(){
    start = true;
}

void Track::stoped(){
    start = false;
}

bool Track::is_started(){
    return start;
}

bool Track::is_paused(){
    return pause;
}