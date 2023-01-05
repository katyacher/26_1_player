#pragma once
#include <iostream>
#include <ctime>

class Track{
    std::string name_;
    int duration_; 
    std::tm* date_;
    bool start;
    bool pause;

public:
    Track(std::string name, int duration);

    std::string get_name();
    void info();
    void paused();
    void started();
    bool is_started();
    void stoped();
};