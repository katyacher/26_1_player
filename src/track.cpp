#include <iostream>
#include "track.h"

Track::Track(){
    name = "Unknown";
    duration = {};
<<<<<<< HEAD
    std::time_t time = std::time(nullptr);
=======
    std::time_t time  = std::time(nullptr);
>>>>>>> 15b16a686eeaa1735f5560c8e886c4149927d70c
    date = localtime(&time);
}

Track::Track(std::string name_, std::tm duration_tm):name(name_), duration(duration_tm){
    std::time_t time  = std::time(nullptr);
    date = localtime(&time);
}

std::string Track::get_name(){
    return name;
}

void Track::info(){
    std::cout << "Track name: " << name << std::endl;
    std::cout << "Creation date: "  << std::asctime(date);
    std::cout << "Duration: " << std::put_time(&duration,"%M:%S") << std::endl;
}
