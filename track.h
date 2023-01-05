#pragma once
#include <iostream>
#include <ctime>

class Track{
private:
    std::string name;
    int duration; 
    std::tm* date;
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
    bool is_paused();
};