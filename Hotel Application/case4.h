//
// Created by polej on 08.05.2023.
//

#ifndef FUNWITHOBJECT_CASE4_H
#define FUNWITHOBJECT_CASE4_H

#include <iostream>
#include "Rooms.h"
#include "Users.h"
#include "case3.h"

void case4(){
    std::string choice{};
    while(choice !="2") {
        std::cout << "1) Check out guest\n";
        std::cout <<"2) Back\n";
        std::cin >> choice;

        if(choice == "1") {
            int room_number{};
            std::cout << "Room number: ";
            std::cin >> room_number;
            int guest_code{};
            std::cout << "Guest code: ";
            std::cin >> guest_code;
            Rooms leave_room;
            Users check_out_guest;
            if (leave_room.return_guest_number_by_room(room_number) == guest_code) { // if guest in room == guest code, we can remove guest from Users map and Room map

                leave_room.check_out(room_number, guest_code);
                check_out_guest.delete_guest(guest_code);
        }

            else {
                std::cout << "Incorrect data.\n";
                case3();
            }


        }
        else if(choice=="2"){

        }
        else
            std::cout<<"Incorrect choice, try again\n";


    }
}
#endif //FUNWITHOBJECT_CASE4_H
