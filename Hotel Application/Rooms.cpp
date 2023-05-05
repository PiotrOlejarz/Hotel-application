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

    for (int i{101}; i <= 116; i++) { // ROOMS 101-116
        std::cout << i << " " << guests_in_room[i]<<std::endl;

    }
    for (int i{201}; i <= 230; i++) { // ROOMS 201 - 230
        std::cout << i << " " << guests_in_room[i]<<std::endl;

    }
    for (int i{301}; i <= 330; i++) { // ROOMS 301 = 330
        std::cout << i << " " << guests_in_room[i]<<std::endl;
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
void Rooms::registr_new_guest(){
    std::ifstream input_file("guest_in_rooms.txt");
    std::ofstream output_file("new_guest_in_rooms.txt");

    if (input_file.is_open() && output_file.is_open()) {
        std::string line;
        while (std::getline(input_file, line)) {
            int key;
            std::string value;
            std::istringstream iss(line);
            iss >> key >> value;
            if (key == 109) {
                value = "Kasia";
            }
            output_file << key << " " << value << "\n";
        }
        input_file.close();
        output_file.close();
        // usunięcie pierwotnego pliku
        std::remove("guest_in_rooms.txt");
        // zmiana nazwy nowego pliku na pierwotną nazwę pliku
        std::rename("new_guest_in_rooms.txt", "guest_in_rooms.txt");
    }
    else {
        std::cerr << "Unable to open file(s)!" << std::endl;
    }

}