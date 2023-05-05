//
// Created by polej on 28.04.2023.
//

#include <fstream>
#include "Users.h"
#include <fstream>
#include <sstream>


Users::Users(): people_in_group(){

    std::ifstream file("guestse.txt");
    if (file.is_open()) {

        int key;
        std::string value;
        while (file >> key) {
            std::vector<std::string> values;
            for (int i = 0; i < 8; i++) {
                file >> value;
                values.push_back(value);
            }
            people_in_group[key] = values;

        }
        this->people_in_group = people_in_group;
    }
    else {
        std::cerr << "Unable to open file!" << std::endl;
    }
    file.close();

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
int Users::get_special_code(int new_special_code){
    bool condition_special_code{false};
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
        file << std::endl;
        file << special_code << " "<<user_name<<" "<<user_last_name<< " "<<phone_number<<" "<<personal_id_number<<" "<<address<<std::endl;
    }
    file.close();

}
void Users::just_display(int key) {
    std::cout<<people_in_group[8635].size();
}
