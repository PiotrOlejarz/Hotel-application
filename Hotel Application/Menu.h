//
// Created by polej on 28.04.2023.
//

#ifndef FUNWITHOBJECT_MENU_H
#define FUNWITHOBJECT_MENU_H


#include "FunctionsInMenu.h"
#include "Users.h"
#include <iostream>
#include <fstream>
void display_menu(){
std::cout << "1) Registr new guest\n";
std::cout << "2) Show all free rooms\n";
std::cout << "3) Find registred guest\n";
std::cout << "4) i dont know\n";
std::cout << "5) Exit\n";
}
void menu_switcher(){
    char choice{};
    display_menu();
    do {
        std::cin >> choice;
        switch (choice) {
            case '1': {

                std::string name{};
                std::string last_name{};
                std::string personal_number{};
                name =get_guest_name(name); //function in FunctionsInMenu loop is checking correct of data (only alpha signs), if wrong cin again
                last_name=get_guest_last_name(last_name); //function in FunctionsInMenu loop is checking correct of data (only alpha signs), if wrong cin again
                personal_number = get_personal_number(personal_number);//checking correct personal number
                Users new_guest; //creating new object which is adding to guests
                new_guest.get_personal_data(name, last_name, personal_number);//Users function, initialization data in object
                std::string phone_number{};
                std::string address{};
                phone_number = get_phone_number(phone_number);
                address = get_address(address);
                std::cout << address;
                new_guest.get_contact_details(phone_number, address);
                int special_code;
                new_guest.get_special_code(special_code);
                std::cout << special_code;
                new_guest.save_user_to_file();
                int xd{8635};
                new_guest.just_display(xd);







            }
            case '2': {


            }
        }
    }while(choice != '5');
}


#endif //FUNWITHOBJECT_MENU_H
