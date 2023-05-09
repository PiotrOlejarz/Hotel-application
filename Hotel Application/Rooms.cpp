//
// Created by polej on 29.04.2023.
//

#include "Rooms.h"
#include <sstream>

//#include <fstream>
// constructor, 3 floors 1 floor -  15 rooms, 2 floor - 30 rooms, 3 floor - 30 rooms.
//String in map is waiting for guests names
Rooms::Rooms(){

    std::ifstream file("guest_in_rooms.txt");


    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            int key;
            std::string value;
            if (iss >> key >> value) {
                guests_in_room[key] = value;
            }
        }
    } else {
        std::cerr << "Unable to open file!" << std::endl;
    }
    file.close();

}
void Rooms::display_rooms(){
    short k{1};
    std::cout<<"Ground floor\n";
    for (int i{101}; i <= 116; i++) { // ROOMS 101-116
        std::cout << i << " " << guests_in_room[i]<<" ";
        if(k%5==0)
            std::cout<<std::endl;
        ++k;

    }
    std::cout <<"First floor\n";
    for (int i{201}; i <= 230; i++) { // ROOMS 201 - 230
        std::cout << i << " " << guests_in_room[i]<<" ";
        if(k%5==0)
            std::cout<<std::endl;
        ++k;

    }
    std::cout <<"Second floor\n";
    for (int i{301}; i <= 330; i++) { // ROOMS 301 = 330
        std::cout << i << " " << guests_in_room[i]<<" ";
        if(k%5==0)
            std::cout<<std::endl;
        ++k;
    }
}
void Rooms::display_rooms(std::string floor) {
    short k{1};
    if (floor == "2") {
        std::cout << "Displaying empty rooms on ground floor\n";
        for (int i{101}; i <= 116; i++) { // ROOMS 101-116
            if (guests_in_room[i] == "AVAILABLE")
                std::cout << i << " " << guests_in_room[i] << " ";
            if(k % 5 == 0)
                std::cout<<std::endl;
            ++k;
        }
    }
    else if (floor == "3") {
        short k{1};
        std::cout << "Displaying empty rooms on first floor\n";
        for (int i{201}; i <= 230; i++) { // ROOMS 201 - 230
            if (guests_in_room[i] == "AVAILABLE") {
                std::cout << i << " " << guests_in_room[i] << " ";
                if(k % 5 == 0)
                    std::cout<<std::endl;
                ++k;
            }

        }
    }
    else if (floor == "4") {
        std::cout << "Displaying empty rooms on second floor\n";
        for (int i{301}; i <= 330; i++) { // ROOMS 301 - 330
            if (guests_in_room[i] == "AVAILABLE") {
                std::cout << i << " " << guests_in_room[i] << " ";
                if (k % 5 == 0)
                    std::cout << std::endl;
                ++k;
            }

        }

    }
}
void Rooms::guest_registration(std::string name, int room_number) {


    guests_in_room[room_number] = name;
    std::ofstream outfile ("guest_in_rooms.txt", std::ios_base::app);
    if(outfile.is_open()) {
        for (int i{101}; i <= 116; i++) { // ROOMS 101-116
            outfile << i << " "<<guests_in_room[i]<<std::endl;

        }
        for (int i{201}; i <= 230; i++) { // ROOMS 201 - 230
            outfile << i << " "<<guests_in_room[i]<<std::endl;

        }
        for (int i{301}; i <= 330; i++) { // ROOMS 301 = 330
            outfile << i << " "<<guests_in_room[i]<<std::endl;
        }
    }

}
void Rooms::registr_new_guest(int room_number, int special_code){
    std::ifstream input_file("guest_in_rooms.txt");
    std::ofstream output_file("new_guest_in_rooms.txt");

    if (input_file.is_open() && output_file.is_open()) {
        std::string line;
        while (std::getline(input_file, line)) {
            int key;
            std::string value;
            std::string special_code_string;
            special_code_string = std::to_string(special_code);

            std::istringstream iss(line);
            iss >> key >> value;
            if (key == room_number) {
                if(value == "AVAILABLE")
                    value = special_code_string;
            }
            output_file << key << " " << value<< "\n";
        }
        input_file.close();
        output_file.close();
        std::remove("guest_in_rooms.txt");
        std::rename("new_guest_in_rooms.txt", "guest_in_rooms.txt");
    }
    else {
        std::cerr << "Unable to open file(s)!" << std::endl;
    }

}
void Rooms::check_out(int room_number, int special_code){
    std::ifstream input_file("guest_in_rooms.txt");
    std::ofstream output_file("new_guest_in_rooms.txt");

    if (input_file.is_open() && output_file.is_open()) {
        std::string line;
        while (std::getline(input_file, line)) {
            int key;
            std::string value;
            std::string special_code_string;
            special_code_string = std::to_string(special_code);

            std::istringstream iss(line);
            iss >> key >> value;
            if (key == room_number) {
                if(value == special_code_string)
                    value = "AVAILABLE";
            }
            output_file << key << " " << value<< "\n";
        }
        input_file.close();
        output_file.close();
        std::remove("guest_in_rooms.txt");
        std::rename("new_guest_in_rooms.txt", "guest_in_rooms.txt");
    }
    else {
        std::cerr << "Unable to open file(s)!" << std::endl;
    }

}
bool Rooms::check_room_free(int get_room_number){
    if(protection_map(get_room_number)) {
        if (guests_in_room[get_room_number] == "AVAILABLE")
            return false;
        else {
             //std::cout <<"This room is occupied! Try again";
             return true;
    }
}



} //function is checking does room is empty?
int Rooms::return_guest_number_by_room(int room_number) {

        if (protection_map(room_number)) {
            int convert_guest_code;
            if(check_room_free(room_number)) { //checking room status, if is empty return false.
                convert_guest_code = stoi(guests_in_room[room_number]);
                return convert_guest_code;
            }
        }
        else
            return 0;

}
bool Rooms::protection_map(int key_map){
    if(guests_in_room.count(key_map) > 0)
        return true;
    else
        return false;

}
