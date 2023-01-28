#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>

class Track{
private:
    std::string name;
    std::tm duration; 
    std::tm* date;
  
public:
    Track();
    Track(std::string name_, std::tm duration_tm);

    std::string get_name();
    //void set_name(std::string name_);
    //void set_duration(std::tm duration_tm);
    void info();
};