//
// Created by polej on 28.04.2023.
//



#include <iostream>



void display_menu();
void menu_switcher();
std::string get_guest_name(std::string name);
std::string get_guest_last_name(std::string last_name);
std::string get_personal_number(std::string is_personal_numb_correct);
std::string get_phone_number(std::string phone_number);
std::string get_address();
bool name_checker(std::string name_to_check);
bool personal_number_checker();
bool check_number_phone(std::string number_phone);
void case1();
std::string connect_address(std::string change_spaces); // function changing spaces to &
void case2();
void case3();
void display_guest_by_code(int guest_number);



