//
// Created by polej on 28.04.2023.
//

#ifndef FUNWITHOBJECT_MENU_H
#define FUNWITHOBJECT_MENU_H


#include "FunctionsInCase1.h"
#include "Users.h"
#include "Rooms.h"
#include "Case1.h"
#include "Case2.h"
#include "case3.h"
#include <iostream>
#include <fstream>

void display_menu(){
std::cout << "1) Registr new guest\n";
std::cout << "2) Check rooms\n";
std::cout << "3) Find registred guest\n";
std::cout << "4) i dont know\n";
std::cout << "5) Exit\n";
}
void menu_switcher(){
    char choice{};

    do {
        display_menu();
        std::cin >> choice;
        switch (choice) {
            case '1': {

                case1();
                break;
            }
            case '2': {

                case2();
                break;
            }
            case '3':{
                case3();
                /*
                Users nowy_ziom;
                int xd{};
                int noxd{};
                std::cin >> xd;
                std::cin >> noxd;
                nowy_ziom.just_display(xd, noxd);
                 */

            }
        }
    }while(choice != '5');
}


#endif //FUNWITHOBJECT_MENU_H
