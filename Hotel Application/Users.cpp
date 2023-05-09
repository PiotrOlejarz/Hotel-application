//
// Created by polej on 28.04.2023.
//

#include <fstream>
#include "Users.h"
#include <fstream>
#include <sstream>


Users::Users() {
    std::ifstream file("guestse.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            int code;
            std::vector<std::string> data(5);

            ss >> code;
            for (int i = 0; i < 5; i++) {
                ss >> data[i];
            }
            people_in_group[code] = data;
        }
        file.close();
    }
    else {
        std::cerr << "Error opening file." << std::endl;
    }
}


void Users::get_personal_data(std::string new_user_name, std::string new_user_last_name, std::string new_personal_id_number){
    user_name = new_user_name;
    user_last_name = new_user_last_name;
    personal_id_number = new_personal_id_number;
}
void Users::get_contact_details(std::string new_phone_number, std::string new_address){
    phone_number = new_phone_number;
    address = new_address;

}
int Users::get_special_code(){
    bool condition_special_code{false};
    int new_special_code{};
    do {


        srand(time(NULL));
        new_special_code = std::rand() % 9000 + 1000;
        special_code = new_special_code;
        std::string value_to_find = std::to_string(special_code);
        std::ifstream file("guestse.txt");
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string value_in_column;
            ss >> value_in_column;
            if (value_in_column == value_to_find)
                condition_special_code=true;



        }
        file.close();
    }while(condition_special_code);

    return special_code;
}
void Users::save_user_to_file(){
    std::ofstream file("guestse.txt", std::ios_base::app);
    if(!file.is_open()){
        std::cout << "File failed open ";

    }
    else{
        file << special_code << " "<<user_name<<" "<<user_last_name<< " "<<phone_number<<" "<<personal_id_number<<" "<<address<<std::endl;
    }
    file.close();

}
void Users::guest_in_past(){
    std::ofstream file("guests.txt", std::ios_base::app);
    if(!file.is_open()){
        std::cout << "File failed open ";

    }
    else{
        file <<personal_id_number<<" "<<user_name<<" "<<user_last_name<< " "<<phone_number<<" "<<address<<std::endl;
    }
    file.close();

}
void Users::just_display(int key, int &&value) {
    if(protection_map(key)){
        if (value != 4)
            std::cout << people_in_group[key].at(value);
        else {
            for (char c: people_in_group[key].at(value)) {
                if (c != '&')
                    std::cout << c;
                else
                    std::cout << ' ';

            }

        }
    }
}
bool Users::protection_map(int key_map){
    if(people_in_group.count(key_map) > 0)
        return true;
    else
        return false;

}
void Users::delete_guest(int guest_code) {
    std::string to_remove{std::to_string(guest_code)+" "};
    size_t i {0};

    for(auto data : people_in_group[guest_code]) {
        if(i < 4)
            data += " ";
        else
            data+="\n";

        to_remove += data;
        ++i;
    }
    std::string filename = "guestse.txt";
    std::ifstream fin(filename);
    std::ofstream fout(filename + ".temp");

    if (fin.is_open() && fout.is_open()) {
        std::string line;
        while (getline(fin, line)) {
            if (line.back() != '\n') {
                line += '\n';
            }
            if (line != to_remove) {
                fout << line;
            }
        }

        fin.close();
        fout.close();

        remove(filename.c_str());
        rename((filename + ".temp").c_str(), filename.c_str());
        std::cout <<"Guest removed from data base\n";
    } else {
        std::cout << "Failed to open file " << filename << std::endl;
    }

}
