//
// Created by polej on 29.04.2023.
//

#ifndef FUNWITHOBJECT_ROOMS_H
#define FUNWITHOBJECT_ROOMS_H
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>


class Rooms {
private:
    std::map<int,std::string> guests_in_room;
public:
    Rooms();
    void display_rooms();
    void guest_registration(std::string name, int room_number);
    void registr_new_guest();

};


#endif //FUNWITHOBJECT_ROOMS_H
