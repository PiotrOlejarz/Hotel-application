//
// Created by polej on 07.05.2023.
//

#ifndef FUNWITHOBJECT_CASE3_H
#define FUNWITHOBJECT_CASE3_H

#include <iostream>
#include "Users.h"
#include "Rooms.h"

void display_guest_by_code(int guest_code){
    Users display_guest;
    std::cout <<"Guest nr "<<guest_code<<std::endl;
    std::cout <<"Name: "; display_guest.just_display(guest_code, 0);
    std::cout <<" Last name: "; display_guest.just_display(guest_code, 1);
    std::cout <<" Phone number: "; display_guest.just_display(guest_code, 2);
    std::cout <<" Personal number: "; display_guest.just_display(guest_code, 3); std::cout<<std::endl;
    std::cout <<"Full address: "; display_guest.just_display(guest_code, 4); std::cout <<std::endl;


}
void case3() {

    std::string choice{};

    while (choice != "3") {
        std::cout << "Find guest and personal details\n1) By guest code\n2) By room number\n3) Back to menu\n";
        std::cin >> choice;
        if (choice == "1") {
            std::cout <<"Enter the guest number: ";
            int guest_number{};
            std::cin >> guest_number;
            display_guest_by_code(guest_number);


        } else if (choice == "2") {
            std::cout << "Enter room number: ";
            int room_number{};
            std::cin >>room_number;
            Rooms get_guest_number;
            if(get_guest_number.check_room_free(room_number)){
                display_guest_by_code(get_guest_number.return_guest_number_by_room(room_number));

            }
            else
                std::cout <<"This room is empty!"<<std::endl;


        } else
            std::cout << "Invalid choice. Try again\n";
    }
}

#endif //FUNWITHOBJECT_CASE3_H
