//
// Created by polej on 28.04.2023.
//

#ifndef FUNWITHOBJECT_CHECKERS_H
#define FUNWITHOBJECT_CHECKERS_H
#include <iostream>
#include <limits>
#include <ctype.h>
bool name_checker(std::string  name_to_check){
    size_t meter{};
    for(char c: name_to_check) {
        if (std::isalpha(c))
            ++meter;
    }
    if(meter == name_to_check.size())
        return true;
    else
        return false;

}
bool personal_number_checker(std::string personal_number){
        if(personal_number.size() != 11)
            return false;
        else {
            int tab[] {1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1, 0};
            int suma {};
            std::string one_number_of_full{};
            for(int i {}; i <= 10; i++){
                int digit{};
                one_number_of_full = personal_number.at(i);
                digit = std::stoi(one_number_of_full);
                suma += digit*tab[i];

            }
            if(suma%10 ==0) {
                return true;
            }
            else
                return false;

        }

    }
    bool check_number_phone(std::string number_phone){
    int meter{};
    if(number_phone.size() > 20 && number_phone.size()>7)
        return false;
    else
        for(char c : number_phone) {
            if (std::isdigit(c))
                ++meter;
        }
        if(number_phone.size() == meter)
            return true;
        else
            return false;

}
int is_room_ok(){
    int room{};
    do {
        std::cin >> room;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid value. Try again: ";
            return 0;
        }
    }while(std::cin.fail());

        return room;

}
std::string connect_address(){
    std::string change_spaces{};

    std::getline(std::cin,  change_spaces);
    for(int i{0}; i<change_spaces.size(); i++){
        if(change_spaces[i] == ' ')
            change_spaces[i] = '&';
    }
    return change_spaces;
}

#endif //FUNWITHOBJECT_CHECKERS_H
