//
// Created by polej on 06.05.2023.
//

#ifndef FUNWITHOBJECT_CASE2_H
#define FUNWITHOBJECT_CASE2_H

#include <iostream>
#include "Rooms.h"
/*
 This case is really simply to understand. We have few functions, but it works only with created object room.
 We can call to methods in room. We are using two overload methods
 -room.display_rooms(); // this method display everything in map. All number room, information about guest(special code)
 or if room is empty "AVAILABLE".
 -room.display_rooms(floor);



 */
void case2(){
    std::cout << "1) Display all free rooms\n2) Display ground floor \n3)Display first floor \n4) Display third floor";
    std::string floor{};
    Rooms room;
    std::cin >> floor;
    if(floor == "1")
        room.display_rooms();
    else if(floor == "2" || floor == "3" || floor == "4")
        room.display_rooms(floor);
    else
        std::cout << "Incorrect choice, try again.";






}
#endif //FUNWITHOBJECT_CASE2_H
