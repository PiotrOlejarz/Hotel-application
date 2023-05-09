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
    void display_rooms(); //overload function which is displaying all rooms, and all parametrs
    void display_rooms(std::string floor); //overload function which is display chose floor by user
    void guest_registration(std::string name, int room_number);
    void registr_new_guest(int room_number, int special_code);
    void check_out(int room_number, int special_code);
    bool check_room_free(int get_room_number); //function is checking does room is empty?
    int return_guest_number_by_room(int room_number); // function is returning guest number, before convert string to int
    bool protection_map(int key_map); //This function protects the map from going out of range

};


#endif //FUNWITHOBJECT_ROOMS_H
