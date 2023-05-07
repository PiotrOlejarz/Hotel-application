//
// Created by polej on 28.04.2023.
//

#ifndef FUNWITHOBJECT_USERS_H
#define FUNWITHOBJECT_USERS_H
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <time.h>

class Users {

private:
    std::map<int, std::vector<std::string>> people_in_group; // map to connect special user number and client data, this
    std::string user_name;                                  //special code is generating in method get_special_code()
    std::string user_last_name;
    std::string phone_number;
    std::string personal_id_number;
    std::string address;
    int special_code;


public:
    Users();

    void get_personal_data(std::string new_user_name, std::string new_user_last_name, std::string personal_id_number);

    void get_contact_details(std::string phone_number, std::string address);

    int get_special_code();
    void save_user_to_file();
    void just_display(int key, int &&value);

};


#endif //FUNWITHOBJECT_USERS_H
