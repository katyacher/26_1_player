#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>

class Track{
private:
    std::string name;
    std::tm duration; 
    std::tm* date;
  
public:
    Track(std::string name, std::tm duration);

    std::string get_name();
    void info();
};